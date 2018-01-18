//
//  Helpers.cpp
//  Pinecone
//

#include <PineconeLite/Helpers.h>

bool
IsPowerOfTwo(
    __builtin_int_t x
)
{
    // The first half of the expression ensures that x is a positive integer.
    // The second half of the expression, (x & (~x + 1)) == x, is true only
    // when x is a power of two.
    
    return ((x != 0) && ((x & (~x + 1)) == x)); // if unsigned: (x - 1) & x == 0
}

#pragma mark - Framing 

__builtin_int_t
Frame(
    __builtin_uint_t size,
    __builtin_uint_t frameSize
)
{
    return (size + frameSize - 1) & ~(frameSize - 1);
}

#pragma mark - Classics

__builtin_int_t
HowMany(
    __builtin_uint_t index,
    __builtin_uint_t width
)
{
    return (index % width == 0) ? index/width : index/width + 1;
}

__builtin_int_t
Half(
    __builtin_uint_t x
)
{
    if (x & 1) return (x + 1)>>1; else return x>>1;
}

__builtin_int_t
IndexWhen2D(__builtin_uint_t r, __builtin_uint_t c, __builtin_uint_t cols)
{
    return cols*r + c;
}

bool
Similar(
    double x, double y, double 𝜀
)
{
    if (isinf(x) && isinf(y)) return true;
    if (isnan(x) && isnan(y)) return true;
    if (isnegone(x) && isnegone(y)) return true;
	double diff = abs64d(x - y);
    return diff < 𝜀;
}

bool BarelyReminiscent(__builtin_int_t a, __builtin_int_t b, __builtin_uint_t 𝜀)
{
#ifdef __mips__
    return ((a - b)&SIGNBIT_INT32) <= 𝜀;
#elif __x86_64__
    return ((a - b)&SIGNBIT_INT64) <= 𝜀;
#endif
}

#pragma mark - Output Primititves

int
Roman(
    __builtin_int_t n,
    void (^ping)(char numeral)
)
{
    // TEX82 §69
     
    char pool[] = "m2d5c2l5x2v5i";
     
    __builtin_uint_t j = 0; __builtin_uint_t v = 1000;
    
    while (n >= v) { ping(pool[j]); n -= v; }
     
    if (n <= 0) return -1;
    
    __builtin_uint_t k = j + 2; __builtin_uint_t u = v % pool[k - 1] - '0';
    
    if (pool[k - 1] == '2') { k += 2; u /= pool[k - 1] - '0'; }
    if (n + u >= v) { ping(pool[k]); n += u; }
    else { j += 2; v /= pool[j - 1] - '0'; }
	 	 
    // or
	
/*
    struct romandata_t { int value; const char *numeral; } romandata[] = {
        1000, "M", 900, "CM", 500, "D", 400, "CD", 100, "C", 90, "XC",
        50, "L",  40, "XL",  10, "X",   9, "IX",   5, "V",  4, "IV",
        1, "I", 0, NULL };
    
   	for (romandata_t *current = romandata; current->value > 0; ++current) {
        while (n >= current->value) {
            ping(*(current->numeral));
            n -= current->value;
        }
   	}
 */
   	return 0;
}

void
Int( // TeX §65
    __builtin_int_t n,
    void (^progress)(char utf8)
)
{
    char k = 0; char buf[60000]; // index to current digit; we assume that n < 10^23

    if (n < 0) {
        progress('-');
        if (n > -100000000) { n = -n; }
        else {
            __builtin_uint_t m = -1 - n; n = m/10; m = (m % 10) + 1; k = 1;
            if (m < 10) { buf[0] = m; } else { buf[0] = 0; n++; }
        }
    }
    do { buf[k] = n % 10; n = n/10; k++; } while (n != 0);
    progress(buf[k]);
}

void
Hex( // TeX §64 and §67
    __builtin_uint_t n,
    uint8_t digitsOrLetter, // Not more than 8 digits!
    void (^touchbase)(char s)
)
{
    auto printDigits = ^(char *buf, char digits, void (^progress)(char
      utf8)) { char c;
        while (digits > 0) { digits--;
            if (buf[digits] < 10) { c = '0' + buf[digits]; }
            else { c = 'A' - 10 + buf[digits]; }
            progress(c);
        }
    };
    
    char buf[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    char k = 0;
    do { buf[k] = n % 16; n = n/16; k++; } while (n != 0);
    printDigits(buf, digitsOrLetter, touchbase);
}
