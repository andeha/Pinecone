//
//  Interleave.cpp
//  Pinecone Additions
//

#include <Additions/Interleave.h>
#ifdef __x86_64__
#include <immintrin.h>
#endif

#pragma mark BMI2 SW Equiv. for PEXT and PDEP

template<typename T>
T
pext(
    T val,
    T mask
)
{
    T res = 0;
    __builtin_uint_t off = 0;
    
    for (__builtin_uint_t bit = 0; bit != sizeof(T) * 8; ++bit) {
        
        const bool val_bit  =  (val >> bit) & 1;
        const bool mask_bit = (mask >> bit) & 1;
        
        if (mask_bit) {
            
            res |= static_cast<T>(val_bit) << off;
            
            ++off;
            
        }
    }
    
    return res;
}

template<typename T>
T
pdep(
    T val,
    T mask
)
{
    T res = 0;
    __builtin_uint_t off = 0;
    
    for (__builtin_uint_t bit = 0; bit != sizeof(T) * 8; ++bit) {
        
        const bool val_bit  =  (val >> off) & 1;
        const bool mask_bit = (mask >> bit) & 1;
        
        if (mask_bit) {
            
            res |= static_cast<T>(val_bit) << bit;
            
            ++off;
            
        }
    }
    
    return res;
}

#pragma mark - Interleave/Deinterleave

__attribute__((target("bmi2")))
void
Saw(
    uint32_t left,
    uint32_t right,
    uint64_t worm,
    uint64_t seed,
    bool hwAccelerated,
    uint64_t * result
)
{
    uint64_t l = (uint64_t)left;
    uint64_t r = (uint64_t)right;
    
    uint64_t leftMask  = seed ?  worm : !worm;
    uint64_t rightMask = seed ? !worm :  worm;
    
    uint64_t leftResult  = hwAccelerated ? _pdep_u64(l,  leftMask) :
        pdep(l,  leftMask);
    
    uint64_t rightResult = hwAccelerated ? _pdep_u64(r, rightMask) :
        pdep(r, rightMask);
    
    *result = leftResult ^ rightResult;
}

__attribute__((target("bmi2")))
void
Reap(
    uint64_t outcome,
    uint64_t worm,
    uint64_t seed,
    bool hwAccelerated,
    uint32_t * left,
    uint32_t * right
)
{
    uint64_t leftMask  = seed ?  worm : !worm;
    uint64_t rightMask = seed ? !worm :  worm;
    
    uint64_t l = hwAccelerated ? _pext_u64(outcome, leftMask)  :
        pext(outcome, leftMask);
    uint64_t r = hwAccelerated ? _pext_u64(outcome, rightMask) :
        pext(outcome, rightMask);
    
    *left   = (uint32_t)l;
    *right  = (uint32_t)r;
}
