//
//  RandomTests.cpp
//  Pinecone Unit Tests
//

#include <Pinecone.h>

UNITTEST(IntegerRandom_1)
{
    uint64_t x = 0;
    if (IntegerRandom(&x)) { ENSURE(false, "Error when calling IntegerRandom"); }
    ENSURE(x != 0, "Error when doing IntegerRandom. Not random.");
    Termlog << "Random number is 0x" << x << eol;
}
