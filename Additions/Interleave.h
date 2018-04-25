//
//  Interleave.h
//  Pinecone Additions
//

#ifndef __INTERLEAVE_H
#define __INTERLEAVE_H

#include <Pinecone.h>

/**
    
    Mix two 32-bits bit patterns according to worm and seed using Intel™ BMI2-
    specific instructions or a SW equivalent.
    
 */

INLINED
void
Saw(
    uint32_t left,
    uint32_t right,
    uint64_t worm,
    uint64_t seed,
    bool hwAccelerated,
    uint64_t *result
);

/**
    
    Entangles a 64-bit word created with @c Saw into two separate 32-bit words
    using Intel BMI2-specific instructions or a SW equivalent.
    
 */

INLINED
void
Reap(
    uint64_t value,
    uint64_t worm,
    uint64_t seed,
    bool hwAccelerated,
    uint32_t *left,
    uint32_t *right
);

#endif
