//
//  Pinecone.h or Pamphlet about 😐 💀,  ∧ ∨ 🎲(2)'  ⃨ in 🇵🇱 ≅
//  Pinecone
//

#ifndef __PINECONE_H
#define __PINECONE_H

typedef double(^Recursive)(double x, double n, bool(^)(double));
#define NULL 0

// Acceptable and Enclavable Platform Base ✁ until ✂️

/**
 
    Utf-8 Non-regulars: .*｟｠ ⃦ ('Combining double vertical stroke overlay' or
        'fat-pipe') ✚ ★ ‽ ⸺ \ 𐤟 (PHOENICIAN WORD SEPARATOR) ↩︎ ↹
    Example: ｟↹↩︎｠★
    Logic and one-liners: ≅ ≠ ⋍ ~ ⟶ ⟷ ⊂⊄⊆⊈ ⊃ (Małuszyński inclusion) ∩∪ ∈∉
        ¬∧∨ ≤≥ ≰ ≱ ∞ ∀∃∄ ⊨ ∅ 𝜖 √ ∑∏ ∂𝜕∆ ∇𝛻 ∫∬∭ ¶
    Greek: 𝛢𝛣𝛤𝛥𝛦𝛧𝛨𝛩𝛪𝛫𝛬𝛭𝛮𝛯𝛰𝛱𝛲𝛳𝛴𝛵𝛶𝛷𝛸𝛹𝛺 𝛼𝛽𝛾𝛿𝜀𝜁𝜂𝜃𝜄𝜅𝜆𝜇𝜈𝜉𝜊𝜋𝜌𝜎𝜏𝜐𝜑𝜒𝜓𝜔 𝜙𝜛
    Mathematics 𝐼𝑡𝑎𝑙𝑖cs: 𝐴𝐵𝐶𝐷𝐸𝐹𝐺𝐻𝐼𝐾𝐽𝐿𝑀𝑁𝑂𝑃𝑄𝑅𝑆𝑇𝑈𝑉𝑊𝑋𝑌𝑍 𝑎𝑏𝑐𝑑𝑒𝑓𝑔ℎ𝑖𝚤𝑗𝚥𝑘𝑙𝑚𝑛𝑜𝑝𝑞𝑟𝑠𝑡𝑢𝑣𝑤𝑥𝑦𝑧
    Math. 𝑩𝒐𝒍𝒅 Italics: 𝑨𝑩𝑪𝑫𝑬𝑭𝑮𝑯𝑰𝑱𝑲𝑳𝑴𝑵𝑶𝑷𝑸𝑹𝑺𝑻𝑼𝑽𝑾𝑿𝒀𝒁 𝒂𝒃𝒄𝒅𝒆𝒇𝒈𝒉𝒊𝒋𝒌𝒍𝒎𝒏𝒐𝒑𝒒𝒓𝒔𝒕𝒖𝒗𝒘𝒙𝒚𝒛
    Math. Sans-serif: 𝟶𝟷𝟸𝟹𝟺𝟻𝟼𝟽𝟾𝟿 𝖠𝖡𝖢𝖣𝖤𝖥𝖦𝖧𝖨𝖩𝖪𝖫𝖬𝖭𝖮𝖯𝖰𝖱𝖲𝖳𝖴𝖵𝖶𝖷𝖸𝖹 𝖺𝖻𝖼𝖽𝖾𝖿𝗀𝗁𝗂𝗃𝗄𝗅𝗆𝗇𝗈𝗉𝗊𝗋𝗌𝗍𝗎𝗏𝗐𝗑𝗒𝗓
    Math. Sans-serif B𝗼𝗹𝗱: 𝗔𝗕𝗖𝗗𝗘𝗙𝗚𝗛𝗜𝗝𝗞𝗟𝗠𝗡𝗢𝗣𝗤𝗥𝗦𝗧𝗨𝗩𝗪𝗫𝗬𝗭 𝗮𝗯𝗰𝗱𝗲𝗳𝗴𝗵𝗶𝗷𝗸𝗹𝗺𝗻𝗼𝗽𝗾𝗿𝘀𝘁𝘂𝘃𝘄𝘅𝘆𝘇
    Math. Sans-serif Bold 𝘐𝘵𝘢𝘭𝘪𝘤: 𝘈𝘉𝘊𝘋𝘌𝘍𝘎𝘏𝘐𝘑𝘒𝘓𝘔𝘕𝘖𝘗𝘘𝘙𝘚𝘛𝘜𝘝𝘞𝘟𝘠𝘡 𝘢𝘣𝘤𝘥𝘦𝘧𝘨𝘩𝘪𝘫𝘬𝘭𝘮𝘯𝘰𝘱𝘲𝘳𝘴𝘵𝘶𝘷𝘸𝘹𝘺𝘻
    Mathematics 𝙼𝚘𝚗𝚘space: 𝙰𝙱𝙳𝙴𝙵𝙶𝙷𝙸𝙹𝙺𝙻𝙼𝙽𝙾𝙿𝚀𝚁𝚂𝚃𝚄𝚅𝚆𝚇𝚈𝚉 𝚊𝚋𝚌𝚍𝚎𝚏𝚐𝚑𝚒𝚓𝚔𝚕𝚖𝚗𝚘𝚙𝚚𝚛𝚜𝚝𝚞𝚟𝚠𝚡𝚢𝚣
    Models and Mathematics: ⊏ ⊑ ⊢ ⊨, ⊿ ª0 +  ⃨ + ªn₋1 n₍2k₊1₎ ª1⋯ªk ⋱ ⋰ ⋮ ∎ ⇀↽
    Parenthesis: ⎛⎜⎝   ⎞⎟⎠
    Matrices and Conditionals: ⎡⎢⎣  ⎤⎥⎦  ⎧⎨⎩  ⎫⎬⎭  ⎪
    Temporals: ◯ ♢ ▢
    ^-Graphemes: ␁ ␂ ␚
    Signals: ⎍ ⎎
    Chemistry Hobbyist: ⇾ ₀₁₂₃₄₅₆₇₈₉
    Alt. Math: ± ∓ ∔
    Big No-no: ≈ ≣ --<'', '' (Slanted dowsing.)
    Misc¹: ℃ ℉ ® © ™ № º µ Ω ℊ ℑ𝑚 ℜ𝑒 ∁ ≙ ⋈ ⫝ ⦣⧄⧅⧆⧇ ⧈ ⧉ ╳ ☩ ₧ ₥
    Misc²: ª º ✓ ✔︎ ☑︎☒ ✕ ✖︎ ✗ ✘ ▲◇□▪︎ △□◇▷▽ ○◦●∙⦁
        à ⬷ The letter 'a'+'COMBINING GRAVE ACCENT'. See ACUTE and CIRCUMFLEX
        a͟͞z͟͞ ⬷ 'Combining double-macaron' or the 'Bitfields' macraron'.
        L̵ ⬷ L and 'Combining short stroke overlay'
        a⃝ ⬷ The letter 'a' + "COMBINING ENCLOSING CIRCLE"
        ℹ︎ ⬷ 'Information source'
        i⃝ ⬷ The letter 'i' + "COMBINING ENCLOSING CIRCLE"
         ⃒⃘ ⬷ 'Combining long vertical line' and 'ring overlay'
        c⃥ ⬷ 'Combining reverse solidus overlay'
         ⃫ ⬷ 'COMBINING LONG SOLIDUS OVERLAY'
 
   Footnotes, references and (enum.) lists: ¹₁²₂³₃⁴₄⁵₅⁶₆⁷₇⁸₈⁹₉⁰₀ •○◦・•⁃⦾⦿‣⁌⁍
 
     ╮  ╯ ╭ ╰ ╱ ╲ ╳     ┤ ┌ ├ ┼ ┘ ┐ ─ │ ┴ ┬    ╴╵╷╴
 
      Key   Value   ∃
     ┾━━━╈━━━━━━━━━┿━┽           ⌏  ⌎   ⌜  ⌝  ⌖  ⏚
     │k₁ ┃         │✓│           ⌍  ⌌   ⌞  ⌟  ‖
     └───┸─────────┴─┘
 
          ┌def┐
          │   │                     ╭─ Leaf 1 ──╮
     ─abc─┘─┐ ┘           ── Stem ──┤           ├── Again ──
            └                       ╰─ Leaf 2 ──╯
 
    „ ⃨as illustrated below or above:‟
 
      ∞              ∞
      ⌠ 🔍😐         \̅
      ⎮ 𝘦^-𝘹 𝘥𝘹 ≅ √𝘹 + › ⁣⅟k² ≅ @w Sum[, ... ∈ ℝ (DOUBLE-STRUCK CAPITAL R)    (0)
      ⌡              /͟
     -∞             k=1
 
      ⎡n₁₁     ⎤    ⎧ ⎫    ⎛   ⎞      ⸑
      ⎢        ⎥    ⎨ ⎬    ⎜   ⎟     ⎸    ⎲
      ⎣     nᵣᵥ⎦    ⎩ ⎭    ⎝   ⎠    ⎷    ⎳
 
   Further, consider:
 
   Dashes: ‒ Figure Dash, – En Dash, — Em Dash, ⁓ Swung Dash, ⸺ Two-em Dash,
        ⸻ Three-em Dash, 〰 Wavy Dash, - Hyphen Minus.
 
   Arrows: ⇽ ⇾ ⟲⟳ ↗︎↘︎↙︎↖︎ ⸔⸕ ⤡⤢ ⤺⤻ ↰↱↲↳ ↴ ↩︎ ↵  ⮐ ↹ ←↑→↓
     ↼ (Leftward harpoon with barb upwards) ↽↾↿⇀⇁⇂⇃⇄⇅⇆⇇⇈⇉⇊⇋⇌⇍⇏⇐⇑⇒⇓⇚⇛⇜⇝⇤⇥⇦⇧
     ⇨⇩⇪⇵⇶ ⎔ ➔➙➛➜➝➞➟➠⟰⟤⟥ ⤶ ⤷  ↔︎
     📲📩📈📉🔃➡︎⬅︎⬆︎⬇︎↩︎⤴︎⤵︎⤴⤵ (牮筏)
     ⬷ ⤐ (Leftwards two-headed triple dash arrow)
 
   Extensions: ⁌⁍ ⊸ ⫰ ⫱ ⿱⿳⿶  ⃦ a⃮ b⃯ a͍ (Combining left and right arrow below),
     a̫b̫c̫ ⬷ 'Combining inverted double arch below' a⃨b⃨c⃨ a⃩ a⃪
     1゚ (Combining Katakana Sound Mark)
     a ⃫b (Combining long double solidus overlay)
     aᷣ (Combining latin small letter R rotund)
     a⳯b⳰c⳱ (The Coptics)
     ˥ ˦ ˧ ˨ ˩ (Tone letters)
 
    Symbol  c-char  Utf-8          Unicode Name
       ␜  "\u241C" 0xE2 0x90 0x9C SYMBOL FOR FILE SEPARATOR
       ␝  "\u241D" 0xE2 0x90 0x9D SYMBOL FOR GROUP SEPARATOR
       ␞  "\u241E" 0xE2 0x90 0x9E SYMBOL FOR RECORD SEPARATOR
       ␟  "\u241F" 0xE2 0x90 0x9F SYMBOL FOR UNIT SEPARATOR
 
    ␉ ␋ HORZONTAL and VERTICAL TABULATION ⇀↽ ⇀↽ ⇀↽ ⇀↽ "\u001F" - "\u001C",
    0x1F - 0x1C, INFORMATION SEPARATOR ONE/FOUR
 
   Buttons: ⌘ Command, &#x2318; – &#8984; ⌥ Option, &#x2325; – &#8997; ⇧ Shift,
     &#x21E7; – &#8679; ⎋ ESC &#x238B; – &#9099; ⇪ Capslock &#x21ea; – &#8682;
     ⏎  Return &#x23ce; – &#9166; ⌫ Delete/Backspace, &#x232b; – &#9003;
     ⇥ Tab Arrow
 
   Spaces: ⇀ ↽ (en space), ⇀  ↽ (em space), ⇀ ↽ (Three-per-em space),
     ⇀ ↽ (Four per em-space), ⇀ ↽ (Six-per-em), ⇀ ↽ (Figure space),
     ⇀ ↽ (Punctuation space), ⇀ ↽ (Thin space), ⇀ ↽ (Hair space),
     ⇀ ​↽ (Zero width space), ⇀ ↽ (Narrow no-break space),
     ⇀ ↽ (Medium mathematical space), ⇀　↽ (Ideographic space), ⇀〿↽
     (Ideographic half-fill space). ␣ (Knuths' Constant.)
 
 *␣///}✂️ >> --<myShoebox>{Utf-8 Symbols} */

