//
//  Pinecone.h or Pamphlet about 😐 💀,  ∧ ∨ 🎲(2)'  ⃨ in 🇵🇱≅
//  Pinecone
//

#ifndef __PINECONE_H
#define __PINECONE_H

typedef double(^Recursive)(double x, double n, bool(^)(double));
#define NULL 0

// Acceptable and Enclavable Platform Base ✁ until ✂️

/**

    Utf-8 Non-regulars: .*｟｠ ⃦ ('Combining double vertical stroke overlay' or
        'fat-pipe') ✚ ★ ‽ ⸺ \ 𐤟 (The phoenician word separator?) ↩︎ ↹
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
        a͟͞z͟͞ ⬷ 'Combining double-macaron'
         L̵ ⬷ L and 'Combining short stroke overlay'
         a⃝ ⬷ The letter 'a' + "COMBINING ENCLOSING CIRCLE'
         ℹ︎ ⬷ 'Information source'
         i⃝ ⬷ The letter 'i' + "COMBINING ENCLOSING CIRCLE'
          ⃒⃘ ⬷ 'Combining long vertical line' and 'ring overlay'
         c⃥ ⬷ 'Combining reverse solidus overlay'
          ⃫ ⬷ 'COMBINING LONG SOLIDUS OVERLAY'
 
   Footnotes, references and (enum.) lists: ¹₁²₂³₃⁴₄⁵₅⁶₆⁷₇⁸₈⁹₉⁰₀ •○◦・•⁃⦾⦿‣⁌⁍
 
                ╮  ╯ ╭ ╰ ╱ ╲ ╳     ┤ ┌ ├ ┼ ┘ ┐ ─ │ ┴ ┬    ╴╵╷╴

        Key   Value   ∃
       ┾━━━╈━━━━━━━━━┿━┽           ⌏  ⌎   ⌜  ⌝ ⌖  ⏚
       │k₁ ┃         │✓│           ⌍  ⌌   ⌞  ⌟ ‖
       └───┸─────────┴─┘
 
                ┌def┐
                │   │                     ╭─ Leaf 1 ──╮
           ─abc─┘─┐ ┘           ── Stem ──┤           ├── Again ──
                  └                       ╰─ Leaf 2 ──╯
 
    „ ⃨as illustrated below or above:‟
 
        ∞              ∞
        ⌠ 🔍😐         \̅
        ⎮ 𝘦^-𝘹 𝘥𝘹 ≅ √𝘹 + › ⁣⅟k² ≅ @w Sum[, ... ∈ R                             (0)
        ⌡              /͟
       -∞             k=1
 
        ⎡n₁₁     ⎤    ⎧ ⎫    ⎛   ⎞      ⸑
        ⎢        ⎥    ⎨ ⎬    ⎜   ⎟     ⎸    ⎲
        ⎣     nᵣᵥ⎦    ⎩ ⎭    ⎝   ⎠    ⎷    ⎳
 
    Further, consider:
 
 Dashes: ‒ Figure Dash, – En Dash, — Em Dash, ⁓ Swung Dash, ⸺ Two-em Dash,
    ⸻ Three-em Dash, 〰 Wavy Dash, - Hyphen Minus.
 
 Arrows: ⇽ ⇾ ⟲⟳ ↗︎↘︎↙︎↖︎ ⸔⸕ ⤡⤢ ⤺⤻ ↰↱↲↳ ↴ ↩︎ ↵  ⮐ ↹ ←↑→↓
    ↼ (Leftward harpoon with barb upwards) ↽↾↿⇀⇁⇂⇃⇄⇅⇆⇇⇈⇉⇊⇋⇌⇍⇏⇐⇑⇒⇓⇚⇛⇜⇝⇤⇥⇦⇧⇨
    ⇩⇪⇵⇶ ⎔ ➔➙➛➜➝➞➟➠⟰⟤⟥ ⤶ ⤷  ↔︎
    📲📩📈📉🔃➡︎⬅︎⬆︎⬇︎↩︎⤴︎⤵︎⤴⤵ (牮筏) ⬷ ⤐ (Leftwards two-headed triple dash arrow)
 
 Extensions: ⁌⁍ ⊸ ⫰ ⫱ ⿱⿳⿶  ⃦ a⃮ b⃯ a͍ (Combining left and right arrow below),
    a̫b̫c̫ ⬷ 'Combining inverted double arch below' a⃨b⃨c⃨ a⃩ a⃪ 
    1゚ (Combining Katakana Sound Mark)
    a ⃫b (Combining long double solidus overlay)
    aᷣ (Combining latin small letter R rotund)
    a⳯b⳰c⳱ (The Coptics)
     ˥ ˦ ˧ ˨ ˩ (Tone letters)
 
  Symbol String  Utf-8           Unicode Name
     ␜  "\u241C" 0xE2 0x90 0x9C SYMBOL FOR FILE SEPARATOR
     ␝  "\u241D" 0xE2 0x90 0x9D SYMBOL FOR GROUP SEPARATOR
     ␞  "\u241E" 0xE2 0x90 0x9E SYMBOL FOR RECORD SEPARATOR
     ␟  "\u241F" 0xE2 0x90 0x9F SYMBOL FOR UNIT SEPARATOR
 
  ␉ ␋ HORZONTAL and VERTICAL TABULATION
 
  ⇀↽ ⇀↽ ⇀↽ ⇀↽ "\u001F" - "\u001C", 0x1F - 0x1C, INFORMATION SEPARATOR ONE/FOUR
 
 Buttons: ⌘ Command, &#x2318; – &#8984; ⌥ Option, &#x2325; – &#8997; ⇧ Shift,
  &#x21E7; – &#8679; ⎋ ESC &#x238B; – &#9099; ⇪ Capslock &#x21ea; – &#8682;
  ⏎  Return &#x23ce; – &#9166; ⌫ Delete/Backspace, &#x232b; – &#9003;
  ⇥ Tab Arrow

 Spaces: ⇀ ↽ (en space), ⇀  ↽ (em space), ⇀ ↽ (Three-per-em space), ⇀ ↽ (Four 
 per em-space), ⇀ ↽ (Six-per-em), ⇀ ↽ (Figure space), ⇀ ↽ (Punctuation space), 
 ⇀ ↽ (Thin space), ⇀ ↽ (Hair space), ⇀ ​↽ (Zero width space), ⇀ ↽ (Narrow no-
 break space), ⇀ ↽ (Medium mathematical space), ⇀　↽ (Ideographic space), ⇀〿↽
 (Ideographic half-fill space). ␣ (Knuths' Constant.)
 
 *␣///}✂️ >> --<myShoebox>{Utf-8 Control Codes} */

 //#include <Block.h> // ☜😐: ¬𝘦^𝘹?

