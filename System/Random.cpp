//
//  Random.cpp
//  Pinecone
//

#include <Pinecone.h>

#ifdef __mips__

FOCAL
int
IntegerRandom(
    uint64_t *x
)
{
    static bool initialized = false;
    if (!initialized) {
        uint32_t seed = MIPSCycleCount();
        //   ⃨ (Initialize your random number generator)
        initialized = true;
    }
    //   ⃨ (Draw random number)
    return 0;
}

//   ⃨ (Details removed partially to simplify exposition.)

#elif defined __x86_64__

#include <immintrin.h>

FOCAL
__attribute__((target("rdrnd")))
int
IntegerRandom(
    uint64_t *x
)
{
    for (unsigned i = 0; i < 10; i++) { if (_rdrand64_step(x)) return 0; }
        return 1;
}

#endif