#pragma mark - Reverse Engineering and Export Tables (prompt> nm -help)

#define INLINED __attribute__((always_inline))
#define MACRO inline INLINED
// Macros for .cpp and .cxx files, e.g exclude symbols from an export table.
// INNER_STRUCT actually affects all methods/static data members in decorated.
#define INNER_STRUCT struct __attribute__((internal_linkage))
#define INNER_DATA static __attribute__((internal_linkage))
#define INNER_FUNCTION static __attribute__((internal_linkage))
#define STRINGIFY(x) #x
#define SECTION(seg,sc,id) __attribute__( (section("__" seg ",__ " sc " " id)))

#pragma mark - Intrinsic Integer Types

typedef unsigned char       uint8_t;
typedef signed char         int8_t;

#ifdef  __mips__
typedef unsigned long long  uint32_t;
typedef long long           int32_t;
typedef uint32_t            __builtin_uint_t;
typedef int32_t             __builtin_int_t;
#define TriboolUnknown 0xFFFFFFFF
#elif defined __x86_64__
typedef unsigned long long  uint64_t;
typedef long long           int64_t;
typedef unsigned int        uint32_t;
typedef int                 int32_t;
typedef uint64_t            __builtin_uint_t;
typedef int64_t             __builtin_int_t;
#define TriboolUnknown 0xFFFFFFFFFFFFFFFF
#endif

