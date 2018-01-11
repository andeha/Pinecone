/*

	System.h
	PineconeLite

 */

#ifndef __SYSTEM_H
#define __SYSTEM_H

#pragma mark Constants and Misc. Polar Hysteresis

namespace Naturals {
constexpr auto π = 3.1415926535897932384626433832795028841971693993751058209749;
constexpr auto e = 2.7182818284590452353602874713526624977572470936999595749669;
constexpr auto φ = 1.6180339887498948482045868343656381177203091798057628621354;
}

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

#pragma mark - Directions

typedef __builtin_uint_t BinaryChoice; BITMASK(BinaryChoice) { 
	BinaryChoiceToLeft  = 0b0, BinaryChoiceToRight = 0b1 };

#pragma mark - Algebraic Structures and Mathematical Artifacts

 template <typename T> struct Relative {
    static T arithmeticBetween(T x₁, T x₂) { return (x₁ + x₂) / 2; }
    // static T geometricBetween(T x₁, T acc) { return sqrt(x₁ * acc); } // See: Search ☜😐: ⌨️ MMXVII, XXX, ⅳ  ⃨ 
    // static T harmonic1Between(T x₁, T acc) { return 1 / sqrt(x₁ * acc); } // See: Padé ☜😐: ⌨️ 🐚, 🐇,
    static Relative<T> leftChange(T x₁, T x₂) { return (x₁ - x₂) / x₂; } // ∈ [0, 1]
    static Relative<T> rightChange(T x₁, T x₂) { return (x₂ - x₁) / x₁; } // ∈ [0, 1]
    // Norm == Sequence<T>|AccumulativeSequence<T> S, AlgebraicCategory<T> C
    static T dist(T x₁, T x₂, T(^N)(T x, T y)) { return N(x₁ - x₂); } // ∈ [0, 1]
    static T max(T x₁, T x₂) { return x₁ < x₂ ? x₂ : x₁; }
    static T min(T x₁, T x₂) { return x₂ < x₁ ? x₂ : x₁; }
    static bool eqrel(T x₁, T x₂) { return !(x₁ < x₂ || x₂ < x₁); };
    static bool eqeql(T x₁, T x₂) { return x₁ == x₂; };
    T value;
 };

#pragma mark - Endianess, 128/256-bits Computers, IEEE 754-2008 and 𝒕𝒉𝒆 𝒉𝒂𝑙𝑓

typedef union {
    double value; // 2^–1022  2^1023 or 2.23 × 10^–308 to 1.79 × 10^308
    struct { uint32_t lsl; int32_t msl; } little_endian;
	struct { int32_t msl; uint32_t lsl; } big_endian;
	struct { uint32_t lsl; uint32_t msl; } unsigned_little_endian;
	struct { uint32_t msl; uint32_t lsl; } unsigned_big_endian;
	struct {
		unsigned mantissal : 32;
		unsigned mantissah : 20;
		unsigned exponent  : 11;
		unsigned sign      :  1;
	} ieee754;
#ifdef __x86_64__
	uint64_t quad;
#endif
} quad;

#ifdef  __mips__
typedef quad uint64_t;
typedef quad int64_t;
#endif

typedef union {
    //__m128 whole;
    // __M128I integer;
    // __M128D doublePrecFloat;
    struct { int64_t lsq; uint64_t msq; } little_endian;
    struct { int64_t msq; uint64_t lsq; } big_endian;
    struct { uint64_t lsq; uint64_t msq; } unsigned_little_endian;
    struct { uint64_t msq; uint64_t lsq; } unsigned_big_endian;
} octa;

typedef __builtin_uint_t * WordAlignedRef; typedef uint8_t * ByteAlignedRef;

INLINED ByteAlignedRef CopyMemory8(ByteAlignedRef dst, ByteAlignedRef src,
	 __builtin_uint_t bytes);

