//
//  Hypervisor.h
//  Pinecone Additions
//

#ifndef __HYPERVISOR_H
#define __HYPERVISOR_H

#include <Pinecone.h>
#include <Additions/Mathematics.h>

typedef enum Debuggable { DebuggableNo, DebuggableYes,
  DebuggableDedicatedCore0Only } Debuggable;

typedef void (^Progress)(uint64_t *outputOrToken, uint64_t bytes);
typedef String (^Input)(Oval val, Relative<double> pressure, bool isFirst,
  bool isLast, String surfaceIdent);

struct Hypervisor {
    
    /**
     
     Create a Virtual Machine Monitor (VMM) for an optionally debuggable
     upper-half or SGX-based kernel.
     
     */
    
    Hypervisor(
        unsigned int cpus,
        Debuggable debuggable,
        String (^sysinput)(String prompt, bool secure),
          void (^syslog)(const char *utf8, ...)
    );
    
    ~Hypervisor();
    
    enum class ErrorCode { unableToVirtualize, unableToStart };
    
    MACRO static void Error(ErrorCode code) BLURTS {
        switch (code) {
            case ErrorCode::unableToVirtualize:
                BLURT("Unable to virtualize");
            case ErrorCode::unableToStart:
                BLURT("Unable to start");
        }
        BLURT("General exception");
    }
    
#pragma mark Program Load and Execution
    
    void
    boot(
         const char * kernelpath, // utf8
         bool allowSelfsigned,
         Vector<Input> initialInputs,
         Vector<Progress> initialProgress
    ) const;
    
    void lock() const;
    
😐;

#endif
