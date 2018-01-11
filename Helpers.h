//
//  Helpers.h
//  Pinecone
//

#ifndef __HELPERS_H
#define __HELPERS_H

#include <PineconeLite/Pinecone.h>

#pragma mark Inceptives

/**
 
    Returns @c true if @c x is a power of two.  Inspect the binary
    representation, i.e if for some @c y, @c x can be written as @c 2^y.
 
    @param x  The value to investigate
 
    @return @c true if the value is a power of two, @c false otherwise
 
 */

 INLINED
 bool
 IsPowerOfTwo(
    __builtin_int_t x
 );

/**
 
    Return the smallest value larger than or equal to @c size that also is a
    multiple of @c framesize. E.g:
 
      framesize = 9
 
      '21' ⟿                    ↴     = 27
          |---------|---------|---------|---------|
           012345678 9      17 18     26 27     35
                                          ↳ '27' ⟿
 
    @param size  The value to increase or leave unchanged
 
    @param framesize  The size of the frame
 
    @return Multiple of @c framesize
 
 */

 INLINED
 __builtin_int_t
 Frame(
    __builtin_uint_t size,
    __builtin_uint_t framesize
 );

#pragma mark - Classics

/**
 
    Return the number of buckets sized @c width to contain @c index ∈ N.
    
       '7' ⟿
                |   |  |   | |   |  |   |  |   |
                 ---    ---   ---    ---    ---
                  0      1     2      3      4
                 012    345   678    901    234
 
    😐📖: 'How may sides has a dice if it did not have spots?'
 
 */

 FOCAL
 INLINED
 __builtin_int_t
 HowMany(
    __builtin_uint_t index,
    __builtin_uint_t width
 );

/**  Return half of an integer in an non-ambiguous way even for odd integers. */

 INLINED
 __builtin_int_t
 Half(
     __builtin_uint_t x
 );

/*
 
    Return @c true if @c a and @c b are similar according to @c 𝜀.
 
    😐📖: 'What is returned if a == b (i.e are equal)?'
 
 */

 FOCAL
 INLINED
 bool
 Similar(
    double a, double b, double 𝜀
 );

/**  Given a two dimensional grid, return stream index. */

 INLINED
 __builtin_int_t 
 IndexWhen2D(
	__builtin_uint_t row, 
	__builtin_uint_t column, 
	__builtin_uint_t cols
 );
	
/**  Return @c false if @c a and @c b differs with more than 𝜀. */

 INLINED bool BarelyReminiscent(__builtin_int_t a, __builtin_int_t b, 
 	__builtin_int_t 𝜀);
 
#pragma mark Expressives; Clear and Plain 
 
/**  Output integer in compliance with Mediterranean laws. */
      
 FOCAL int Roman(__builtin_int_t n, void (^ping)(char numeral));

/**  The textual representation of a signed integer. */

 void Int(__builtin_int_t n, void (^progress)(char digit));

/**   ⃨ and now with the IEEE754 base-2 floating point. */

 void Double(double x, uint8_t decimals, void (^progress)(char digit));

/**  Not more than 8 digits! */ 

 FOCAL void 
 Hex(__builtin_uint_t n, uint8_t digitsOrLetter, void (^touchbase)(char fourBits));

#endif
