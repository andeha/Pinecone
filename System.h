//
//  System.h
//  Pinecone
//

#ifndef __SYSTEM_H
#define __SYSTEM_H

namespace Naturals {
    constexpr auto π = 3.1415926535897932384626433832795028841971693993751058209749;
    constexpr auto e = 2.7182818284590452353602874713526624977572470936999595749669;
    constexpr auto φ = 1.6180339887498948482045868343656381177203091798057628621354;
}

#pragma mark Constants and Misc. Polar Hysteresis

 template <typename T> struct Interval { T closedBeginning; T openEnd; };
 
 #pragma mark Rectangular Coordinate Systems
 
 struct Cartesian3D { typedef double type; type x, y, z; };
 
 struct Rasterized2D { typedef __builtin_int_t type; type x, y; };
 
 struct Cartesian2D {
    
    typedef double type; type x, y;
    
    Cartesian2D(double x, double y) : x(x), y(y) {}
    
    Cartesian2D(const Cartesian2D &p) : x(p.x), y(p.y) {}
    
 };
 
 #pragma mark Non-Rectangular Coordinate Systems
 
 typedef struct Polar { typedef double type; type r, 𝜑; } Polar;
 
 typedef struct Spherical { typedef double type; type r, 𝛳, 𝜑; } Spherical;
 
 typedef struct Cylindrical { typedef double type; type h, 𝜑; } Cylindrical;
 
 enum Projection { Equirectangular, Cassini, Mercator };
 
 typedef struct EarthBasedSpatialTemporalLocation {
    double degrees, arcminutes, arcseconds;
 } EarthBasedSpatialTemporalLocation;
 
 typedef EarthBasedSpatialTemporalLocation DefaultSpatialTemporalLocation;
 
 /**  Angles continue in a clockwise direction, rather than counterclockwise. */
 
 typedef struct DeltaPolar { double theta, phi, t; } DeltaPolar;
 
 // #define EarthBasedSpatialTemporalHeading 360 == 0 degrees

namespace Naturals {
    constexpr auto degreesPerRadian = 57.296;
    constexpr auto π² = 9.86960440108935861883449099987615113531369940724079062641334; // 😐: ≅ 10
    constexpr auto π²div6 = 1.6449340668482264364724151666460251892189499012067984377; // 😐: ≅ ∑ 1/k², k ∈ [1 ⃨∞)
    // constexpr auto √5 = 2.23606797749978969640917366873127623544061835961152572427089; // 🕛: 𝜖 = 10³ @w N[Sqrt[5], 70]
    // constexpr auto πᵉ = 22.45915771836104547342715220454373502758931513399669224920;
    // constexpr auto φ² = 2.618033988749894848204586834365638117720309179805762862135; 😐: ≅ φ¹ + φ⁰
}

#pragma mark - Directions
 
 typedef __builtin_uint_t Positano; BITMASK(Positano) { // Movements on an approx. spherical surface while responding to 𝑜𝑛𝑒 gravitational field.
    PositanoUpLeftwards     = 0b00000001,
    PositanoLeftToRight     = 0b00000010,
    PositanoDownLeftwards   = 0b00000100,
    PositanoRightToLeft     = 0b00001000,
    PositanoDownRighttwards = 0b00010000,
    PositanoTopToBottom     = 0b00100000,
    PositanoUpRighttwards   = 0b01000000,
    PositanoBottomToTop     = 0b10000000 };
 
 typedef __builtin_uint_t Turtle; BITMASK(Turtle) {
    TurtleLeft        = 0b00000001,
    TurtleRight       = 0b00000010,
    TurtleForward     = 0b00000011,
    TurtleReverse     = 0b00000100,
    TurtleUp          = 0b00000101,
    TurtleDown        = 0b00000110,
    TurtleAccelerate  = 0b00001000,
    TurtleDeccelerate = 0b00010000 };
 
 typedef __builtin_uint_t Strider; BITMASK(Strider) { // ☜😐: 🔅
    StriderPort      = 0b00000001,
    StriderStarboard = 0b00000010,
    StriderForward   = 0b00000101,
    StriderAdrift    = 0b00000110,
    StriderAnchored  = 0b00000100 };
 
 typedef __builtin_uint_t RelationalStrider; BITMASK(RelationalStrider) {
    RelationalStriderAbaft         = 0b00000001,
    RelationalStriderLeeward       = 0b00000010,
    RelationalStriderAboard        = 0b00000011,
    RelationalStriderAthwartships  = 0b00000100,
    RelationalStriderBelowdecks    = 0b00000101,
    RelationalStriderAmidships     = 0b00000110,
    RelationalStriderOutboard      = 0b00000111,
    RelationalStriderAlee          = 0b000001000 };
 
 typedef __builtin_uint_t Manhattan; BITMASK(Manhattan) {
    ManhattanLeftToRight = 0b0001,
    ManhattanRightToLeft = 0b0010,
    ManhattanTopToBottom = 0b0100,
    ManhattanBottomToTop = 0b1000 };
 
 typedef __builtin_uint_t BinaryChoice; BITMASK(BinaryChoice) {
    BinaryChoiceToLeft  = 0b0, BinaryChoiceToRight = 0b1 };
 
#pragma mark - Algebraic Structures and Mathematical Artifacts

 template <typename T> struct Relative {
    static T arithmeticBetween(T x₁, T x₂) { return (x₁ + x₂) / 2; }
    // static T geometricBetween(T x₁, T acc) { return sqrt(x₁ * acc); } // See: Search ☜😐: ⌨️ MMXVII, XXX, ⅳ
    // static T harmonic1Between(T x₁, T acc) { return 1 / sqrt(x₁ * acc); } // See: Padé ☜😐: ⌨️ 🐚, 🐇,
    static Relative<T> leftChange(T x₁, T x₂) { return Relative<T> { (x₁ - x₂) / x₂ }; } // ∈ [0, 1]
    static Relative<T> rightChange(T x₁, T x₂) { return Relative<T> { (x₂ - x₁) / x₁ }; } // ∈ [0, 1]
    // Norm == Sequence<T>|AccumulativeSequence<T> S, AlgebraicCategory<T> C
    static T diff(T x₁, T x₂) { return x₁ - x₂; }
    static T dist(T x₁, T x₂, T (^N)(T x, T y)) { return N(x₁, x₂); }
    static T max(T x₁, T x₂) { return x₁ < x₂ ? x₂ : x₁; }
    static T min(T x₁, T x₂) { return x₂ < x₁ ? x₂ : x₁; }
    static bool eqrel(T x₁, T x₂) { return !(x₁ < x₂ || x₂ < x₁); };
    static bool eqeql(T x₁, T x₂) { return x₁ == x₂; };
    T value; };

