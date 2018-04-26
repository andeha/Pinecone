//
//  BitTests.cpp
//  Pinecone Unit Tests
//

#include <Pinecone.h>

#define RCON 0xBF80F600 // Reset Control Register

BITMASK (uint32_t) { // RCON
    RCON_VREGS  = 0b1100000000, // Voltage Regulator Standby/Sleep Enable
    RCON_EXTR   = 0b0010000000, // External Reset (MCLR) Pin Flag
    RCON_SWR    = 0b0001000000, // Software Reset Flag
    RCON_WDTO   = 0b0000010000, // Watchdog Timer Time-out Flag
    RCON_SLEEP  = 0b0000001000, // Wake From Sleep Flag
    RCON_IDLE   = 0b0000000100, // Wake From Idle Flag
    RCON_BOR    = 0b0000000010, // Brown-out Reset Flag
    RCON_POR    = 0b0000000001  // Power-on Reset Flag
};

UNITTEST(Bittest_glassAndWrench)
{
    __builtin_uint_t rcon = 0xcafebabe;
    __builtin_uint_t val1 = 🔎((__builtin_uint_t)&rcon); // 🔎(RCON);
    🔧((__builtin_uint_t)&rcon) = ~val1;
    ENSURE(🔎((__builtin_uint_t)&rcon) == 0xffffffff35014541, "Bit retrieval/update (glass/wrench) failed");
}

UNITTEST(Bittest_shift)
{
    __builtin_uint_t rcon = 0xcafebabe;
    __builtin_uint_t val1 = 🔎MaskandShift((__builtin_uint_t)&rcon, RCON_VREGS);
    ENSURE(val1 == 0b10, "🔎MaskandShift failed");
    🔧((__builtin_uint_t)&rcon, RCON_VREGS, 0b01);
    ENSURE(🔎((__builtin_uint_t)&rcon) == 0x00000000cafeb9be, "Masked 🔧 failed");
}

UNITTEST(Bittest_toggle)
{
    __builtin_uint_t rcon = 0xcafebabe;
    🔧Toggle((__builtin_uint_t)&rcon, RCON_VREGS);
    ENSURE(🔎((__builtin_uint_t)&rcon) == 0x00000000cafeb9be, "🔧Toggle failed");
}