#pragma mark - Reverse Engineering and Export Tables (prompt> nm -help)

/**
 
    Macros for .h files; A @c MACRO is 𝑎𝑙𝑤𝑎𝑦𝑠 inlined and optionally exposes
    source details at compile-time.
 
 */

#if __has_attribute(always_inline)
  #define INLINED __attribute__((always_inline))
  #define MACRO inline INLINED
  #define __CONCAT(x,y) x ## y
  #define __STRING(x) #x
  #define ENCRYPTIC SUCEPTIBLE
  #define ENCLAVED /* ☜😐: extern TARGET_CPU_ARM64 ⟶ extern "ENCLAVED"? */
  /* extern "ANSI-C" #define ENCLAVED(e) // ⬷ Leaks enclave name
  extern "encrypted"? MyStruct&& foo() { return MyStruct { 0, 0 } };
  extern "naked" int foo() { return one+one; };
  extern "utf-8" struct "myTuple" { int a; int b; } foo() { return { 0, 0 }; }
  // ☜😐: "😀" ∧ (<it>{}</it>)❓ ⟶ ❌?
  #define UNENCLAVED */
#else
  #error "☝︎😐: 🔒!"
#endif

/**
  
    Macros for .cpp and .cxx files, e.g exclude symbols from an export table.
 
    INNER_CLASS affects all methods and static data members in the decorated.
 
 */

#if __has_attribute(internal_linkage)
  #define INNER_FUNCTION static __attribute__((internal_linkage))
  #define INNER_MACRO static MACRO __attribute__((internal_linkage))
  #define INNER_DATA static __attribute__((internal_linkage))
  #define INNER_STRUCT struct __attribute__((internal_linkage))
  #define SUCEPTIBLE __attribute__((internal_linkage))
  #define __IDSTRING(name,string) static const char name[] __used = string
  #define __COPYRIGHT(s) __IDSTRING(copyright,s)
  #define __GITID(s) __IDSTRING(gitid,s)
  #define __PROJECT_VERSION(s) __IDSTRING(project_version,s)