typedef unsigned short      uint16_t;
typedef short               int16_t;

#pragma mark - The Tribool

typedef __builtin_uint_t Tribool;

#pragma mark - Bitmasks in Hardcover (allocated from right to left)

#define BITMASK(type) enum : type
// See [Blackhat]>--<@c Intel.cpp> for details on 'bitmasks, well-specified'

#pragma mark - The ☞ Idiom

template<typename T>
struct FramingReference { T * ref_;
    FramingReference<T>() {}
    //~FramingReference() { delete ref_; }
    T * operator->() const { return ref_; }
    FramingReference(T * ref) { ref_ = ref; }
};

#define APPEND_PIMPL                                   \
      struct Implementation;                           \
      FramingReference<Implementation> impl_;

#define 😐 APPEND_PIMPL }

#pragma mark - The Essentials'

template <class... Ts> struct Tuple {}; template <class T, class... Ts>
  struct Tuple<T, Ts...> : Tuple<Ts...> { Tuple(T t, Ts... ts) : Tuple<Ts...>
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

template <typename T> struct Optional { union Option { T inner;
  __builtin_uint_t no; Option() {};  ~Option() {} } option; Optional(T inner)
  { option.inner = inner; kind = 0; } Optional(const Optional& other) { kind =
  other.kind; } Optional() { kind = 1; } static Optional no() { return
  Optional(); } T * query() const { if (kind != 1) return (T*)&option.inner;
  else return 0; } __builtin_uint_t kind; };

#ifdef  __mips__
typedef unsigned int size_t;
#elif defined __x86_64__
typedef unsigned long size_t;
#endif

namespace std { // The Standard Residual
  typedef ::size_t size_t; template<class T> class initializer_list {
  const T *beg; size_t sz; initializer_list(const T *b, size_t s) : beg(b),
  sz(s) {} public: typedef T value_type; typedef const T& reference; typedef
  const T& const_reference; typedef size_t size_type; typedef const T *
  iterator; typedef const T *const_iterator; initializer_list() : beg(0), sz(0)
  {} size_t size() const { return sz; } const T * begin() const { return beg; }
  const T * end() const { return beg + sz; } }; template<class T> inline const T
  *begin(std::initializer_list<T> il) { return il.begin(); } template<class T>
  inline const T *end(std::initializer_list<T> il) { return il.end(); } }

#pragma mark - Bit Manipulation

MACRO __builtin_uint_t 🔎(__builtin_uint_t var) {
    return *((__builtin_uint_t *)var); }

MACRO __builtin_uint_t&  🔧(__builtin_uint_t var) {
    return (__builtin_uint_t&)*(__builtin_uint_t *)var; }

MACRO __builtin_uint_t TrailingZeros(__builtin_uint_t x) { if (x == 0) { return
    8*sizeof(x); } __builtin_uint_t zeros = 0, mask = 1; while (!(x&mask)) {
        zeros++; mask<<=1; } return zeros; }

MACRO __builtin_uint_t MaskAndShift(__builtin_uint_t value, __builtin_uint_t
    mask) { __builtin_uint_t shift = TrailingZeros(mask); return (mask&value)
    >> shift; }

MACRO __builtin_uint_t 🔎MaskandShift(__builtin_uint_t var, __builtin_uint_t
    mask) { return MaskAndShift(🔎(var), mask); }

MACRO void 🔧(__builtin_uint_t var, __builtin_uint_t mask, __builtin_uint_t
      value) { __builtin_uint_t shift = TrailingZeros(mask);
    __builtin_uint_t secured = value & (mask>>shift);
    *(__builtin_uint_t *)var &= ~mask;
    *(__builtin_uint_t *)var |= secured<<shift; }

MACRO void 🔧Toggle(__builtin_uint_t var, __builtin_uint_t mask) {
    __builtin_uint_t shift = TrailingZeros(mask);
    __builtin_uint_t secured = mask>>shift;
    *(__builtin_uint_t *)var ^= secured<<shift; }

#pragma mark - Contexts for Switch and the '𝐶𝑜𝑟𝑟𝑒𝑐𝑡𝑙𝑦 Implemented Exception™' (i.e setjmp/longjmp)

#ifdef  __mips__
typedef uint32_t mips32_context[32]; // EPC, Status, r31-30, r28, r25-r1, hi, lo
typedef mips32_context jmp_buf2;  // ☜😐: ?
#elif defined __x86_64__
// rflags, rip, rbp, rsp, rbx, r12, r13, r14, r15... these are 8 bytes each
// mxcsr, fp control word, sigmask... these are 4 bytes each add 16 ints for
// future expansion needs.
typedef int64_t x86_64_full_context[(9 * 2) + 3 + 16];
// rflags, rip, rbp, rsp, these are 8 bytes each mxcsr, sigmask... these are 4
// bytes each add 16 ints for future expansion needs.
typedef int64_t x86_64_slim_context[(4 * 2) + 2 + 16];
typedef x86_64_full_context jmp_buf2;  // ☜😐: ?
#endif

#pragma mark - Exception Handling

struct Exception {
    const char *blurt;
    __builtin_uint_t firstTimestamp;
    double meanFreq; // Hz. TODO: Consider Vector<Tuple<Timestamp, ...
    __builtin_uint_t prevTimestamp;
    void *context;
    __builtin_uint_t bytesContext;
    const char *revisionCurrent;
};

extern "C" { int setjmp2(jmp_buf2 env); void longjmp2(jmp_buf2 env,
  __builtin_int_t val); }
extern jmp_buf2 _envBuffer;
#define BLURT(str) longjmp2(_envBuffer, (__builtin_uint_t)str);
#define MIRROR(str, closure)                            \
    longjmp(_envBuffer, (__builtin_uint_t)str,          \
      ^(Exception exception) { closure(exception); });
#define BLURTS /* Mandatory */
#define NEVERBLURTS /* Fortunately optional. */
#define FALLIBLE /* Unfortunately not mandatory while constructor blurts. */
#define TRY { jmp_buf2 _envBuffer; if (!setjmp(_envBuffer)) {
#define CATCH } else {
#define END_TRY } }
#define NOTBLURTING_BEGIN { TRY
#define NOTBLURTING_END(value) CATCH {} END_TRY; return value; }

#pragma mark - Macros Available when 'Git!'

// BuildPhasesRunscript: export sha1git=`git log -1 '--pretty=format:%h'`
// BuildSettingsOtherC(++)Flags -DSHA1GIT=$(sha1git)
#define PROGRESS_QUOTE_MACRO(x) STRINGIFY(x)
#define PROGRESS_VERSION PROGRESS_QUOTE_MACRO(SHORT_VERSION)
#define PROGRESS_VERSION_SHA1 PROGRESS_QUOTE_MACRO(SHA1GIT)
 #define BUILDINFO_COPYRIGHT_MESSAGE                                    \
   "Copyright " PROGRESS_START_YEAR "—" PROGRESS_BUILD_YEAR " "         \
     BUILDINFO_BRAND

#pragma mark - 😐: 🌱✔︎?

 #define SETUP_LOGGING(proj,subsystem)                                  \
    const char *myTestlogPath = proj "_" __DATE__ "_" __TIME__ "_rev"   \
        PROGRESS_VERSION_SHA1;
 #define Testlog _myTerminal /*_myTestlog*/
 #define Termlog _myTerminal

#pragma mark - Yet Another Unit Test Library (💾😐💰)

 #define UNITTEST(symbol) extern "C" void UnitTest_##symbol()
 #define Panic(log,s) { log << "'" << s << "'" << eol <<                \
   "Panicking at " << __FUNCTION__ << " in " << __FILE__ << ":" <<      \
   (__builtin_int_t)__LINE__ << " version " << PROGRESS_VERSION_SHA1    \
   << eol; exit(-1); }
 #define ENSURE(c,s) { if (!(c)) { Panic(Testlog, s); } }
 #define BEGIN_UNITTESTS const char *_myUnitTests[] = {
 #define ADD_UNITTEST(symbol) STRINGIFY(UnitTest_##symbol),
 #define END_UNITTESTS NULL };
 //#define } } /* __CONJECTURE: */