#pragma mark - Endianess, 128/256-bits Computers, IEEE 754-2008 and 𝒕𝒉𝒆 𝒉𝒂𝑙𝑓
 
 typedef union {
    double base2; // 2^–1022  2^1023 or 2.23 × 10^–308 to 1.79 × 10^308
    struct { uint32_t lst; int32_t mst; } little_endian;
    struct { int32_t mst; uint32_t lst; } big_endian;
    struct { uint32_t lst; uint32_t mst; } unsigned_little_endian;
    struct { uint32_t mst; uint32_t lst; } unsigned_big_endian;
    struct {
        unsigned mantissal : 32;
        unsigned mantissah : 20;
        unsigned exponent  : 11;
        unsigned sign      :  1;
    } ieee754;
#ifdef __x86_64__
    uint64_t octa;
#endif
 } octa;
 
#ifdef __mips__
    typedef octa uint64_t;
#endif
 
#ifdef __x86_64__
#include <xmmintrin.h>  // ≥ SSE 4.2
#include <immintrin.h>  // AVX and AVX2 from avxintrin.h and avx2intrin.h
#endif
 
 typedef union {
#ifdef __x86_64__
    __m128 sexdeca;
    __m128i twoOcta;
    __m128d twoDoubles;
#endif
    struct { int64_t lso; uint64_t mso; } little_endian;
    struct { int64_t mso; uint64_t lso; } big_endian;
    struct { uint64_t lso; uint64_t mso; } unsigned_little_endian;
    struct { uint64_t mso; uint64_t lso; } unsigned_big_endian;
 } sexdeca;
 
 typedef union {
#ifdef __x86_64__
    __m256 fourOcta;
#endif
    struct { sexdeca lss; sexdeca mss; } little_endian;
    struct { sexdeca mss; sexdeca lss; } big_endian;
 } hentriaconta;
 
 typedef union {
    float base2; // 2^–126 to 2^127 or 1.18 × 10^–38 to 3.40 × 10^38
    struct { int16_t lsh; uint16_t msh; } little_endian;
    struct { int16_t msh; uint16_t lsh; } big_endian;
    struct {
        unsigned mantissa : 23;
        unsigned exponent :  8;
        unsigned sign     :  1;
    } ieee754;
    uint32_t tetra;
 } tetra;
 
 typedef union { // 2^–14 to 2^15 or 3.1 × 10^–5 to 6.50 × 10^4
    // binary16 base2
    struct { int8_t lsh; uint8_t msh; } little_endian;
    struct { uint8_t msh; int8_t lsh; } big_endian;
    struct {
        unsigned mantissa : 10;
        unsigned exponent :  5;
        unsigned sign     :  1;
    } ieee754;
    uint16_t half;
 } half;
 
#pragma mark - Math

 #define SIGNBIT_INT64  0x8000000000000000L
 #define SIGNBIT_INT32  0x80000000
 
 #define abs64i(x) int64_t(((uint64_t)(x) & ~SIGNBIT_INT64))
 #define abs32i(x) int32_t(((uint32_t)(x) & ~SIGNBIT_INT32))
 
 #define IEEE754BASE2_64BIT_SNAN   0x7ff0000000000001L
 #define IEEE754BASE2_64BIT_QNAN   0x7ff8000000000000L
 #define IEEE754BASE2_64BIT_PINF   0x7ff0000000000000L
 #define IEEE754BASE2_64BIT_NINF   0xfff0000000000000L
 #define IEEE754BASE2_32BIT_QNAN   0x7FC00000
 
 MACRO float abs32s(float x) { tetra t; t.base2 = x; t.ieee754.sign = 0; return t.base2; }
 MACRO double abs64d(double x) { octa o; o.base2 = x; o.ieee754.sign = 0; return o.base2; }
 
 template <typename T> MACRO T abs(T x) { return x < 0 ? -x : x; }
 
 MACRO bool isinf(double x) {
    octa o; o.base2 = x;
    return o.ieee754.exponent == 0x7ff || o.ieee754.exponent == 0xfff; }
 
 MACRO bool isnan(double x) {
    octa o; o.base2 = x;
    return (o.ieee754.mantissah != 0 || o.ieee754.mantissal != 0) &&
    o.ieee754.exponent == 0x7ff; }

 MACRO bool isnegone(double x) {
    octa o; o.base2 = x;
    return o.little_endian.lst == -1 && o.little_endian.mst == -1; }
 
 /**
 
  Breaks value into integral and fractional parts, each of which has the
  same sign as the argument.  They return the fractional part, and store
  the integral part (as a floating-point number) in the object pointed to
  by iptr.
 
  */
 
 extern "C" INLINED double modf(double x, double *iptr);
 
 /**  Compute eˣ, the base-e exponential of x. */
 
 extern "C" INLINED double exp(double x);
 
 /**  Compute the exponent of @c x as in @c ln x. */
 
 extern "C" INLINED double ln(double x);
 
 /**  Compute x raised to the power y. */
 
 extern "C" INLINED double pow(double x, double y) WOBBLING DO_NOT_USE; // 😐📖: a*x^2 +b*x^3 == x*x*(a + b*x) ∧ 0^0 == 0^-0 == 1/0^0.
 
/**  Compute the non-negative square root of @c x. */
 
 extern "C" INLINED double sqrt(double x); // An exception is thrown when x < 0
 
/**  Compute reciprocal square root of @c x. */
 
 extern "C" INLINED float rsqrt(float x);
 
/**  Axiomatization */
 
 /** AX_: */ extern "C" INLINED double arctan(double x);
 
 /** AX_: */ FOCAL extern "C" INLINED void sincos(double x, double *s, double *c);
 
 /** AX_: */ FOCAL extern "C" INLINED double pinecone_floor(double x);
 
#pragma mark - Integer to String and Radix Conversion

 void Base(__builtin_uint_t z, unsigned base, unsigned numeralsOrZero, void (^progress)(char c));

 void Base(__builtin_int_t n, unsigned base, unsigned numeralsOrZero, void (^progress)(char c));

#pragma mark - Integer Randoms

 /**
 
 Return a random 64-bit value. (See '128-bit PRNG'.) May very well be
 NIST SP 800-90A compliant.
 
  */

 int IntegerRandom(uint64_t *x);

#pragma mark - More Maths Required

