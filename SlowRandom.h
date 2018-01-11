//
//  SlowRandom.h
//  Pinecone
//

#ifndef __SLOWRANDOM_H
#define __SLOWRANDOM_H

#include <PineconeLite/Pinecone.h>

ENCLAVED
struct SlowRandom { // 😐🎲 See [Unittests]>--<SyncTests.cpp>{Synchronization_rendezvousbroadcast} for details.

    enum class Solution { RAND, SEED };

    SlowRandom(uint64_t *valueOptAlsoSeed, Solution s) FALLIBLE;

    SlowRandom(Vector<uint64_t> &values, Solution s) FALLIBLE;

    ~SlowRandom();
    
    INLINED void update() const BLURTS;
	
  	/**  Approximations for normally distributed random variates. */

    enum GaussianApproximate { AbramowitzStegun, ZogheibHlynka };
	
	/**
 
     To transformed into a normally distributed random variable:
    
     @code
     double notgaussian = value * stddev + mean
     @endcode
 
     */
    
    INLINED static double gaussian(GaussianApproximate ga);
	
	/**
 
     Return a uniformly distriuted random value ∈ [0-𝜀, 1+𝜀]. To lax the distri-
     bution to @c value ∈ [min, max], compute:
 
     @code
     double myuniform = value*(max - min) + min
     @endcode
 
     */

    INLINED static double uniform(); // value between 0 and 1

    enum class ErrorCode { unableToRAND, unableToSEED };
    
    MACRO static void Error(ErrorCode code) BLURTS {
        switch (code) {
            case ErrorCode::unableToRAND: BLURT("Unable to RAND");
            case ErrorCode::unableToSEED: BLURT("Unable to SEED");
        }
        BLURT("General exception");
    }

😐;
    
#define 🎲(sides) { uint64_t value, SlowRandom rnd(&value, SlowRandom::Solution::RAND), rnd.update(), value % sides; }

#endif
