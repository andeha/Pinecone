//
//  AppSymbols.cpp
//  Pinecone
//

#include <System/macOS/AppSymbols.h>
#include <Additions/Helpers.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <mach-o/loader.h>
#include <mach-o/dyld.h>
#include <mach-o/arch.h>
#include <mach-o/nlist.h>
#include <sys/mman.h>
#include <sys/stat.h>

INNER_STRUCT AppSymbols::Implementation {
    
    Implementation(const char * execFilepath) { file = MemoryRegion::reflect(
      execFilepath); }
    
    ~Implementation() {}
    
    void
    loadCommands(
        unsigned int imageOrdinal,
        void (^callback)(mach_header_64 *mach_header_ptr, load_command *cmd,
            bool& stop)
    )
    {
        uint32_t count = _dyld_image_count();
        
        if (imageOrdinal < count) {
            
            mach_header_64 *mach_header_ptr = (mach_header_64 *)
                _dyld_get_image_header(imageOrdinal);
            
            uint8_t *p = (uint8_t *)mach_header_ptr + sizeof(mach_header_64);
            
            for (int i = 0; i < mach_header_ptr->ncmds; ++i) {
                
                load_command *command = (load_command *)p;
                
                bool stop = false;
                callback((mach_header_64 *)mach_header_ptr, command, stop);
                if (stop) break;
                
                p += command->cmdsize;
            }
        }
    }
    
    Optional<MemoryRegion> file;
    
    AppSymbols *outer;
    
};

#pragma - Outer Class

AppSymbols::AppSymbols(const char * execfilepath) : impl_ { new
  Implementation(execfilepath) } { impl_->outer = this; }

AppSymbols::~AppSymbols() { }

void AppSymbols::symbols(void (^callback)(const char *, uint64_t, bool&)) const
{
    if (MemoryRegion *region = impl_->file.query()) {
        
        char *obj = (char *)region->pointer(0).pointer;
        
        char *obj_p = (char *)obj;
        struct mach_header_64 *header = (struct mach_header_64 *)obj_p;
        obj_p += sizeof *header;
        struct section *sections = NULL;
        uint32_t nsects;
        
        __block bool outerStop = false;
        
        for (int i = 0; i < header->ncmds; ++i) {
            struct load_command *lc = (struct load_command *)obj_p;
            if (lc->cmd == LC_SYMTAB) {
                struct symtab_command *symtab = (struct symtab_command *)obj_p;
                obj_p += sizeof *symtab;
                struct nlist_64 *ns = (struct nlist_64 *)(obj + symtab->symoff);
                char *strtable = obj + symtab->stroff;
                for (int i = 0; i < symtab->nsyms; i++) {
                    struct nlist_64 *entry = ns + i;
                    uint32_t idx = entry->n_un.n_strx;
                    callback(strtable + idx, entry->n_value, outerStop);
                    if (outerStop) { return; }
                }
            } else if (lc->cmd == LC_SEGMENT) {
                struct segment_command *segment = (struct segment_command *)obj_p;
                obj_p += sizeof *segment;
                nsects = segment->nsects;
                sections = (struct section *)obj_p;
                obj_p += nsects * sizeof *sections;
            } else {
                obj_p += lc->cmdsize;
            }
        }
    }
}

void
AppSymbols::images(
    void (^callback)(unsigned, void *, const char *, const char *, bool&)
) const
{
    uint32_t count = _dyld_image_count();
    
    for (uint32_t i = 0; i < count; i++) {
        
        const char *imagepath = _dyld_get_image_name(i);
        
        const struct mach_header_64 *header =
            (const struct mach_header_64 *)_dyld_get_image_header(i);
        
        const NXArchInfo *info = NXGetArchInfoFromCpuType(
            header->cputype, header->cpusubtype);
        
        uint64_t address = (uint64_t)header;
        
        bool stop = false;
        
        callback(i, (void *)address, info->name, imagepath, stop);
        
        if (stop) break;
    }
}

void *
AppSymbols::entryPoint() const
{
    // Applications often rely on _dyld_get_image_header(0) being the main
    // executable so we find the main entry point by extracting out the LC_MAIN
    // in the first image.
    
    __block mach_vm_address_t result = NULL;
    
    impl_->loadCommands(0, ^(mach_header_64 *mach_header_ptr, load_command *cmd,
      bool& stop) { // ☜😐: 🕰?
        
        if (cmd->cmd == LC_MAIN) {
            
            entry_point_command *lc_entry_point_command = (struct entry_point_command *)cmd;
            
            // printf("\tentry offset\t= %llu\n", lc_entry_point_command->entryoff);
            
            uint64_t ptr = (uint64_t)mach_header_ptr;
            
            result = (mach_vm_address_t)(ptr + lc_entry_point_command->entryoff);
            
            stop = true;
        }
        
    });
    
    return (void *)result;
}