template <typename T>
struct AlgebraicCategory {
    virtual T zero() const = 0;
    virtual T half() const = 0;
    virtual T one() const = 0;
    virtual T sqrt3div2() const = 0;
    virtual T onedivsqrt2() const = 0;
    virtual T epsilon() const = 0;
    // virtual T NaN() const = 0;
    // virtual T quietNaN() const = 0;
    virtual T pow(T x, T y, T env) const = 0;
    virtual T sin(T x) const = 0;
    virtual T cos(T x) const = 0;
    virtual T arctan(T x) const = 0;
    virtual __builtin_int_t floor(T x) const = 0;
    virtual T e(uint64_t fractDigit) const = 0;
    virtual T pi(uint64_t fractDigit) const = 0; // 😐: √5?
};

#pragma mark - The Parade
 
 template <typename T> struct Sequence {
    virtual __builtin_int_t count() const = 0;
    virtual int dereference(__builtin_int_t idx, void (^touchbase)(T *p)) const = 0;
    MACRO int forall(void (^block)(T *p, bool first, bool last,
          __builtin_int_t idx, bool& stop)) { // TODO: _∀(void ...)
        __builtin_int_t itemCount = count();
        __builtin_int_t idx = 0;
    again:
        if (idx < itemCount) {
            __block bool innerStop;
            if (dereference(idx, ^(T *elem) {
                block(elem, idx == 0, idx == itemCount - 1, idx, innerStop);
            }))
            {
                return -2;
            }
            if (innerStop) { return -1; }
            idx++;
            goto again;
        }
        return 0;
    }
 };
 
 template <typename T, typename C = Sequence<T>> struct Mitigate : public Sequence<T> {
    FINAL virtual C clone(void *(^allocate)(__builtin_int_t bytes)) const = 0;
    FINAL virtual Tuple<C, C> attach(__builtin_int_t index) const = 0;
    FINAL virtual Tuple<C, C> detach(__builtin_int_t index, void *(^allocate)(__builtin_int_t bytes)) const = 0;
 };
 
 template <typename T>
 struct SelectiveSequence : public Sequence<T> { // 😐:  🚢 🚙 ⛵️ 🚤   ⟶  ⛵️
    T * select(T *now, SelectiveSequence<T> &backlog) const = 0; };
 
 template <typename T>
 struct AccumulativeSequence : public Sequence<T> { // 😐: ∑ ∏
    void select(void (^map)(T &elem, bool first, bool last, bool& stop))
    const { return forall(map);}};
 
 /*  𝘒𝘌𝘌𝘗 things in order, but not too much. */
 
 template <typename T>
 struct SortedSequence : public Sequence<T> {
    virtual T *first() const = 0;
    virtual T *middle() const = 0;
    virtual T *last() const = 0;
 };
 
 enum class Endianness { Native, Network };

// extern ENCRYPTED "Utf-8✕json" struct "myTuple" Pair { int a; int b; } foo() { return { 0, 0 }; }
 
 #define kNullFossilate Fossilate { NULL, 1, NULL, Tuple<__builtin_uint_t, __builtin_uint_t>(0, NULL) }
 
 /* ONETIMEPAD */ typedef struct Fossilate /* public : base */ {
    /* DISJUNCT */ union Value {
        // ...Interesting. FINAL below often                        ☜😐🔅¹
        Tuple<__builtin_int_t, char32_t *> machineString; // ⬷ Not stored in SI™
        char *eightbitCString;
        __builtin_uint_t bitmap;
        double real;
        typedef struct Reference {
            void *p;
            Tuple<__builtin_uint_t, char32_t *> canonizedTypename;
        } Reference;
        Value() { }
    } value;
    __builtin_uint_t kind; // ∈ [0, ⃨,k-1]
    Fossilate *optUnit;
    Optional<Tuple<__builtin_uint_t, char32_t *>> optUnitNameOrIdent;
    // ↸ But not neccessarily FINAL here...                         ☜😐🔅²
    Fossilate() { optUnitNameOrIdent = Optional<Tuple<uint64_t, char32_t *>>::no(); }
 } Fossilate /* == {
    Content {
    machineString,
    eightbitCString,
    base,
    bitmap,
    value,
    {
        canonizedTypename,
        p
    },
    kind,
    optUnit,
    nameOrIdent,
    this } */ ; // ⬷ ⚠️ Struct 'Fossilate' did recently contain a 'this' pointer but now contains an ⚱️. Optional signature, i.e. SHA1 last 64 bits, an xor with a key and then xor back has not yet been computed.
 
// 💀🎤😐: 🎲⤣ ≅

#pragma mark - The String
 