#pragma mark - Math

 #define SIGNBIT_IEEE754BASE2_64BIT 0x8000000000000000
 #define SIGNBIT_IEEE754BASE2_32BIT 0x80000000
 #define SIGNBIT_INT64 0x8000000000000000
 #define SIGNBIT_INT32 0x80000000
 #define UINT64_MAX 0xffffffffffffffffUL
 #define INT64_MAX  0x7fffffffffffffffL
 #define INT64_MIN  (-0x7fffffffffffffffL-1)

 #define IEEE754BASE2_64BIT_NAN 0x7ff8000000000000L
 // #define IEEE754BASE2_64BIT_QNAN //0xfff8000000000000L
 #define IEEE754BASE2_64BIT_INF 0x7ff0000000000000L
 #define IEEE754BASE2_64BIT_NEGINF 0xFff0000000000000L

 #define abs64i(x) int64_t((uint64_t)(x) & ~(1<<63))
 #define abs32i(x) int32_t((uint32_t)(x) & ~(1<<31))
 #define abs32s(x) float((uint32_t)(x) & ~(1<<31))
 MACRO double abs64d(double x) { return x < 0 ? -x : x; }
  
 MACRO bool isinf(double x) {
    quad y; y.value = x;
 	return y.ieee754.exponent == 0x7ff || y.ieee754.exponent == 0xfff;
 }

 MACRO bool isnan(double x) {
    quad y; y.value = x;
 	return (y.ieee754.mantissah != 0 || y.ieee754.mantissal != 0) &&
         y.ieee754.exponent == 0x7ff;
 }

 MACRO bool isnegone(double x) {
     quad y; y.value = x;
     return y.little_endian.lsl == -1 && y.little_endian.msl == -1;
 }
 
/**  Compute x raised to the power y. */

 extern "C" INLINED double pow(double x, double y) WOBBLING DO_NOT_USE; // 😐📖: a*x^2 +b*x^3 == x*x*(a + b*x) ∧ 0^0 == 0^-0 == 1/0^0. 
 