#pragma mark - 'prompt> egrep -r' Concurring a case of release 0.999 (👨‍⚕️😐🔎 ⇠)

#define FINAL //   ⃨ or DO_NOT_DESTABBILIZE
#define LONGTOOTH
#define WOBBLING
#define DUPLICATE(symbol)
#define BREACHED
#define DO_NOT_USE
#define EVOLVING
#define CONTEMPLATING_REMOVAL
#define SOON_REMOVED
#define FOCAL
#define Si_FOCAL
#define OPT_Si_FOCAL
#define SEQUENTIAL
#define SWIZZLE
#define ENCLAVED
#define DONT_REQUIRE_SIGNBIT
#define TRANSMOGRIFYING
#define µA(measured,envisioned)

#pragma mark - Pleasure Cycles

 #define OMEGA(ident) bool ident = false;
 #define OMEGASET(ident,ret) if (ident) { return (int)ret; }
 #define va_epilogue __builtin_va_end(arg);
 #define va_prologue(symbol)            \
   __builtin_va_list arg;               \
   __builtin_va_start(arg, symbol);

#ifdef __is_symbolic //  ☜😐: 🛎 ∨ ✂️
 #define ∧ &&
 #define ∨ ||
 #define ￢ !
 #define ↹ tab
 #define ¶ sep
 #define ↩︎ eol
 #define ■ 1
 #define □ 0
 #define ⬚ TriboolUnknown
 #define 𝛺(ident) bool ident = false;
 #define 𝛺☜(ident, ret) OMEGASET(ident, ret)
 #define ⊕ !IsEqual(a, b) // ≈
 #define ⟶(a, b)  (¬(a) ∨ (b))
 #define ⟷(a, b)  (⟶((a), (b)) ∧ ⟶((b), (a)))
 #define ⟵(a, b)  ((a) ∨ ¬(b))
 #define ≤ <= // ☜😐: //
 #define ≥ >=
 #define ⎨ NOTBLURTING_BEGIN { // i.e 𝐵old-braces
 #define ⎬ } NOTBLURTING_END
 #define ∅ NULL
