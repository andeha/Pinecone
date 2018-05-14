//
//  Utf8.cpp 
//  Pinecone
//

#include <Pinecone.h>

FOCAL
INLINED
__builtin_int_t
Utf8Followers(uint8_t leadOr8Bit)
{
    if (leadOr8Bit < 128) { return 0; }
    if (128 <= leadOr8Bit && leadOr8Bit < 192) return -1;
    if (248 <= leadOr8Bit) return -1;
#ifdef  __mips__
    auto clz = ^(uint8_t x) {
        INNER_DATA static constexpr uint8_t lookup[16] = { 4, 3, 2, 2, 1, 1, 1,
          1, 0, 0, 0, 0, 0, 0, 0, 0 };
        uint8_t upper = x >> 4, lower = x & 0x0F;
        return upper ? lookup[upper] : 4 + lookup[lower];
    };
    __builtin_int_t onesUntilZero = clz(~leadOr8Bit);
#elif defined __x86_64__
    __builtin_int_t onesUntilZero = __builtin_clzll(~((uint64_t)leadOr8Bit<<56));
#endif
    
    return onesUntilZero - 1;
}

FOCAL
INLINED
char32_t
Utf8ToUnicode(
    uint8_t *p,
    __builtin_int_t bytes
)
{
    switch (bytes) {
        case 1: return (char32_t)(uint8_t)*p;
        case 2: return (0b11111&*p) <<  6 | (0b111111&(*(p + 1)));
        case 3: return  (0b1111&*p) << 12 | (0b111111&(*(p + 1))) <<  6 | (0b111111&(*(p + 2)));
        case 4: return   (0b111&*p) << 18 | (0b111111&(*(p + 1))) << 12 | (0b111111&(*(p + 2))) << 6 | (0b111111&(*(p + 3)));
    }
    return 0;
}

FOCAL
int
TokenizeUtf8OrUnicode(
    Encoding encoding,
    MemoryRegion * region,
    __builtin_int_t& beam,
    void (^character)(char32_t unicode, __builtin_int_t byteOffset, bool& stop)
)
{
    __builtin_int_t bytes = region->bytes();
    __builtin_int_t i = beam;
    while (i < bytes) {
        SemanticPointer<void *> p = region->pointer(i);
        __builtin_int_t charBytes = 4;
        bool stop = false;
        if (encoding == Encoding::utf8) {
            uint8_t *c = (uint8_t *)p.pointer;
            charBytes = Utf8Followers(*(uint8_t *)c) + 1;
            if (charBytes == -1) return 1; // Not Utf-8?
            char32_t unicode = Utf8ToUnicode(c, charBytes);
            character(unicode, i, stop);
        } else { character(*(char32_t *)(p.pointer), i, stop); }
        i += charBytes;
        beam = i;
        if (stop) break;
    }
    return 0;
}
