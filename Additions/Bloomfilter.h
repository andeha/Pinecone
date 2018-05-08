//
//  Bloomfilter.h
//  Pinecone Additions
//

#ifndef __BLOOMFILTER_H
#define __BLOOMFILTER_H

#include <Pinecone.h>

struct Bloomfilter {
    
    enum class Style { basic, counting };
    
    Bloomfilter(Style style);
    
    ~Bloomfilter();
    
    void insert(__builtin_uint_t value) const;
    
    bool possiblyContainsOrDefinitelyNotIn(__builtin_uint_t value) const;
    
    void invalidate(__builtin_uint_t value) const;
    
    enum class ErrorCode { supportsRemove };
    
    MACRO static void Error(ErrorCode code) BLURTS {
        switch (code) {
            case ErrorCode::supportsRemove:
                BLURT("Bloomfilter supports remove");
        }
        BLURT("General exception");
    }
    
😐;

#endif
