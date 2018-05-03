//
//  RoundingTests.cpp
//  Pinecone Unit Tests
//

#include <Pinecone.h>
#include <stdio.h>

void CForm(double x, void (^touchbase)(char32_t c))
{
    CastToText(x, ^(bool neg, int e, const char *s) {
        
        auto strlen = ^(const char *str) {
            const char *s;
            for (s = str; *s; ++s);
            return s - str;
        };
        
        if (neg) touchbase('-');
        
        int len = (int)strlen(s);
        
        if (e > 17 || e < len - 17) {
            fprintf(stdout, "%c%s%se%d", s[0], (s[1] ? ".": ""), s+1, e-1); }
        else if (e < 0) {
            fprintf(stdout, ".%0*d%s", -e, 0, s); }
        else if (strlen(s) >= e) {
            fprintf(stdout, "%.*s.%s", e, s, s+e); }
        else {
            fprintf(stdout, "%s%0*d.", s, e - len, 0); }
    },
    ^() { touchbase('0'); },
    ^() { touchbase(U'∞'); },
    ^() { touchbase('N'); touchbase('a'); touchbase('N'); });
}

void MonetaryForm(double x, void (^touchbase)(char32_t c))
{
    CastToText(x, ^(bool neg, int e, const char *s) {
        
        auto strlen = ^(const char *str) {
            const char *s;
            for (s = str; *s; ++s);
            return s - str;
        };
        
        if (neg) touchbase('-');
        
        int len = (int)strlen(s);
        
        if (e > 17 || e < len - 17) {
            touchbase(s[0]);
            if (s[1]) touchbase('.');
            unsigned i = 1;
            while (s[i]) { touchbase(s[i]); i++; }
            touchbase('e');
            Base((__builtin_int_t)(e - 1), 10, 0, ^(char c) { touchbase((char32_t)c); });
        } else if (e <= 0) {
            touchbase('0');
            touchbase('.');
            touchbase(s[0]);
            touchbase(s[1] ? s[1] : '0');
        } else if (len >= e) {
            unsigned i;
            for (i = 0; i < e; i++) { touchbase(s[i]); }
            touchbase('.');
            if (s[i]) {
                touchbase(s[i]);
                i++;
                if (s[i]) { touchbase(s[i]); } else { touchbase('0'); }
            } else { touchbase('0'); touchbase('0'); }
        } else {
            unsigned i = 0;
            while (s[i]) { touchbase(s[i]); i++; }
        } // TODO: Implement rounding
        
    },
    ^() { touchbase('0'); touchbase('.'); touchbase('0'); touchbase('0'); },
    ^() { touchbase(U'∞'); },
    ^() { touchbase('N'); touchbase('a'); touchbase('N'); });
}

UNITTEST(Cast_1)
{ double x;
    x = 3.141592654;
    CForm(x, ^(char32_t c) { Termlog << c; }); Termlog << eol;
    MonetaryForm(x, ^(char32_t c) { Termlog << c; }); Termlog << eol;
    x = 1024.;
    CForm(x, ^(char32_t c) { Termlog << c; }); Termlog << eol;
    MonetaryForm(x, ^(char32_t c) { Termlog << c; }); Termlog << eol;
    x = .1024;
    CForm(x, ^(char32_t c) { Termlog << c; }); Termlog << eol;
    MonetaryForm(x, ^(char32_t c) { Termlog << c; }); Termlog << eol;
    x = .1450;
    CForm(x, ^(char32_t c) { Termlog << c; }); Termlog << eol;
    MonetaryForm(x, ^(char32_t c) { Termlog << c; }); Termlog << eol;
    x = Naturals::π;
    CForm(x, ^(char32_t c) { Termlog << c; }); Termlog << eol;
    MonetaryForm(x, ^(char32_t c) { Termlog << c; }); Termlog << eol;
    x = 1.65e18;
    CForm(x, ^(char32_t c) { Termlog << c; }); Termlog << eol;
    MonetaryForm(x, ^(char32_t c) { Termlog << c; }); Termlog << eol;
    x = 1.65e-18;
    CForm(x, ^(char32_t c) { Termlog << c; }); Termlog << eol;
    MonetaryForm(x, ^(char32_t c) { Termlog << c; }); Termlog << eol;
}
