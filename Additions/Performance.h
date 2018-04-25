//
//  Performance.h
//  Pinecone Additions
//

#ifndef __PERFORMANCE_H
#define __PERFORMANCE_H

#include <Pinecone.h>
#ifdef __x86_64__
#include <x86intrin.h>
#endif

/**
    
    ⏱😐🏁
    
    Macros measuring performance.  Note the nonexisting @c POOL_MEASURE macro
    closing bracket.
    
    @code
    MEASURE_START(myMeasure)
    ... // Code to be measured
    MEASURE_END(myMeasure)
    @endcode
    
    and
    
    @code
    int foo()
    {
        POOL_MEASURE(myMeasure)
        for (int i = 0; i < 1000; i++) { ... }
    }
    @endcode
    
 */

#define MEASURE_START(prefix) uint64_t prefix##Start = __rdtsc();
#define MEASURE_END(prefix)                                                   \
    uint64_t prefix##End = __rdtsc();                                         \
    uint64_t prefix##Nanos = prefix##End - prefix##Start;                     \
    Termlog << #prefix << " measures " << prefix##Nanos << " ns";

#define POOL_MEASURE(prefix)                                                  \
    MEASURE_START(prefix);                                                    \
    auto goodbye = make_exit_scope(^() { MEASURE_END(prefix); Termlog << ↩︎ });

#endif