#endif

#pragma mark - Runtime

 #ifdef  __mips__
    #define Halt for(;;);
 #elif defined __x86_64__
    #define Halt asm("hlt");
 #endif

 #if _DEBUG
    #define assert(x) Panic(Termlog, "Assert failed: "#x)
 #else
    #define assert(x)
 #endif

typedef __builtin_uint_t * WordAlignedRef; typedef uint8_t * ByteAlignedRef;
INLINED ByteAlignedRef CopyMemory8(ByteAlignedRef dst, ByteAlignedRef src,
  __builtin_uint_t bytes);
INLINED ByteAlignedRef ClearMemory8(ByteAlignedRef mem, __builtin_uint_t bytes);
INLINED ByteAlignedRef SetMemory8(ByteAlignedRef src, uint8_t val,
  __builtin_uint_t bytes);

extern "C" { void * malloc(size_t); void free(void *); int printf(const char
  *utf8Format, ...); uint8_t getch(); void putch(uint8_t data); int atexit(void
  (*func) (void)); void exit(int); }

extern "C" { extern const char *tab; extern const char *eol; extern const char
  *sep; }

#pragma mark - Occasionally Used `main` Exitcodes

 #define EXIT_OK                         0
 #define EXIT_ERROR_IN_COMMAND_LINE      1
 #define EXIT_ERROR_UNHANDLED_EXCEPTION  2
 #define EXIT_ERROR_WHILE_PARSING        3
 #define EXIT_ERROR_CONFIGURATION        4