#else
   #error "☝︎😐: 🍩!
#endif

#pragma mark - Intrinsic Integer Types

 typedef unsigned char       uint8_t;
 typedef char                int8_t;

#ifdef  __mips__
 typedef unsigned int        uint32_t;
 typedef int                 int32_t;
 typedef uint32_t            __builtin_uint_t;
 typedef int32_t             __builtin_int_t;
 #define TriboolUnknown 0xFFFFFFFF
#elif __x86_64__
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
 #define x̱ 1 // I do not understand/have not tried this bit yet

#pragma mark - The ☞ Idiom

 template <typename T>
 struct FramingReference { T *ref_;
	 FramingReference<T>() {} 
     // ~FramingReference<T>() { delete ref_; }
     T * operator-> () const { return ref_; }
     FramingReference<T>(T *ref) { ref_ = ref; }};

 #define APPEND_PIMPL                                   \
    protected:                                          \
       struct Implementation;                           \
       FramingReference<Implementation> impl_;

 #define 😐 APPEND_PIMPL }

#pragma mark - Contexts for Switch and Setjmp/Longjmp

#ifdef  __mips__
  typedef uint32_t mips32_context[32]; // EPC, Status, r31-30, r28, r25-r1, hi, lo
  typedef mips32_context jmp_buf2;  // ☜😐: ?
#elif __x86_64__
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

extern __builtin_uint_t setjmp(jmp_buf2 env);
extern void longjmp(jmp_buf2 env, __builtin_uint_t val, void (^log)(Exception
    exception));
extern jmp_buf2 _envBuffer;

#define BLURT(str)                                      \
    longjmp(_envBuffer, (__builtin_uint_t)str,          \
        ^(Exception exception) {});

#define MIRROR(str, closure)                            \
    longjmp(_envBuffer, (__builtin_uint_t)str,          \
        ^(Exception exception) { closure(exception); });

#define BLURTS /* Mandatory */
#define NEVERBLURTS /* Optional. May or may not insert try catch and setjmp/longjmp guards. May very well be syntesized. */
#define FALLIBLE /* Mandatory when constructor blurts */
#define TRY { jmp_buf2 _envBuffer; if (!setjmp(_envBuffer)) {
#define CATCH } else {
#define END_TRY } }
#define NOTBLURTING_BEGIN { TRY
#define NOTBLURTING_END(value) CATCH {} END_TRY; return value; }

#pragma mark - Accidentially Misplaced Endians and the Blackhat Musterion
 #ifdef __is_symbolic // ☜😐: 🔅!
   #define ⟶¹(p) Dereference(p, 1)
   #define ⟶²(p) Dereference(p, 2)
   #define ⟶³(p) Dereference(p, 3)
   #define ⟶⁴(p) Dereference(p, 4)
   #define ⟶ⁿ(n,p) Dereference(p, n)
 #endif

#if __APPLE__ /* AAPL cons are often little-endian i.e non-network ordered. */
  #define ntohl(x)  __builtin_bswap32(x)
  #define htonl(x)  __builtin_bswap32(x)
  #define htonll(x) __builtin_bswap64(x)
  #define ntohll(x) __builtin_bswap64(x)
#endif

#if defined(__mips__) || defined(__x86_64__)
#define LITTLE_ENDIAN
#else
#error "P(😐☞) ≠ 0"
#endif

#pragma mark - Macros Available when 'Git!'

