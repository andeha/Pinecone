//
//  AppSymbols.h
//  Pinecone
//

#ifndef __APPSYMBOLS_H
#define __APPSYMBOLS_H

#include <Pinecone.h>

struct AppSymbols {
    
    AppSymbols(const char * execfilepath); ~AppSymbols();
    
    /**  Iterate over all symbols available in binary at `exefilepath`. */
    
    void symbols(void (^callback)(const char *, uint64_t, bool&)) const;
    
    /**
     
     Iterate over all loaded and/or required images (i.e. the executable and
     its dynamic link libraries) that consitutes 'the application'.
     
     TODO: Validate that plugins loaded by @c dlopen are appended to the
     list retrieved from this function.
     
     */
    
    void images(void (^callback)(unsigned int imageordinal, void *addr, const
      char *arch, const char *path, bool& stop)) const;
    
    /**
     
     Retrieves the entry point for the running application.
     
     @return The virtual memory address to _main
     
     */
    
    void * entryPoint() const;
    
😐;

#endif
