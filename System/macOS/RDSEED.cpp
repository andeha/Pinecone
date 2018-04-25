//
//  RDSEED.cpp
//  Pinecone
//

#include <x86intrin.h> 

//#define _rdseed64_step(x) ({ unsigned char err; asm volatile(".byte 0x48; .byte 0x0f; .byte 0xc7; .byte 0xf8; setc %1":"=a"(*x), "=qm"(err)); err; })

__attribute__((target("rdseed")))
int
RDSEED(
    uint64_t *x
)
{
    for (unsigned i = 0; i < 10; i++) { if (_rdseed64_step(x)) return 0; }
    return 1;
}