/*
 
    To get a fingerprint, unique to your currently checked in source files,
    from a revision handling system, run:
 
    ln -s ../../bin/post_commit.sh .git/hooks/post-commit
 
    from the directory where files such as .xcodeproj resides. The file
    post_commit.sh is run every time a Git commit occurs.

    The post_commit.sh script contains the following text:
 
    #!/bin/sh
    source `git rev-parse --git-dir`/../bin/create_revision.sh
 
    The create_revision.sh script contains the following text:
 
    #!/bin/sh
    rm -rf `git rev-parse --git-dir`/../tmp/Revision.h
    echo "#define SHORT_VERSION `git describe --abbrev=0 --tags`"       \
        > `git rev-parse --git-dir`/../Shared/Revision.h
    echo "#define SHA1_HASH `git log -1 '--pretty=format:%h'`"          \
        >> `git rev-parse --git-dir`/../Shared/Revision.h
 
    And flag the two scripts as executables with chmod +x.
 
    ...and create a directory 'Shared' inside your project.
 
    See [UnitTests]>--<main.cpp> for further details.

 */

 #define CPP_QUOTE_MACRO(x) __STRING(x)
 #define PROGRESS_VERSION CPP_QUOTE_MACRO(SHORT_VERSION)
 #define PROGRESS_VERSION_SHA1 CPP_QUOTE_MACRO(SHA1_HASH)
 #define BUILDINFO_COPYRIGHT_MESSAGE                                    \
   "Copyright " PROGRESS_START_YEAR "—" PROGRESS_BUILD_YEAR " "         \
   BUILDINFO_BRAND

 #pragma mark - 😐: 🌱✔︎?

 #define SETUP_LOGGING(proj,subsystem)                                  \
    const char *myTestlogPath = proj "_" __DATE__ "_" __TIME__ "_rev"   \
        PROGRESS_VERSION_SHA1;                                          \
    FileTerminal myTestlog = FileTerminal(&_theTerminal, myTestlogPath);\
    ConsoleTerminal _mySystemLog = ConsoleTerminal(proj, subsystem);
 #define SystemLog  _mySystemLog
 #define Testlog myTestlog
 #define Termlog _theTerminal
 #define TestlogPath myTestlogPath

#pragma mark - Yet Another Unit Test Library (💾😐💰)

 #define UNITTEST(symbol) void UnitTest_##symbol()
 #define Panic(log,s) { log << "'" << s << "'" << eol 				   \
    << "Panicking at " __STRING(__FUNCTION__) __STRING(__FILE__) ":"   \
    __STRING(__LINE__ ) "in" PROGRESS_VERSION_SHA1 << eol; 		       \
    exit(-1); }
 #define ENSURE(c,s) { if (!(c)) { Panic(Testlog, s); } }
 #define BEGIN_UNITTESTS const char *_myUnitTests[] = {
 #define ADD_UNITTEST(symbol) __STRING(UnitTest_##symbol),
 #define END_UNITTESTS NULL };
 //#define } } /* __CONJECTURE: */
			
#pragma mark - 'prompt> egrep -r' Concurring a case of release 0.999 (👨‍⚕️😐🔎 ⇠)

 #define CONTEMPLATING_REMOVAL
#if __has_attribute(deprecated)
  #define SOON_REMOVED
#else
  #define SOON_REMOVED
#endif
 #define CEASED_TO_BE_PRONONCED
 #define BREACHED
 #define DO_NOT_USE
 #define EVOLVING
 #define LONGTOOTH
 #define WOBBLING
 #define DUPLICATE(symbol)
 #define FINAL //   ⃨ or DO_NOT_DESTABBILIZE
 #define FOCAL
 #define Si_FOCAL
 #define OPT_Si_FOCAL
 #define SEQUENTIAL
 #define SWIZZLE
 #define SHORTFORM
 #define DONT_REQUIRE_SIGNBIT
 #define REQUIRES_SIGNBIT
 #define SECTION(seg,sc,id) __attribute__( (section("__" seg ",__ " sc " " id)))
 #define TRANSMOGRIFYING

 #if _DEBUG
   #define assert(x) Panic(Termlog, "Assert failed: "#x)
 #else
   #define assert(x) 
 #endif
 
 #define NIY for(;;); "😐: No."; // ☜😐: 🎬 { llvm, gcc } ∧ cl?

#pragma mark - Overridables for main.cpp vs. Occasionally used main() exitcodes

/**
 
    Include the following redefinitions in your main.cpp:

    #define BUILDINFO_BRAND "My Project Name"
    #define PROGRESS_START_YEAR __STRING(1990)
    #define PROGRESS_BUILD_YEAR __STRING(2017)
 
 */

 #define EXIT_OK                         0
 #define EXIT_ERROR_IN_COMMAND_LINE      1
 #define EXIT_ERROR_UNHANDLED_EXCEPTION  2
 #define EXIT_ERROR_WHILE_PARSING        3
 #define EXIT_ERROR_CONFIGURATION        4
	
