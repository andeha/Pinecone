//
//  PrintfTests.cpp
//  Pinecone Unit Tests
//

#include <Pinecone.h>

UNITTEST(Printf_1)
{
    printf("hello world");
}

UNITTEST(Printf_2)
{
    printf("hello world %d", 12);
}

UNITTEST(Printf_3)
{
    printf("hello world %x", 12);
}

UNITTEST(Printf_4)
{
    printf("hello world %b", 12);
}

UNITTEST(Printf_5)
{
    printf("hello %s\n", "world");
}

UNITTEST(Printf_6)
{
    String s = StringLiteral("world");
    printf("hello %S\n", *s);
}