#pragma mark - The Parade
 
 template <typename T> struct Sequence {
    virtual __builtin_uint_t count() const = 0;
    // virtual int dereferenceOpt(uint64_t idx, int (^touchbase)(Optional<T*> p)) const = 0;
    // virtual int dereferenceFailable(uint64_t idx, int (^touchbase)(T *p)) const = 0;
    // dereferenceOpt(idx,  ^(T *p) { touchbase(p); return 0; } ); }
    virtual int dereference(__builtin_uint_t idx, void (^touchbase)(T *p)) = 0;
    MACRO int forall(void (^block)(T *p, bool first, bool last, 
		   __builtin_uint_t idx, bool& stop)) { // TODO: _∀(void ...)
       __builtin_uint_t itemCount = count();
       __builtin_uint_t idx = 0;
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

#pragma mark - Generic, yet Efficient Serialization of a Tuple

 template <class... Ts> struct Tuple {}; template <class T, class... Ts> // ☜😐: ❌ ↰↱ ✔︎
 struct Tuple<T, Ts...> : Tuple<Ts...> { Tuple(T t, Ts... ts) : Tuple<Ts...> // ☜😐:  ⃨ ≠  ⃨  ⟷ 🌦
    (ts...), tail(t) {} T tail; };
 template <__builtin_uint_t, class> struct elem_type_holder; template <class T,
 class... Ts> struct elem_type_holder<0, Tuple<T, Ts...>> { typedef T type; };
 template <__builtin_uint_t k, class T, class... Ts>
 struct elem_type_holder<k, Tuple<T, Ts...>> { typedef typename elem_type_holder
    <k - 1, Tuple<Ts...>>::type type; };
 template <bool, typename T = void> struct std__enable_if {};
 template <typename T> struct std__enable_if<true, T> { typedef T type; };	
 template <__builtin_uint_t k, class... Ts>
 typename std__enable_if<k == 0, typename elem_type_holder<0, Tuple<Ts...>>::
 type&>::type get(Tuple<Ts...>& t) { return t.tail; }
 template <__builtin_uint_t k, class T, class... Ts> typename std__enable_if<k 
 != 0, typename elem_type_holder<k, Tuple<T, Ts...>>::type&>::type
 get(Tuple<T, Ts...>& t) { Tuple<Ts...> &base = t; return get<k-1>(base); }
 template <class ...T> Tuple<T...> Tie(T... t) { return Tuple<T...>(t...); }
 
 namespace std { // A Standard Residual
	 
	  typedef __builtin_uint_t size_t;
  
      template<class T>
      class initializer_list {

          const T *beg; size_t sz;

          initializer_list(const T *b, size_t s) : beg(b), sz(s) {}

      public:

          typedef T value_type;
          typedef const T& reference;
          typedef const T& const_reference;
          typedef size_t size_type;
          typedef const T *iterator;
          typedef const T *const_iterator;

          initializer_list() : beg(0), sz(0) {}

          size_t size() const { return sz; }
  
          const T * begin() const { return beg; }
          const T * end() const { return beg + sz; }
       };
  }

  template<class T> inline const
  T *
  begin(
      std::initializer_list<T> il
  ) { return il.begin(); }

  template<class T> inline const
  T *
  end(
      std::initializer_list<T> il
  ) { return il.end(); }

#pragma mark - Hello! I'm Optional

template <typename T>
struct Optional {

    union Option { T inner; __builtin_uint_t no; Option() {};  ~Option() {} } option;

    Optional(T inner) { option.inner = inner; kind = 0; }

    Optional(const Optional& other) { kind = other.kind; }

    Optional() { kind = 1; }

    static Optional no() { return Optional(); }

    T * query() const { if (kind != 1) return (T*)&option.inner; else return 0; }

    __builtin_uint_t kind;

};

#define guard(type, var, expr) type var; if ((var = expr)) {}

template <typename T, typename C = Sequence<T>> struct Mitigate : public Sequence<T> {
   FINAL ENCLAVED virtual C * clone() const SWIZZLE = 0;
   virtual Tuple<C, C> branch(__builtin_uint_t index) const = 0;
};

#pragma mark - Essential Memory-Region Operations II

 INLINED ByteAlignedRef ClearMemory(ByteAlignedRef mem, __builtin_uint_t bytes);
 INLINED ByteAlignedRef SetMemory8(ByteAlignedRef src, uint8_t value, __builtin_uint_t bytes);

 typedef Tuple<uint8_t *, __builtin_uint_t> RegionPrimitive;

 enum Endianness { Native, Network };

#pragma mark - The String

 FINAL FOCAL struct String : public Mitigate<char32_t, String> {

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
     Literal(
           Endianness endianness,
           const char32_t *p,
           __builtin_uint_t graphemeCount,
           bool readonly = true
     );

    /**

     Until the grapheme located before @maxBytes, create a truncated @c String.

     */

    FOCAL
    INLINED
    static
    String
    SecureLiteral(
         const char *utf8,
         __builtin_uint_t maxBytes,
         bool readonly = true
    );

    // ~String() {} // { free(buf, bytes); }

    String(const String& other); // Copying resource
    String& operator=(const String& other); // Copy assignment operator
    String(String&& other); // Moving resource
    String& operator=(String&& other); // Move assignment operator

#pragma mark Sequence

    /**  Return the number of graphemes. Runs in O(1). */

    INLINED __builtin_uint_t count() const;

    /**  Return a single grapheme if one exists. */

	INLINED
    int
    dereference(
        __builtin_uint_t graphemeIdx,
        void (^touchbase)(char32_t *elem)
    );

#pragma mark Mitigate

    ENCLAVED INLINED String * clone() const;

    INLINED Tuple<String, String> branch(__builtin_uint_t index) const;

#pragma mark Misc

    INLINED bool empty() const;

    /**

		If dirty, lazily (re)create utf-8 representation that can be freed with
		@c free(myString.utf8Buf_)

	 */

    char * utf8(__builtin_uint_t *bytes = NULL); // O(n)

    /**  Access underlying Unicode string. */

    const char32_t * operator*(); // O(1)

    /**  Return the number of bytes consituting a Unicode string. */

    __builtin_uint_t bytes() const; // O(1)

     /**  Return empty string. */

    static String epsilon(); // ☜😐: 🕰 ⃨☀️

 private:

     String(
            __builtin_int_t utf8Bytes, uint8_t *utf8Buf,
            __builtin_int_t unicodeBytes, char32_t *unicodeBuf
     );

 😐;

#define StringLiteral String::Literal

#pragma mark - Unicode Characters
     
 enum class UnicodeCategory {
	 
	 /*
	 Lu, //	Letter, Uppercase
	 Ll, //	Letter, Lowercase
	 Lt, //	Letter, Titlecase
	 Lm, //	Letter, Modifier
	 Lo, //	Letter, Other
	 Mn, //	Mark, Nonspacing
	 Mc, //	Mark, Spacing Combining
	 Me, //	Mark, Enclosing
	 Nd, //	Number, Decimal Digit
	 Nl, //	Number, Letter
	 No, //	Number, Other
	 Pc, //	Punctuation, Connector
	 Pd, //	Punctuation, Dash
	 Ps, //	Punctuation, Open
	 Pe, //	Punctuation, Close
	 Pi, //	Punctuation, Initial quote (may behave like Ps or Pe depending on usage)
	 Pf, //	Punctuation, Final quote (may behave like Ps or Pe depending on usage)
	 Po, //	Punctuation, Other
	 Sm, //	Symbol, Math
	 Sc, //	Symbol, Currency
	 Sk, //	Symbol, Modifier
	 So, //	Symbol, Other
	 Zs, //	Separator, Space
	 Zl, //	Separator, Line
	 Zp, //	Separator, Paragraph
	 Cc, //	Other, Control
	 Cf, //	Other, Format
	 Cs, //	Other, Surrogate
	 Co, //	Other, Private Use
	 Cn, //	Other, Not Assigned (no characters in the file have this property)
     */
     letter, mark, number, punctuation, symbol, separator, other };

 struct UnicodeCharInfo {
    const char *look;
    const char *name;
    UnicodeCategory category;
    __builtin_uint_t combiningclass; // non-combining =0,
    const char *note;
    static bool isReserved(char32_t c) { return false; }
    static bool isPrivateUse(char32_t c) { return (0xE000 <= c && c <= 0xF8FF) || (0xF0000 <= c && c <= 0xFFFFD) || (0x100000 <= c && c <= 0x10FFFD); }
    static bool isGraphic(char32_t c) { return false; } // has a visible glyph shape or represent a visible space
    static bool isFormat(char32_t c) { return false; } // do not have a visible appearance, but may have an effect on the appearance or behavior of neighboring characters. e.g 200c zero width non-joiner, 200d zero width joiner
    static bool isControl(char32_t c) { return (c <= 0x001F) || (0x007F <= c && c <= 0x009F); }
    static bool isAssigned(char32_t c) { return isGraphic(c) || isFormat(c) || isControl(c) || isPrivateUse(c); }
    static bool isCombining(char32_t c) { return false; } //  U+0300..U+036F, U+1AB0..U+1AFF, U+FE20..U+FE2F, U+1DC0..U+1DFF, U+20D0..U+20FF
 };

 /**  Given a UNICODE character, return textual description. */

 const char * UnicodeDescription(char32_t c);

 /**  Given a textual description, return corresponding character. */

 char32_t Unicode(const char *description);

 extern "C" { extern const char *tab; extern const char *eol; extern const char *sep; }

/**  Merge @c prefix and @c suffix at @c prefix with optional middle padding. */

 FOCAL
 INLINED
 String
 StringMerge(
    String prefix,
    String suffix,
    __builtin_uint_t padBytes
 ); //The @c suffix parameter may very-well be @c NULL.

/**  Create focus on a region of @c s. */

 FOCAL INLINED String StringSegment(String s,
    char32_t *start, __builtin_uint_t bytes,
    bool reuse = false
 );

/**  Set bytes in the String @c s to zero to simplify debugging. */

 INLINED void StringFree(String s); // ☜😐: ?

#pragma mark - Traversing a Unicode String (See http://unicode.org/reports/tr29/)

 typedef struct GraphemeCluster {
    const char32_t *start;
    __builtin_uint_t bytes;
	GraphemeCluster(const char32_t *s, __builtin_uint_t b) { start = s; bytes = b; }
	GraphemeCluster(String components) {
		start = (char32_t *)*components;
		bytes = 4*components.count();
	}
 } GraphemeCluster;

 typedef GraphemeCluster GraphemeClusters;
 typedef GraphemeCluster GraphemeClusterPrefix;

 typedef struct Utf8Location {
    uint8_t *start;
    __builtin_uint_t bytesFromStart;
 } Utf8Location;

 typedef struct UnicodeLocation {
    char32_t *start;
    __builtin_uint_t bytesFromStart;
 } UnicodeLocation;

 typedef struct UnicodeInterval {
    UnicodeLocation closedBegin;
    UnicodeLocation closedEnd;
 } UnicodeInterval;

 typedef struct Utf8UnicodeBeam {
    uint8_t *utf8; char32_t *unicode;
    Utf8Location utf8Loc;
    UnicodeLocation unicodeLoc;
    __builtin_uint_t utf8Bytes; __builtin_uint_t unicodeBytes;
    Optional<char32_t *>
    unicodeLook(
        __builtin_uint_t ahead,
        BinaryChoice direction
    ) const;
    Optional<GraphemeCluster>
    clusterLook(
        __builtin_uint_t ahead,
        BinaryChoice direction
    ) const;
 } Utf8UnicodeBeam;

/**  Sets @c beam to beginning of string. */

 FOCAL INLINED void Utf8UnicodeBeamInitialize(String &s, Utf8UnicodeBeam *beam,
 	bool atEnd);

/**  Advance @c beam one grapheme. */

 FOCAL INLINED int UnicodeNext(Utf8UnicodeBeam *beam, BinaryChoice direction,
       __builtin_uint_t steps = 1);

/**  Revert @c beam one grapheme. */

 FOCAL INLINED int UnicodePrevious(Utf8UnicodeBeam *beam, BinaryChoice
       direction, __builtin_uint_t steps = 1);

/**  Return the number of combining characters following beam. */

 __builtin_uint_t UnicodeCombiningCount(Utf8UnicodeBeam *beam);

/**  Return current location in Unicode stream. */

 INLINED UnicodeLocation UnicodeCurrentLocation(Utf8UnicodeBeam beam);

/**  Append composition to character. */

 void Compose(UnicodeLocation loc, char32_t c);

/**  Removes a previously composed unicode. */

 void Decompose(UnicodeLocation loc, unsigned int combiningIndex);

/**

     Decompose two precomposed graphemes into graphemes without
     precomposition.
 
 */

 INLINED int CanonicalDecomposition(GraphemeCluster lhs, GraphemeCluster rhs,
    void (^touchbase)(GraphemeCluster &l, GraphemeCluster &r));

/**
 
     Compose grapheme streams into precomposed graphemes. Idempotent
     composition of ligatures.
 
 */

 INLINED int CanonicalComposition(GraphemeCluster lhs, GraphemeCluster rhs,
    bool (^touchbase)(GraphemeCluster &l, GraphemeCluster &r));

/**  Return current location in Utf8 stream. */

 INLINED Utf8Location Utf8CurrentLocation(Utf8UnicodeBeam beam);

/**  Increment or decrement a Utf8 pointer one unicode */

 INLINED int Utf8NextCodepoint(const char *p, BinaryChoice direction);

 INLINED int Utf8PreviousCodepoint(const char *p, BinaryChoice direction);

#pragma mark Utf-8 Grapheme Comparision

 ENCLAVED
 MACRO
 bool
 operator!=(
    GraphemeCluster lhs,
    GraphemeCluster rhs
 )
 {
    return CanonicalComposition(lhs, rhs,
        ^(GraphemeCluster &lhs, GraphemeCluster &rhs) {
    
            for (__builtin_uint_t pos = 0; lhs.bytes == rhs.bytes &&
                 pos < Relative<__builtin_uint_t>::min(lhs.bytes, rhs.bytes); pos++) {
                if (*(lhs.start + pos) != *(rhs.start + pos)) return true;
            }
        
            return lhs.bytes == rhs.bytes;
        });
 }

#pragma mark Utf-8 String Comparision and Concaternation

/**  Return @c true if @c lhs and @c rhs contains equal normalized strings. */

 FOCAL MACRO bool operator==(String lhs, String rhs) {

    Utf8UnicodeBeam l, r;
    Utf8UnicodeBeamInitialize(lhs, &l, false);
    Utf8UnicodeBeamInitialize(rhs, &r, false);

 again:

     __builtin_uint_t lc = UnicodeCombiningCount(&l);
     __builtin_uint_t rc = UnicodeCombiningCount(&r);

     if (lc != 0 && rc != 0) {
         if (lc == rc) {
             auto lgc = GraphemeCluster { l.unicode, lc };
             auto rgc = GraphemeCluster { r.unicode, rc };
         
             if (lgc != rgc) return false;
             else {
                 UnicodeNext(&r, BinaryChoiceToLeft);
                 UnicodeNext(&l, BinaryChoiceToLeft);
                 goto again;
             }
         } else { return false; }

     } else { return lc == 0 && rc == 0; }
 }

/**  Old-style canonized file path, interval, firstLine ╳ lastLine ∈ [0, ⃨,n-1]. */

typedef Tuple<String, UnicodeInterval, Tuple<__builtin_uint_t, __builtin_uint_t>> SourceLocation; // ☜😐🇵🇱: ? 🔍≥ ∨ ?

enum SystemDeserializationError {};

void ParseTextAsList(const char *utf8Text, void (^error)(SourceLocation loc,
   SystemDeserializationError error), void (^touchbase)(String item, bool
   first, bool last, UnicodeLocation itemLocation, bool& stop));

#pragma mark - Vector and TwoDVector

enum class PhysicalDirection { TowardsEnd, TowardsBeginning };

 struct Table {

     Table() {}
     ~Table() { delete p_; }

     __builtin_int_t count_; __builtin_int_t itemBytes_; uint8_t *p_;
         
     MACRO void alloc(void *(^allocate)(), __builtin_int_t itemBytes,
              __builtin_int_t itemCount = 1) {
         count_ = itemCount; itemBytes_ = itemBytes;
         p_ = (uint8_t *)allocate();
     }

     MACRO void setItemSize(__builtin_int_t bytes) {
         count_ *= bytes/(double)itemBytes_; itemBytes_ = bytes;
     }

     MACRO __builtin_int_t itemBytes() const { return itemBytes_; }
     
     MACRO __builtin_int_t bytes() const { return count_*itemBytes_; }

 };

/**  The 'multiple and possibly growing, still same sized items' class. */

 template <typename T>
 struct Vector : public Table, public Mitigate<T, Vector<T>> {

    __builtin_int_t free_;

    static Vector<T> * readwrite(__builtin_int_t initCount = 1) {
        Vector<T> *pristine = (Vector<T> *)Vector::alloc(true, sizeof(T), initCount);
        pristine->free_ = initCount;
        return pristine;
    }

    static Vector<T> * readonly(__builtin_int_t initCount = 0, bool pooled = true,
        bool lazy = true)  { return NULL; }

     Vector() {}

     ~Vector() {
#if _DEBUG
         __builtin_int_t sz = bytes(); Termlog << "Dealloc " << sz << eol;
#endif
     }

#pragma mark Helpers

     MACRO uint8_t *pointer(__builtin_int_t index) const {
         __builtin_int_t offset = index*itemBytes_;
         return p_ + offset;
     }

     MACRO bool outsideBoundsPrimitive(uint8_t *p) const {
         uint8_t *itemEnding = p + itemBytes_;
         uint8_t *ending = p_ + count_*itemBytes_;
         return itemEnding >= ending || p < p_;
     }

#pragma mark Sequence and Transfer

     MACRO __builtin_uint_t count() const { return count_; }

     MACRO int dereference(__builtin_uint_t index, void (^touchbase)(T *elem)) {
         uint8_t *p = pointer(index);
         if (outsideBoundsPrimitive(p)) Error(ErrorCode::accessViolation);
         touchbase((T *)p);
         return 0;
     }

     MACRO int transfer(__builtin_int_t index, uint8_t *p, __builtin_int_t bytes) {
         uint8_t *dst = pointer(index);
         if (outsideBoundsPrimitive(dst)) Error(ErrorCode::accessViolation);
         else { CopyMemory8(p, dst, bytes); }
         return 0;
     }

#pragma mark The Basics

     MACRO void set(__builtin_int_t index, const T &value, bool autoexplore) {
        if (transfer(index, (uint8_t *)&value, sizeof(T))) {
        }
     }

     MACRO T& get(__builtin_int_t index) {

        __block T *result = (T*)0;

        if (dereference(index, ^(T *elem) {

            result = elem;

        }))
        {
        }

        return (T&)*result;
     }

#pragma mark Errors

     enum class ErrorCode { accessViolation, outOfVirtualMemory };

     MACRO static void Error(ErrorCode code) BLURTS {
         switch (code) {
             case  ErrorCode::accessViolation: BLURT("Access Violation");
             case ErrorCode::outOfVirtualMemory: Halt;
         }
         BLURT("General exception");
      }

#pragma mark Traditionals

     MACRO void pushback(const T &value) { set(free_++, value, true); }
     MACRO T& popback() { if (!free_) Error(ErrorCode::accessViolation); return get(--free_); }
     MACRO T * front() const { if (free_) { return (T *)p_; } else { return NULL; } }
     MACRO T * back() const { if (!free_) return NULL; return (T *)(p_ + free_ - 1); }
     // MACRO int pushbackOrExplore(T &value, void (^ping)(int64_t bytesDone,
     //   int64_t bytesLeft) = ^(int64_t, int64_t) {}, void (^completion)
     //     (int64_t bytes) = ^(int64_t){}) const { return 0; }

#pragma mark Trial-API for Connoisseur Development

    /**  Incrementally increase the available memory. 🎁😐🎂 */

     MACRO int explore(void *now, PhysicalDirection dir, __builtin_int_t incr,
         void (^ping)(__builtin_int_t bytesDone, __builtin_int_t bytesLeft) = ^(__builtin_int_t, __builtin_int_t) {},
         void (^completion)(__builtin_int_t bytes) = ^(__builtin_int_t bytes) {}) const { return 0; }

    /**  Include an interval into an already existing structure. Taken pointers
         may become invalid, */

    MACRO int incorporate(void *p, __builtin_int_t itemCount, __builtin_int_t itemSize,
        void (^ping)(__builtin_int_t bytesInserted, __builtin_int_t offsetAfterInsert) = ^(__builtin_int_t, __builtin_int_t) {},
        void (^completion)(__builtin_int_t insertedBytes) = ^(__builtin_int_t) {}) const { return 0; }

    /**  Persist the vector if possible.  */

    MACRO int detain(void (^ping)(__builtin_int_t bytesDone, __builtin_int_t bytesLeft) = ^(__builtin_int_t, __builtin_int_t) {},
       void (^completion)(__builtin_int_t bytes) = ^(__builtin_int_t) {}) const { return 0; }

    /**  Remove an interval */

    MACRO int exclude(void *start, __builtin_int_t itemCount, __builtin_int_t itemSize,
        void (^ping)(__builtin_int_t bytesDone, __builtin_int_t bytesLeft) = ^(__builtin_int_t, __builtin_int_t) {},
        void (^completion)(__builtin_int_t bytes) = ^(__builtin_int_t) {}) const { return 0; }

#pragma mark Mitigate	

     ENCLAVED MACRO Vector<T> * clone() const { return NULL; }

     MACRO Tuple<Vector<T>, Vector<T>> branch(__builtin_uint_t index) const {
        return Tuple<Vector<T>, Vector<T>>(Vector<T>(), Vector<T>()); // ☜😐: ?
     }

#pragma mark Misc. Features

     Vector(std::initializer_list<T> l) {}
     MACRO T& operator[] (__builtin_int_t index) { return get(index); }
     MACRO bool empty() const { return count() == 0; }
     MACRO void push(const T &e) { pushback(e); }
     MACRO T& pop() { return popback(); }
     MACRO int forall2(void (^block)(T *elem)) {
         auto ret = this->forall(^(T *p, bool first, bool last, __builtin_uint_t idx,
           bool& stop) { block(p); }); return ret; }

     MACRO Optional<int> until(bool (^block)(T &elem)) const {
         return Optional<int>::no(); }
/*     MACRO static DecoratedString tokenBegin() {
         return SecureDecoratedLiteral("[", typedIn(Typecase::Bold), 1);
     }
     MACRO static DecoratedString stringWhenEmpty() {
         return SecureDecoratedLiteral("[]", typedIn(Typecase::Bold), 2);
     }
     MACRO static DecoratedString tokenEnd() {
         return SecureDecoratedLiteral("]", typedIn(Typecase::Bold), 1);
     }
     FOCAL static int stream(const Vector &v, void (^touchbase)(DecoratedString
            &pamphlet1, bool firstelem, Optional<T> &elem, bool lastelem,
            DecoratedString &pamphlet2, bool& stop)) {
        OMEGA(stop);
        if (v.count() == 0) {
            auto prefix = Vector::tokenBegin(); auto suffix = Vector::tokenEnd();
            touchbase(prefix, false, Vector::stringAsEmpty, false, suffix, stop);
            OMEGASET(stop, TriboolUnknown);
        } else {
            v.forall(^(T &elem, bool first, bool last, bool& stop) {
                auto prefix = DecoratedString::epsilon();
                auto suffix = DecoratedString::epsilon();
                // if (first) { prefix += Vector::tokenBegin(); }
                // if (last) { suffix += Vector::tokenEnd(); }
                touchbase(prefix, first, elem, last, suffix, stop);
                OMEGASET(stop, TriboolUnknown);
            });
        }
        return 0; } // to output, write: 'Termlog << myVector << ¶;'

#pragma mark Serialization

     static Optional<Vector<String>> parse(const char *utf8, void
       (^error)(SourceLocation loc, SystemDeserializationError error)) {
         __block Vector<String> items;
         ParseTextAsList(utf8,
             ^(SourceLocation loc, SystemDeserializationError e) {
                 error(loc, e);
             },
             ^(String item, bool first, bool last, UnicodeLocation itemLocation, bool& stop) {
                 items.pushback(item);
             });
         
         return items;
     }
*/
 };

#pragma mark - Platform Specific Security

 typedef octa Guid;

 int NewGuid(void (^touchbase)(Guid *guid));

 String GuidToString(Guid *guid);

 String GUID();

/**

   Return a random 64-bit value. (See '128-bit PRNG'.) The value may be
   NIST SP 800-90A compliant.

 */

 int IntegerRandom(uint64_t *x);

#pragma mark - Sugared Pinecone

 MACRO Cartesian2D
 operator+(Cartesian2D l, Cartesian2D r) {
     return Cartesian2D { l.x + r.x, l.y + r.y }; }

 MACRO Cartesian2D
 operator-(Cartesian2D l, Cartesian2D r) {
     return Cartesian2D { l.x - r.x, l.y - r.y }; }

 MACRO Cartesian2D
 operator*(double c, Cartesian2D p) {
     return Cartesian2D { p.x*c, p.y*c }; }

 MACRO Cartesian2D
 operator*(Cartesian2D p, double c) {
     return Cartesian2D { p.x*c, p.y*c }; }

 MACRO Cartesian2D
 operator/(Cartesian2D p, double c) {
     return Cartesian2D { p.x/c, p.y/c }; }

 MACRO Cartesian2D
 Middle(Cartesian2D a, Cartesian2D b) {
     return Cartesian2D { 0.5 * (b.x + a.x), 0.5 * (b.y + a.y) }; }

#pragma mark - Beziers

 typedef struct { Cartesian2D z1; Cartesian2D z2; Cartesian2D z3; Cartesian2D z4; } BezierCurve;

 void RecursiveBezier(__builtin_uint_t iter, BezierCurve c, void (^stream)(Cartesian2D p));
 void ParametricBezier(double t, BezierCurve c, void (^stream)(Cartesian2D &p,
    Optional<Cartesian2D> &prev)); //  Add uint64_t parts for a parallel Bezier.

 //void PlotQuadSpline(RegionPrimitive plate, int n, int x[], int y[]);
 //void PlotCubicSpline(RegionPrimitive plate, int n, int x[], int y[]);
 //void PlotLine(RegionPrimitive plate, int x0, int y0, int x1, int y1);

#pragma mark - Rasterization

 Rasterized2D Rasterize(Cartesian2D &c, Optional<Cartesian2D> &prev);

#endif