#pragma mark - Pleasure Cycles

 #define OMEGA(ident) bool ident = false;
 #define OMEGASET(ident,ret) if (ident) { return (int)ret; }
 #define va_epilogue __builtin_va_end(arg);
 #define va_prologue(symbol)             \
    __builtin_va_list arg;               \
    __builtin_va_start(arg, symbol);

#pragma mark - Runtime

#ifdef  __mips__
#define Halt for(;;);
#elif __x86_64__
#define Halt asm("hlt");
#endif

#pragma mark - Bit Manipulations

 MACRO __builtin_uint_t TrailingZeros(__builtin_uint_t x) {
    if (x == 0) { return 8*sizeof(x); }
    __builtin_uint_t zeros = 0, mask = 1;
    while (!(x&mask)) { zeros++; mask<<=1; }
    return zeros; }

 MACRO void
 🔧(__builtin_uint_t var, __builtin_uint_t mask, __builtin_uint_t value) {
     __builtin_uint_t shift = TrailingZeros(mask);
     __builtin_uint_t secured = value & (mask>>shift);
     *(__builtin_uint_t *)var &= ~mask;
     *(__builtin_uint_t *)var |= secured<<shift; }

 MACRO __builtin_uint_t&  🔧(__builtin_uint_t var) {
    return (__builtin_uint_t&)*(__builtin_uint_t *)var; }

 MACRO void
 🔧Toggle(__builtin_uint_t var, __builtin_uint_t msk, __builtin_uint_t val) {
     __builtin_uint_t shift = TrailingZeros(msk);
     __builtin_uint_t secured = val & (msk>>shift);
     *(__builtin_uint_t *)var ^= secured<<shift; }

MACRO __builtin_uint_t MaskAndShift(__builtin_uint_t value, __builtin_uint_t mask) {
	 __builtin_uint_t shift = TrailingZeros(mask);
	 return (mask&value) >> shift; }

//#define BITS_EQUAL(val1,mask,val2) MaskAndShift(val1, mask)==(val2)
//#define BITS_EQUAL(var,mask,val) MaskAndShift(🔎(var), mask)==(val)

MACRO __builtin_uint_t 🔎(__builtin_uint_t var) {
	 return *((__builtin_uint_t *)var); }

MACRO __builtin_uint_t 🔎MaskandShift(__builtin_uint_t var, __builtin_uint_t mask) {
	 return MaskAndShift(🔎(var), mask); }

#ifdef  __mips__
#include <PineconeLite/System.h>
#elif __x86_64__
#include <FEFoundation/System.h>
#endif

#pragma mark - Personal Preferalia/Preferalium

 /* ❌⭕️⚰️🎈🎎🗞📖✂️🔍🔎📆🛑🅰️🅱️🆎🆔❗️❓🔅 🔋〽️🎲 🔮 🔑 🚪 🛎❗️❓🚸 */

#ifdef __is_symbolic
  #define ∧ &&
  #define ∨ ||
  //#define ¬ !   //   ↰ Fe₊
  #define ￢ !  //  ☜😐✂️: [␣]
  #define ⊕ !IsEqual(a, b) // ≈
  #define ≤ <= // ☜😐: //?
  #define ≥ >=
  #define ∅ NULL
  #define ⟶(a, b)  (¬(a) ∨ (b))
  #define ⟷(a, b)  (⟶((a), (b)) ∧ ⟶((b), (a)))
  #define ⟵(a, b)  ((a) ∨ ¬(b))
  #define ■ 1
  #define □ 0
  #define ⬚ TriboolUnknown
  #define ∥
  #define ⦑
  #define ⦒
  #define ↹ tab
  #define ¶ sep
  #define ↩︎ eol
  #define 𝛺(ident) bool ident = false;
  #define 𝛺☜(ident, ret) OMEGASET(ident, ret)
  #define ⎨ NOTBLURTING_BEGIN {
  #define ⎬ } NOTBLURTING_END

  #ifdef __is_integrative // ☜😐: !
    // The following escapes does not exist in traditional formal languages:
    #define ✁ ✄{  // may be formal, informal or inexplanatorial
    #define ✃ '*'///}✂️
    #define ✃❯❯ ✃ >>
    #define ✃❯ ✃ >
    #define ✎ patchBegin
    #define ✍ patchEndAndPath
    #define ✒︎ oldText
    #define ✏︎ patchDivider
    #define ✑ newTextAndPath

#endif
#endif // ☜😐: ?
#endif
