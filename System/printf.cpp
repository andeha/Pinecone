//
//  printf.cpp 
//  Pinecone
//

#include <Pinecone.h>

// #define SYMBOL_IS_CHAR_NOT_VARIABLE_BYTE_COUNT_UTF8

INNER_FUNCTION
void
streamout_char(
    OutputStream *stream,
    char c
)
{ stream->write((uint8_t *)&c, (__builtin_uint_t)1); }

INNER_FUNCTION
int
streamout_eightbit(
    OutputStream *stream,
    const char *s
)
{ int printedExcept0 = 0;
    while (char c = *s++) { streamout_char(stream, c); printedExcept0++; }
    return printedExcept0;
}

#ifdef SYMBOL_IS_CHAR_NOT_VARIABLE_BYTE_COUNT_UTF8

INNER_FUNCTION
int
vfprintf_eightbit(
    OutputStream *stream,
    const char *format,
    __builtin_va_list arg
)
{ __block int printedBytesExcept0 = 0;
    while (char c = *format++) {
        if (c != '%' || (c = *format++) == '%') { streamout_char(stream, c); printedBytesExcept0++; }
        else { switch (c) {
            case 'd': {
                const __builtin_int_t d = __builtin_va_arg(arg, __builtin_int_t);
                Base(d, 10, 0, ^(char s) { streamout_char(stream, s); printedBytesExcept0++; });
                break; }
            case 'x': {
                const __builtin_uint_t x = __builtin_va_arg(arg, __builtin_uint_t);
                Base(x, 16,
#ifdef __x86_64__
                     16
#elif __mips__
                     8
#endif
                , ^(char s) { streamout_char(stream, s); printedBytesExcept0++; });
                break; }
            case 'b': {
                const __builtin_uint_t b = __builtin_va_arg(arg, __builtin_uint_t);
                Base(b, 2,
#ifdef __x86_64__
                     64
#elif __mips__
                     32
#endif
                , ^(char s) { streamout_char(stream, s); printedBytesExcept0++; });
                break; }
            case 's': {
                const char *s = __builtin_va_arg(arg, const char *);
                printedBytesExcept0 += streamout_eightbit(stream, s);
                break; }
#ifdef VARIABLE_BYTE_COUNT_UTF8
            case 'S': {
                const char32_t *s = __builtin_va_arg(arg, const char32_t *);
                printedBytesExcept0 += streamout_unicodes(stream, s, -1);
                break; }
#endif
        } }
    }
    return printedBytesExcept0;
}

FOCAL extern "C"
int printf(const char *eightBitFormat, ...)
{ // if inited { initUART(); }
    int result;
    va_prologue(utf8Format)
    result = vfprintf_eightbit(eightBitFormat, arg);
    va_epilogue
    return result;
}

#else

INNER_FUNCTION
int
streamout_unicode(
    OutputStream *stream,
    char32_t u
)
{ __block int bytesStreamed = 0;
    UnicodeToUtf8(u, ^(const char *p, int bytes) { // On a Microchip PIC32, the fifo is 4 or 8 levels deep.
        bytesStreamed += stream->write((uint8_t *)p, bytes);
    });
    return bytesStreamed;
}

INNER_FUNCTION
int // bytes, symbols
streamout_unicodes(
    OutputStream *stream,
    const char32_t *s,
    __builtin_int_t count
)
{
    int symbolsExcept0 = 0;
    while (char32_t u = *s++) { streamout_unicode(stream, u); symbolsExcept0++; count--; }
    return symbolsExcept0;
}

int // Tuple<int, int, int> i.e user-percieved characters, unicodes, Utf-8.
vfprintf_unicode(
    OutputStream *stream,
    const char32_t *oneblockFormat,
    __builtin_va_list arg
)
{
    __block int printedSymbolsExcept0 = 0;
    while (char32_t c = *oneblockFormat++) {
        if (c != '%' || (c = *oneblockFormat++) == '%') { streamout_unicode(stream, c); printedSymbolsExcept0++; }
        else { switch (c) {
            case 'd': {
                const __builtin_int_t d = __builtin_va_arg(arg, __builtin_int_t);
                Base(d, 10, 0, ^(char s) { streamout_char(stream, s); printedSymbolsExcept0++; });
                break; }
            case 'x': {
                const __builtin_uint_t x = __builtin_va_arg(arg, __builtin_uint_t);
                Base(x, 16,
#ifdef __x86_64__
                16
#elif __mips__
                8
#endif
                , ^(char s) { streamout_char(stream, s); printedSymbolsExcept0++; });
                break; }
            case 'b': {
                const __builtin_uint_t b = __builtin_va_arg(arg, __builtin_uint_t);
                Base(b, 2,
#ifdef __x86_64__
                64
#elif __mips__
                32
#endif
                , ^(char s) { streamout_char(stream, s); printedSymbolsExcept0++; });
                break; }
            case 's': {
                const char *s = __builtin_va_arg(arg, const char *);
                printedSymbolsExcept0 += streamout_eightbit(stream, s);
                break; }
            case 'S': {
                const char32_t *s = __builtin_va_arg(arg, const char32_t *);
                printedSymbolsExcept0 += streamout_unicodes(stream, s, -1);
                break; }
        } }
    }
    return printedSymbolsExcept0;
}

int
vfprintf_utf8(
    OutputStream *stream,
    const char *utf8Format,
    __builtin_va_list arg
)
{
    String s = StringLiteral(utf8Format);
    int result = vfprintf_unicode(stream, (const char32_t *)(*s)->pointer(0).pointer, arg);
    return result;
}

FOCAL extern "C"
int printf(const char *utf8Format, ...)
{
    int result;
    va_prologue(utf8Format)
    result = vfprintf_utf8(_myTerminal.outputStream(), utf8Format, arg);
    va_epilogue
    return result;
}

#endif

#pragma mark - A Swift Experiment

int print(const char *utf8Format,__builtin_uint_t (^write)(uint8_t *p,
  __builtin_uint_t bytes) = ^(uint8_t *p, __builtin_uint_t bytes) {
  __builtin_uint_t i; for (i = 0; i < bytes; i++) putch(*(p + i)); return i; });

int
print(
    const char *utf8Format,
    __builtin_uint_t (^write)(uint8_t *p, __builtin_uint_t bytes)
)
{
    double value = 17.0;
    void * ebp = __builtin_frame_address(0);
    void * object = (void *)0x12341234;
    // const char * leaf = "attr1";
    // if (RegionFor(object, leaf, ^(void *loc, __builtin_int_t bytes) {
    // })) { return 0; }
    return -1;
}