FINAL struct String /* : public Mitigate<char32_t, String> */ {
    
    /**
     
     Given a traditional C-language character sequence, create an 'owning'
     a.k.a non-copied @c String instance.
     
     */
    
    INLINED static String Literal(const char *utf8, ...);
    
    /**
     
     As StringLiteral, but can be altered with UnicodeAppend, UnicodeDelete,
     UnicodeReplace.
     
     */
    
    INLINED static String FluctuantLiteral(const char *utf8, ...);
    
    /**
     
     Encapsulate, i.e create an owning, non-copied @c String instance.
     
     */
    
    INLINED
    static
    String
    Literal( // For one block of unicodes
        Endianness endianness,
        const char32_t *unicodes,
        __builtin_int_t count,
        bool readonly = true
        // bool moveInsteadOfCopy = false // Rename this function to Frame and Duplicate or remove since we have a clone().
        // void *(^allocate)(__builtin_int_t bytes) = ^(__builtin_int_t bytes) { return malloc(bytes); }
    );
    
    /**
     
     Until the grapheme located before @maxBytes, create a truncated @c String.
     
     */
    
    INLINED
    static
    String
    SecureLiteral(
        const char *utf8,
        __builtin_int_t maxBytes,
        bool readonly,
        __builtin_va_list arg
    );
    
#pragma mark Sequence
    
    /**  Return the number of unicodes. Runs in O(1). */
    
    INLINED __builtin_int_t count() const;
    
    /**  Return a single Unicode if one exists. */
    
    INLINED
    int
    dereference(
        __builtin_int_t unicodeIndex,
        void (^touchbase)(char32_t unicode)
    ) const;
    
#pragma mark API for Connoisseur Development 🎁😐🎂
    
    int incorporate(__builtin_int_t index, String substringToBeCloned,
      void *(^allocate)(__builtin_int_t bytes) = ^(__builtin_int_t bytes) {
      return malloc(bytes); } );
    
    int takeover(__builtin_int_t index, String stringToBeFramed);
    
    int exclude(__builtin_int_t start, __builtin_int_t unicodes);
    
#pragma mark Conveniences
    
    static Optional<String> merge(String head, String tail, void *
      (^allocate)(__builtin_int_t bytes) = ^(__builtin_int_t bytes) { return
      malloc(bytes); } );
    
    Optional<String> clone(void *(^allocate)(__builtin_int_t bytes) =
      ^(__builtin_int_t bytes) { return malloc(bytes); } );
    
    int append(MemoryRegion unicodeSuffix, void *(^allocate)(__builtin_int_t
      bytes) = ^(__builtin_int_t bytes) { return malloc(bytes); } );
    
    int append(const char * utf8, __builtin_int_t maxByteCount, void *(^allocate
      )(__builtin_int_t bytes)  = ^(__builtin_int_t bytes) { return malloc(
      bytes); } );
    
    // MAY_CONTAIN_TRACES_OF_SOFT_REALTIME String& operator=(const char *utf8) {
    //  __builtin_int_t unicodes = count(); exclude(0, unicodes);
    //  append(utf8, -1, ^(__builtin_int_t bytes) { return malloc(bytes); });
    //  return *this;
    // }
    
#pragma mark Mitigate
    
    INLINED Tuple<String, String> attach(__builtin_int_t unicodeIndex);
    INLINED Tuple<String, String> branch(__builtin_int_t unicodeIndex, void *(^
      allocate)(__builtin_int_t bytes) = ^(__builtin_int_t bytes) { return
      malloc(bytes); } );
    
#pragma mark Errors
    
    enum class ErrorCode { lengthUnknown };
    
    MACRO static void Error(ErrorCode code) BLURTS {
        switch (code) {
            case ErrorCode::lengthUnknown: BLURT("String length unknown");
        }
        BLURT("General exception");
    }
    
#pragma mark Misc
    
    INLINED bool empty() const;
    
    INLINED bool isMutable() const;
    
    /**
     
     If dirty, lazily (re)create utf-8 representation that can be freed with
     @c free(myString.utf8Buf_)
     
     */
    
    MemoryRegion * utf8(); // O(n)
    
    /**  Access underlying Unicode string. */
    
    MemoryRegion * operator*(); // O(1)
    
    /**  Return the empty string. */
    
    static String epsilon(bool readonly = true);
    
private:
    
    // ~String() {} // { free(buf, bytes); }
    
    String(MemoryRegion unicodes, bool readonly, bool moveInsteadOfCopy);
    
    String(
        __builtin_int_t utf8Bytes, uint8_t *utf8Buf,
        __builtin_int_t unicodeBytes, char32_t *unicodeBuf,
        bool readonly, bool moveInsteadOfCopy
    );
    
😐;

#define StringLiteral String::Literal
#define FluctuantLiteral String::FluctuantLiteral
#define SecureLiteral String::SecureLiteral

#pragma mark - Unicode (www.unicode.org)
 
 struct UnicodeCategory {
   
   enum Symbol { mark, number, punctuation, symbol, separator, uppercase,
     lowercase, titlecase, nonspacing, spacingCombining, enclosing,
     decimalDigit, connector, dash, open, close, initialQuote, finalQuote, math,
     currency, space, line, paragraph, control, format, surrogate, privateUse,
     notAssigned, letter, modifier, other };
    
    Symbol master, subcat;
 };
 
 struct CharacterInfo {
    const char *look;
    const char *names[4];
    UnicodeCategory category;
    __builtin_int_t combiningclass; // non-combining=0,
    const char *refs; // Sorted sequence of notable chars
 };
 
 MACRO bool EightBitHasPrefix(const char *eightBitString, const char *
   eightBitPrefix) { if (!*eightBitString) { return false; } while (
   *eightBitString && *eightBitPrefix) { if(*eightBitString++ != *
   eightBitPrefix++) return false; } return true; }
 
 extern CharacterInfo unicodes[];
 
 MACRO bool UnicodeIsFormat(char32_t c) { return unicodes[c].category.master == UnicodeCategory::other && unicodes[c].category.subcat == UnicodeCategory::format; } // Doesn't have a visible appearance, but may have an effect on the appearance or behavior of neighboring characters. e.g 200c zero width non-joiner, 200d zero width joiner
 MACRO bool UnicodeIsControl(char32_t c) { return unicodes[c].category.master == UnicodeCategory::other && unicodes[c].category.subcat == UnicodeCategory::control; }
 MACRO bool UnicodeIsPrivateUse(char32_t c) { return (0xE000 <= c && c <= 0xF8FF) || (0xF0000 <= c && c <= 0xFFFFD) || (0x100000 <= c && c <= 0x10FFFD); }
 MACRO bool UnicodeIsUnassigned(char32_t c) { return (0x1FF80 <= c && c <= 0x1FFFF) || (0x2FFFE <= c && c <= 0x2FFFF) || (0xEFF80 <= c && c <= 0xEFFFF); }
 MACRO bool UnicodeIsCombining(char32_t c) { return (0x0300 <= c && c <= 0x036F) || (0x1AB0 <= c && c <= 0x1AFF) || (0x1DC0 <= c && c <= 0x1DFF) || (0x20D0 <= c && c <= 0x20FF) || (0xFE20 <= c && c <= 0xFE2F); }
 
 /**  Given a Unicode character, return textual description. */
 
 MACRO const char * UnicodePrimaryName(char32_t c) { return unicodes[c].names[0]; }
 
 /**  Given a Unicode character, return category. */
 
 MACRO UnicodeCategory UnicodeCategory(char32_t c) { return unicodes[c].category; }
 
 /**  Given a textual description, return corresponding character. */
 
 MACRO char32_t Unicode(const char * eightBitDescr) { char32_t i = 0; while (
   unicodes[i].combiningclass != TriboolUnknown) { if (EightBitHasPrefix(
   (char *)(unicodes[i].names[0]), (char *)eightBitDescr)) return i; i++; }
   return 0; }
 
  typedef Optional<Tuple<__builtin_int_t, __builtin_int_t>> UnicodesAndBytes;
  UnicodesAndBytes Utf8TraverseNullterminated(uint8_t *p, __builtin_int_t
    maxlength, void (^stream)(__builtin_int_t, uint8_t*, __builtin_int_t) =
    ^(__builtin_int_t graphemeIdx, uint8_t *p, __builtin_int_t bytes) {});
  char32_t Utf8ToUnicode(uint8_t *p, __builtin_int_t bytes);
 
#pragma mark - Traversing a Unicode String (See http://unicode.org/reports/tr29/)
 
 typedef struct Utf8Location {
    uint8_t * start;
    __builtin_int_t bytesOffset;
 } Utf8Location;
 
 typedef struct UnicodeLocation {
    MemoryRegion * region;
    __builtin_int_t bytesOffset;
 } UnicodeLocation;
 
 typedef struct UnicodeInterval {
    UnicodeLocation closedBegin;
    UnicodeLocation closedEnd;
 } UnicodeInterval;
 
 typedef struct GraphemeCluster {
    UnicodeLocation location;
    __builtin_int_t bytes;
 } GraphemeCluster;
 
 typedef struct UnicodeBeam {
    UnicodeLocation location;
    Optional<SemanticPointer<char32_t *>>
    unicodeLook(
        __builtin_int_t unicodesAhead,
        BinaryChoice direction
    ) const;
    Optional<GraphemeCluster>
    clusterLook(
        __builtin_int_t clustersAhead,
        BinaryChoice direction
    ) const;
 } UnicodeBeam;
 
 /**  Sets @c beam to beginning of string. */
 
 INLINED void UnicodeBeamInitialize(String &s, UnicodeBeam *beam, bool atEnd);
 
 /**  Advance @c beam one grapheme. */
 
 INLINED int UnicodeNext(UnicodeBeam *beam, BinaryChoice direction,
   __builtin_int_t steps = 1);
 
 /**  Revert @c beam one grapheme. */
 
 INLINED int UnicodePrevious(UnicodeBeam *beam, BinaryChoice direction,
   __builtin_int_t steps = 1);
 
 /**  Inserts a presumably decorative character at `loc`.  */
 
 INLINED void UnicodeCompose(UnicodeLocation location, char32_t c);
 
 /**  Removes the n'th composed character. */
 
 INLINED void UnicodeDecompose(UnicodeLocation location, unsigned combiningIndex); // 0 is the last composed character
 
 /**  Return the number of combining characters following beam. */
 
 __builtin_int_t UnicodeCombiningCount(UnicodeBeam *beam, BinaryChoice direction);
 
 /**
  
  Decompose two precomposed graphemes into graphemes without precomposition.
  
  */
 
 INLINED int UnicodeCanonicalDecomposition(GraphemeCluster lhs, GraphemeCluster
   rhs, void (^touchbase)(GraphemeCluster &l, GraphemeCluster &r));
 
 /**
  
  Compose grapheme streams into precomposed graphemes. Idempotent composition
  of ligatures.
  
  */
 
 INLINED int UnicodeCanonicalComposition(GraphemeCluster lhs, GraphemeCluster
   rhs, bool (^touchbase)(GraphemeCluster &l, GraphemeCluster &r));
 
#pragma mark Unicode Grapheme Cluster Comparision
 
 MACRO
 bool
 IsNotEqual(
     GraphemeCluster lhs,
     GraphemeCluster rhs
 )
 {
     return UnicodeCanonicalComposition(lhs, rhs,
       ^(GraphemeCluster &lhs, GraphemeCluster &rhs) {
        
        for (__builtin_int_t pos = 0; lhs.bytes == rhs.bytes &&
          pos < Relative<__builtin_int_t>::min(lhs.bytes, rhs.bytes); pos++) {
            // if (*(lhs.start + pos) != *(rhs.start + pos)) return true;
        }
        
        return lhs.bytes == rhs.bytes;
    });
 }
 
#pragma mark Unicode String Comparision
 
 /**  Return @c true if @c lhs and @c rhs contains equal normalized strings. */
 
 MACRO bool IsEqual(String lhs, String rhs) {
    
    UnicodeBeam l, r; UnicodeBeamInitialize(lhs, &l, false);
    UnicodeBeamInitialize(rhs, &r, false);
    
 again:
    
    __builtin_int_t lc = UnicodeCombiningCount(&l, BinaryChoiceToRight);
    __builtin_int_t rc = UnicodeCombiningCount(&r, BinaryChoiceToRight);
    
    if (lc != 0 && rc != 0) {
        if (lc == rc) {
        //    auto lgc = GraphemeCluster { l.unicode, lc };
        //    auto rgc = GraphemeCluster { r.unicode, rc };
        
        //    if (IsNotEqual(lgc, rgc)) return false;
        //    else {
            UnicodeNext(&r, BinaryChoiceToLeft);
            UnicodeNext(&l, BinaryChoiceToLeft);
            goto again;
        //    }
        } else { return false; }
        
     } else { return lc == 0 && rc == 0; }
 }
 
 enum class UnicodeDifference { casing, capitalization, decoration, spacing,
   figure, quotes, math, interpunctuation, word };
 
 int UnicodeNonapproximativeCompare(String left, String right,
   bool normalizeBeforeComparision,
   void (^completion)(bool isEqual) = ^(bool isEqual) {},
   bool (^acceptable)(UnicodeDifference delta, bool& stop) =
     ^(UnicodeDifference delta, bool& stop) { return false; },
   void (^ping)(bool& stop) = ^(bool& stop) {}
 );
 
#pragma mark Utf-8 O(n)'s
 
 MACRO bool Utf8IsEqual(const char *utf8Left, const char *utf8Right) { while
   (*utf8Left && *utf8Right) { if (*utf8Left++ != *utf8Right++) return false; }
   return true; }
 
/**  Old-style canonized file path, interval, firstLine ╳ lastLine ∈ [0, ⃨,n-1]. */
 
 typedef Tuple<String, UnicodeInterval, Tuple<__builtin_int_t, __builtin_int_t>> SourceLocation; // ☜😐🇵🇱: ? 🔍≥ ∨ ?
 
#pragma mark - Converting the IEEE 754-2008 base-2 to a Textual Representation
 
 ENCLAVED
 void
 CastToText(
    double value,
    void (^digits)(bool neg, int e, const char *zeroToNineAndNull),
    void (^zero)(), void (^inf)(), void (^nan)()
 ); // 101.01, 3.141592654, 1.01e7, 1.4 * 10^5, 14kΩ and hypothetically other formats.
 
#pragma mark - The Vector: Multiple Same-sized Items, yet possily Growing

/**  In-memory growth direction. */

 enum class PhysicalDirection { TowardsEnd, TowardsBeginning };

/**  Shared management between the Vector and the Matrix. */

 struct Table {
    
    Table(__builtin_int_t c, __builtin_int_t sz) { count = c; bytesEach = sz; }
    
    ~Table() {}
    
    INLINED void * alloc(void *(^allocate)(__builtin_int_t bytes),
      __builtin_int_t bytesEach, __builtin_int_t itemCount = 1,
      bool readonly = true);
    
    MACRO __builtin_int_t bytes() const { return count*bytesEach; }
    
 protected:
    
    __builtin_int_t count; __builtin_int_t bytesEach;
    
 };

 template <typename T>
 struct Vector : public Table /*, public Mitigate<T, Vector<T>> */ {
    
    __builtin_int_t available; MemoryRegion memoryRegion;
    
    Vector<T> readwrite(__builtin_int_t initCount = 1) { void * pristine
      = alloc(^(__builtin_int_t bytes) { return malloc(bytes); }, sizeof(T),
      initCount, false); return Vector<T>(pristine, initCount); }
    
    Vector<T> readonly(__builtin_int_t initCount = 0, bool pooled = true,
      bool lazy = true) { void * pristine = alloc(^(__builtin_int_t bytes) {
      return malloc(bytes); }, sizeof(T), initCount, true); return Vector<T>(
      pristine, initCount); }
    
    Vector(void * p, __builtin_int_t count) : Table(count, sizeof(T)) {
        memoryRegion.incorporate(p, bytes(), 0x0); available = 0; }
    
    Vector(__builtin_int_t initCount = 1) : Vector(malloc(initCount), initCount) { }
    
    ~Vector() {
#if _DEBUG
        __builtin_int_t sz = bytes(); Termlog << "Dealloc " << sz << eol;
#endif
    }
    
#pragma mark Helpers
    
    MACRO SemanticPointer<T *> pointer(__builtin_int_t index) {
        __builtin_int_t offset = index * bytesEach;
        SemanticPointer<void *> p = memoryRegion.pointer(offset);
        return SemanticPointer<T *> { (T *)p.pointer };
    }
    
#pragma mark Sequence and Transfer
    
    MACRO __builtin_int_t count() const { return Table::count; }
    
    MACRO int dereference(__builtin_int_t index, void (^touchbase)(SemanticPointer<T *> elem)) {
        SemanticPointer<T *> p = pointer(index);
        touchbase(p);
        return 0;
    }
    
    MACRO int incorporate(__builtin_int_t index, uint8_t *p, __builtin_int_t bytes) {
        SemanticPointer<uint8_t *> dst = SemanticPointer<uint8_t *> {(uint8_t *)pointer(index).pointer };
        CopyMemory8(dst.pointer, p, bytes);
        return 0;
    }
    
#pragma mark The Basics (old-style)
    
    MACRO void set(__builtin_int_t index, const T &value, bool autoexplore) {
        if (incorporate(index, (uint8_t *)&value, sizeof(T))) {
        }
    }
    
    MACRO T& get(__builtin_int_t index) {
        SemanticPointer<T *> p = pointer(index);
        return (T&)*(p.pointer);
    }
    
#pragma mark Errors
    
    enum class ErrorCode { accessViolation, outOfVirtualMemory };
    
    MACRO static void Error(ErrorCode code) BLURTS {
        switch (code) {
            case ErrorCode::accessViolation: BLURT("Access Violation");
            case ErrorCode::outOfVirtualMemory: Halt;
        }
        BLURT("General exception");
    }
    
#pragma mark Traditionals
    
    MACRO void pushback(const T &value) { set(available++, value, true); }
    MACRO T& popback() { if (!available) Error(ErrorCode::accessViolation); return get(--available); }
    MACRO SemanticPointer<T *> front() BLURTS const { if (count() < 0) { Error(ErrorCode::accessViolation); } return &get(0); }
    MACRO SemanticPointer<T *> back() BLURTS const { __builtin_int_t l = count() - 1; if (l < 0) { Error(ErrorCode::accessViolation); } return get(l); }
    // MACRO int pushbackOrExplore(T &value, void (^ping)(int64_t bytesDone,
    //   int64_t bytesLeft) = ^(int64_t, int64_t) {}, void (^completion)
    //     (int64_t bytes) = ^(int64_t){}) const { return 0; }
    
#pragma mark Trial-API for Connoisseur Development 🎁😐🎂
    
    int incorporate(__builtin_int_t index, Vector<T> sub) { return 0; }
    static Vector<T> merge(Vector<T> head, Vector<T> tail, bool clone) { return Vector<T>(); }
    void append(__builtin_int_t increment) { memoryRegion.append(increment); }
    // int exclude(__builtin_int_t start, __builtin_int_t count) { return 0; }
    
#pragma mark Mitigate
    
    Tuple<Vector<T>, Vector<T>> attach(__builtin_int_t index) const {
        __block Vector<T> pre, post;
        forall(^(T *curr, bool first, bool last, __builtin_uint_t idx, bool& stop) {
            if (idx < index) { pre.pushback(*curr); } else { post.pushback(*curr); }
        });
        //for (__builtin_int_t i = 0; i < count(); i++) {
        //    T& curr = this->at(i);
        //    if (i < index) { pre.pushback(curr); } else { post.pushback(curr); }
        //}
        return Tuple<Vector<T>, Vector<T>>(pre, post);
    }
    
    Tuple<Vector<T>, Vector<T>> detach(__builtin_int_t index, void *(^allocate
      )(__builtin_int_t bytes)) const {
        __block Vector<T> pre, post;
        forall(^(T *curr, bool first, bool last, __builtin_uint_t idx, bool& stop) {
            T * c = curr->clone();
            if (idx < index) { pre.pushback(c); } else { post.pushback(c); }
        });
        return Tuple<Vector<T>, Vector<T>>(pre, post);
    }
    
#pragma mark Misc. Features
    
    Vector(std::initializer_list<T> l) : Table(l.size()/sizeof(T), sizeof(T)) {
        const T * it = l.begin(); const T * const end = l.end();
        for (; it != end; ++it) pushback(*it); }
    MACRO T& operator[] (__builtin_int_t index) { return get(index); }
    MACRO bool empty() const { return count() == 0; }
    MACRO void push(const T &e) { pushback(e); }
    MACRO T& pop() { return popback(); }
    MACRO int forallElems(void (^block)(T *elem)) {
        auto ret = this->forall(^(T *p, bool first, bool last, __builtin_uint_t idx,
          bool& stop) { block(p); }); return ret; }
    MACRO Optional<int> until(bool (^block)(T &elem)) const { return Optional<int>::no(); }
    MACRO T& first() BLURTS { if (count() < 0) { Error(ErrorCode::accessViolation); } return get(0); }
    MACRO T& last() BLURTS { __builtin_int_t l = count() - 1;  if (l < 0) {
      Error(ErrorCode::accessViolation); } return get(l); }
    
 };

#pragma mark - Streams

 struct InputStream LONGTOOTH {
    virtual __builtin_int_t read(uint8_t *p, __builtin_int_t maxBytes) = 0;
 };

 struct OutputStream LONGTOOTH {
    virtual __builtin_int_t write(uint8_t *p, __builtin_int_t bytes) = 0;
 };

#pragma mark - Stream I/O

int
vfprintf_unicode(
    OutputStream *stream,
    const char32_t *oneblockFormat,
    __builtin_va_list arg
);

int
vfprintf_utf8(
    OutputStream *stream,
    const char *format,
    __builtin_va_list arg
);

int UnicodeToUtf8(char32_t c, void (^completion)(const char *p, int bytes));

#pragma mark - Your Typecase, Part I/III

namespace Typecase {
    
    typedef int64_t TypefaceAnatomy;
    
    BITMASK(TypefaceAnatomy) {
        Bold        = 0b000000000000000000000000001,
        Italic      = 0b000000000000000000000000010,
        Slant       = 0b000000000000000000000000100,
        SansSerif   = 0b000000000000000000000001000,
        Monospace   = 0b000000000000000000000010000,
        Number      = 0b000000000000000000000100000, // complementary set of numbers
        Stillistic  = 0b000000000000000000001000000, // a.k.a. script or calligraphy
        Blackletter = 0b000000000000000000010000000, // early typeface e.g. fraktur
        Cjk         = 0b000000000000000000100000000, // Chinese, Japanese or Korean
        Greek       = 0b000000000000000001000000000,
        Symbolic    = 0b000000000000000010000000000, // non-character
        Cultural    = 0b000000000000000100000000000, // emojs
        Musical     = 0b000000000000001000000000000,
        Ornamental  = 0b000000000000010000000000000, // often used in unison with other ornamentals
        Mathdisplay = 0b000000000000100000000000000,
        Display     = 0b000000000001000000000000000, // math and/or ≅30 pt or larger
        Smallprint  = 0b000000000010000000000000000, // math and/or ≅30 pt or larger
        Demo        = 0b000000000100000000000000000, // for pangram and samples
        Combining   = 0b000000001000000000000000000,
        Mergable    = 0b000000010000000000000000000,
        Bundable    = 0b000000100000000000000000000, // can be included in e.g. a file
        Overlay     = 0b000001000000000000000000000,
        Revcontrast = 0b000010000000000000000000000, // reverse contrast (horizontal lines are the thicker than verical)
        Effect      = 0b111100000000000000000000000  // interior of glyph in background e.g. inline, block, outline or shadow
    };
}

#pragma mark - Colors

typedef Tuple<half, half, half> P3Color;

typedef Tuple<half, half, half, half> CMYKColor;

struct Color {
    union Colorspace {
        struct P3 { P3Color p3; P3Color transparancy; };
        struct CMYK { CMYKColor cmyk; CMYKColor transparancy; };
    };
    
    __builtin_uint_t kind;
};

/**  See @c TypedImpression below for details. */

typedef double Fontsize;

struct TypedExpression {
    Typecase::TypefaceAnatomy anatomy;
    Optional<Fontsize> points;
    Optional<const char *> face; // pointer into typedExpressionFaceStringpool
    Optional<Color> color;
};

#define typedIn(anatomy) TypedExpression { anatomy, Optional<Fontsize>::no(), Optional<const char *>::no(), Optional<Color>::no() }

#pragma mark - Cryptographic Hash

/**
 
 Computes a cryptographic hash value similar to NIST FIPS PUB 180-4:
 "Secure Hash Standard (SHS)", August 2015.
 
 See http://nvlpubs.nist.gov/nistpubs/FIPS/NIST.FIPS.180-4.pdf for details.
 
 */
 
 int HwHash(uint8_t *p, __builtin_uint_t bytes, void (^ping)(bool &stop),
   void (^completion)(uint64_t digest[4]));
 // int SwHash(uint8_t *p, __builtin_uint_t bytes, void (^ping)(bool &stop), void
 //    (^completion)(uint64_t digest[4]));
 
 template <typename T>
 MACRO
 sexdeca hash(T *p) {
     
     __block sexdeca res;
     
     HwHash((uint8_t *)p, sizeof(T), ^(bool &stop) {}, ^(uint64_t digest[4]) {
         res.sexdeca = _mm_set_epi64x(digest[0], digest[1]);
     });
     
     return res;
 }

#pragma mark - Decorated String in Procrastinative Style

FINAL struct DecoratedString : Mitigate<DecoratedString, DecoratedString> {
    //   ⎡      😐≅        ⎤
    // ♢⎢    😐?😐≅😐     ⎥
    //   ⎣ 😐?😐≅😐?😐?😐?⎦
    
    DecoratedString(String s);
    
#pragma mark Sequence
    
    __builtin_int_t count() const; // The number of graphemes
    
    int dereference(__builtin_int_t unicodeIndex, void (^touchbase)(DecoratedString *elem)) const;
    
    int dereference(__builtin_int_t unicodeIndex, void (^touchbase)(char32_t unicode));
    
#pragma mark Mitigate
    
    DecoratedString clone(void *(^allocate)(__builtin_int_t bytes)) const;
    
    Tuple<DecoratedString, DecoratedString> attach(__builtin_int_t index) const;
    
    Tuple<DecoratedString, DecoratedString> detach(__builtin_int_t index, void
      *(^allocate)(__builtin_int_t bytes)) const;
    
#pragma mark Mutability
    
    static DecoratedString epsilon();
    
#pragma mark Misc
    
    MemoryRegion * unicodes();
    
😐;
    
#pragma mark - Semantic Analysis

 enum ProbedSemanticContext { Inexplainatoria, Informal, Formal };
    
#pragma mark - The Utf8Terminal, Part I/II

struct Utf8Terminal {
    
    // The only available state, A.k.a '@c std::fixed fortunately eliminated'.
    enum class Style { sequential, editsAllowed }; // Example: vt100 and vi.
    
    Utf8Terminal(Style style); // if !editAllowed, use stderr
    
    ~Utf8Terminal();
    
    virtual
    int
    read(
        __builtin_int_t periods,
        __builtin_int_t seconds,
        void (^ping)(bool &stop),
        void (^touchbase)(DecoratedString ds)
    ) const;
    
    INLINED
    int
    password(
        __builtin_int_t periods,
        __builtin_int_t seconds,
        void (^ping)(bool &stop),
        void (^touchbase)(DecoratedString ds)
    ) const;
    
    virtual void write(DecoratedString ds) const;
    
    //void includeTerminal(FileTerminal *logger);
    
#pragma mark Streams
    
    OutputStream * outputStream() const;
    OutputStream * inputStream() const;
    
😐;

void Present(Utf8Terminal &term, __builtin_int_t z);
enum class PresentBase { dec, hex, oct, bin };
void Present(Utf8Terminal &term, __builtin_uint_t n, PresentBase base = PresentBase::dec);
void Present(Utf8Terminal &term, double value, int decimals = 15, bool scientific = true);
MACRO void Present(Utf8Terminal &term, DecoratedString ds) { term.write(ds); }
// void Present(Utf8Terminal &term, SourceLocation location);

extern Utf8Terminal _myTerminal;

#pragma mark - Your Typecase, Part II/III

namespace ComposingStick {
    
    MACRO DecoratedString compose(String &s, TypedExpression expr) {
      return DecoratedString(s); }
    
    MACRO UnicodeInterval mergeWith(UnicodeInterval i, bool temporary,
      DecoratedString &ds, TypedExpression expr) { return UnicodeInterval {}; }
    
    MACRO TypedExpression probe(Utf8Location l, bool temporary,
      DecoratedString &ds) { return typedIn(Typecase::Bold); } // second is temporary
    
    MACRO TypedExpression probe(UnicodeInterval l, bool temporary,
      DecoratedString &ds) { return typedIn(Typecase::Bold); }
    
    MACRO UnicodeInterval updateTo(UnicodeInterval i, bool temporary,
      DecoratedString &ds, TypedExpression expr) { return UnicodeInterval {}; }
    
    MACRO UnicodeInterval clear(UnicodeInterval i, bool temporary,
      DecoratedString &ds) { return UnicodeInterval {}; }
    
    // 'Virtual Manhattan and physical Manhattan later' // ☜😐📖
    MACRO UnicodeInterval clear(UnicodeLocation i, Manhattan dirs,
      bool temporary, DecoratedString &ds) { // 😐😐: > 'for' ✜𒀽 ⏱🏁
        return UnicodeInterval {}; }
}

#pragma mark - Conveniences for Small Clients

 MACRO Utf8Terminal & operator<<(Utf8Terminal &term, __builtin_int_t z)
 { Present(term, z); return term; }
 
 MACRO Utf8Terminal & operator<<(Utf8Terminal &term, __builtin_uint_t n)
 { Present(term, n, PresentBase::hex); return term; }
 
 MACRO Utf8Terminal & operator<<(Utf8Terminal &term, double x)
 { Present(term, x, 15); return term; }
 
 MACRO Utf8Terminal & operator<<(Utf8Terminal &term, DecoratedString s)
 { Present(term, s); return term; }
 
 MACRO Utf8Terminal & operator<<(Utf8Terminal &term, String s)
 { auto ds = ComposingStick::compose(s, typedIn(Typecase::Bold));
  term << ds; return term; }

 MACRO Utf8Terminal & operator<<(Utf8Terminal &term, const char32_t *unicodes)
 { String s = StringLiteral(Endianness::Native, unicodes, -1); term << s;
  return term; }

 MACRO Utf8Terminal & operator<<(Utf8Terminal &term, char32_t unicode)
 { String s = StringLiteral(Endianness::Native, &unicode, 1); term << s;
  return term; }
    
 MACRO Utf8Terminal & operator<<(Utf8Terminal &term, const char * utf8)
 { String s = StringLiteral(utf8); term << s; return term; }
 
 MACRO Utf8Terminal & operator<<(Utf8Terminal &term, char c)
 { char buf[2]; buf[0] = c; buf[1] = 0; term << buf; return term; }
 
 template <typename T> Utf8Terminal& operator<<(Utf8Terminal &term,
    Vector<T> &v) { Present(v, term); return v; }
 
// Utf8Terminal & operator<<(Utf8Terminal &u8os, Utf8Terminal present) { return u8os; }
    
#pragma mark - Header-based Reflection

 typedef Tuple<uint8_t *, __builtin_int_t> RegionPrimitive;
 
 enum class Subring { readexec, readwrite, nonaccess };
 
 struct Namespace { const char *ident; __builtin_int_t parent; };
 
 struct Attribute {
    const char *ident;
    __builtin_int_t offset;
    __builtin_int_t bytes;
 };
 
 struct Type;
 struct ArgumenttypeNode {
    Type *type;
    ArgumenttypeNode *next;
 };
 
 template <typename C, typename M>
 struct MethodWrap {
    union Wrap {
        M C::*member;
        void *vTableEntry;
        Wrap(M C::*m) { member = m; }
    } wrap;
    MethodWrap(M C::*m) : wrap { m } { }
 };
 
 template <typename C, typename M>
 constexpr void * MW(M C::*m) {
    MethodWrap<C, M> wrap(m);
    return wrap.wrap.vTableEntry; }
 
 struct Method {
    const char * ident;
    __builtin_uint_t returntype;
    void *vTableEntry;
    ArgumenttypeNode *argumenttypes;
 };
 
 struct Type {
    const char * ident;
    __builtin_int_t memberBytes;
    Vector<Attribute> attrs;
    std::initializer_list<Method> methods;
    uint64_t parents[];
 };
 
 struct Reflection {
    __builtin_int_t space;
    std::initializer_list<Type> type;
 };
 
 MACRO bool IsNull(Reflection *refl)
 {
    const Type * type = std::begin<Type>(refl->type);
    return type->memberBytes == -1;
 }
 
 struct Reflectable {
    virtual const char * classname() const noexcept = 0;
    static Vector<Attribute> attributes() { return { }; };
 };
 
 template <typename T = Reflectable>
 int
 RegionFor(
    T& object,
    const char * key,
    void (^touchbase)(void *loc, __builtin_int_t bytes)
 )
 {
    // Requires access to the binary we have loaded, linked and currently runs
    extern __builtin_uint_t MachoImageOrdinal(void *pointer);
    extern int MachOContent(uint64_t imageordinal, const char *segment, const
      char *section, void (^callback)(RegionPrimitive region, Subring max,
      Subring initial, bool& stop));
    __builtin_uint_t imageordinal = MachoImageOrdinal((void *)(&object));
    if (MachOContent(imageordinal, "REFL", "refl", // "reflection_main_cpp",
        ^(RegionPrimitive region, Subring max, Subring initial, bool& stop) {
            Reflection *refl = (Reflection *)get<0>(region);
            while (!IsNull(refl++)) {
                Type * type = (Type *)std::begin<Type>(refl->type);
                if (Utf8IsEqual(object.classname(), type->ident)) { // typeinfo ⬷ CEASED_TO_BE_PRONONCED
                    for (__builtin_uint_t i = 0; i < type->attrs.count(); i++) {
                        Attribute& a = type->attrs.get(0);
                        if (Utf8IsEqual(key, a.ident)) { // TODO: Change to unicode string comparision
                            touchbase((void *)((uint8_t *)&object + a.offset), a.bytes);
                            stop = true;
                        }
                    }
                }
            }
        }))
        {
        }
        
        return 0;
    }
 
#endif