#pragma mark - Fields of Capacitors

typedef __builtin_uint_t metaaddress; struct MemoryRegionDelegate;

template <typename T> struct SemanticPointer { T pointer; }; // ⬷ Non-arithmetic
// ⤤ Do not cast this type back to any other type of pointer

struct MemoryRegion {
    
    MemoryRegion(MemoryRegionDelegate * delegate = NULL);
    
    int incorporate(void *virtue, __builtin_int_t bytes, metaaddress loc);
    
    int inject(__builtin_int_t index, MemoryRegion sub, void *(^allocate)
      (__builtin_int_t bytes) = ^(__builtin_int_t b) { return malloc(b); } );
    
    int exclude(metaaddress start, __builtin_int_t bytes);
    
    int takeover(MemoryRegion virtue, metaaddress loc);
    
    SemanticPointer<void *> pointer(__builtin_int_t byte);
    
    __builtin_int_t bytes();
    
    __builtin_int_t blocks();
    
    void alsoAtDealloc(void (^deferral)()); // ☜😐: 🛵𝜆
    
#pragma mark (the unsigned) Mitigate
    
    Tuple<MemoryRegion, MemoryRegion> attach(metaaddress loc) const;
    
    Tuple<MemoryRegion, MemoryRegion> branch(metaaddress loc, void *(^allocate)
      (__builtin_int_t bytes)) const;
    
#pragma mark Little and Big Endians
    
    /**  TODO: Measure energy consumption while 𝑝𝑢𝑚𝑝𝑖𝑛' 𝑛𝑒𝑡𝑤𝑜𝑟𝑘/𝑛𝑎𝑡𝑖𝑣𝑒. */
    
    INLINED void toggleNetworkAndNative(void (^ping)(bool &stop), void
      (^completion)(__builtin_int_t bytes)) const; // REQ: O(1)
    
#pragma mark Iterator
    
    int forall(void (^block)(SemanticPointer<uint8_t *> isolative, bool first,
      bool last, __builtin_int_t index, signed short * step, bool& stop));
    
#pragma mark Conveniences
    
    static Optional<MemoryRegion> abduct(__builtin_int_t bytes,
      MemoryRegionDelegate *delegate = NULL, bool allowWrites = true,
      void *(^allocate)(__builtin_int_t bytes) = ^(__builtin_int_t bytes) {
        return malloc(bytes); });
    
    static Optional<MemoryRegion> reflect(const char * utf8Filepath,
      __builtin_int_t pagesOffset = 0, __builtin_int_t pagesLength = -1,
      MemoryRegionDelegate *delegate = NULL, bool allowWrites = false,
      void *(^allocate)(__builtin_int_t bytes) = ^(__builtin_int_t bytes) {
        return malloc(bytes); });
    
    Optional<MemoryRegion> clone(void *(^allocate)(__builtin_int_t bytes) = ^( // TODO: Move to base?
      __builtin_int_t bytes) { return malloc(bytes); } ) {
        Tuple<MemoryRegion, MemoryRegion> regions = branch(0, allocate);
        if (bytes() == 0 || get<1>(regions).bytes() != 0) { return Optional<
          MemoryRegion>(get<1>(regions)); } return Optional<MemoryRegion>::no();
    };
    
    void append(__builtin_int_t bytes, void *(^allocate)(__builtin_int_t bytes)
      = ^(__builtin_int_t bytes) { return malloc(bytes); });
    
😐;

struct MemoryRegionDelegate {
    virtual void first(MemoryRegion * region, SemanticPointer<void *> curr) = 0;
    virtual void next(MemoryRegion * region, SemanticPointer<void *> current, SemanticPointer<void *> later) = 0;
    virtual void prev(MemoryRegion * region, SemanticPointer<void *> current, SemanticPointer<void *> later) = 0;
    virtual void last(MemoryRegion * region, SemanticPointer<void *> curr) = 0;
};

__builtin_int_t SystemInfoPageSize();

#include <System.h>

#endif
