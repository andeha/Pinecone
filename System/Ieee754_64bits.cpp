//
//  Ieee754_2008.cpp
//  Pinecone
//

#include <Pinecone.h>
#include <Additions/Helpers.h>
#ifdef __x86_64__
#include <x86intrin.h>
#endif

#pragma mark - Converting the IEEE 754-2008 base-2 to a Textual Representation

enum { bignum_prec = 157, magic_offset = 2112, origin = 37 };

typedef uint32_t _tetra;
typedef struct { _tetra h, l; } _octa;

typedef INNER_STRUCT {
    int a;
    int b;
    _tetra dat[bignum_prec];
} bignum;

INNER_FUNCTION
void
print_float(
    _octa x,
    void (^digits)(bool neg, int e, const char *s),
    void (^zero)(), void (^inf)(), void (^nan)()
) // MMMIX-ARITH § 54-67
{
    _octa f,g;
    int e;
    int j,k;
    bignum ff, gg;
    bignum tt;
    char s[18];
    char *p;
    bool neg = false;
    
    auto bignum_times_ten = ^(bignum *f) {
        _tetra *p, *q; _tetra x, carry;
        for (p = &f->dat[f->b], q = &f->dat[f->a], carry = 0; p >= q; p--) {
            x = *p*10 + carry;
            *p = x & 0xfffffff;
            carry = x>>28;
        }
        *p = carry;
        if (carry) f->a--;
        if (f->dat[f->b] == 0 && f->b > f->a) f->b--;
    };
    
    auto bignum_compare = ^(bignum *f, bignum *g) {
        _tetra *p, *pp, *q, *qq;
        if (f->a != g->a) return f->a > g->a ? -1 : 1;
        pp = &f->dat[f->b]; qq = &g->dat[g->b];
        for (p = &f->dat[f->a], q=&g->dat[g->a]; p <= pp; p++, q++) {
            if (*p != *q) return *p < *q? -1 : 1;
            if (q == qq) return p < pp ? 1 : 0;
        }
        return -1;
    };
    
    auto bignum_dec = ^(bignum *f, bignum *g, _tetra r) {
        _tetra *p, *q, *qq;
        int x, borrow;
        while (g->b > f->b) f->dat[++f->b] = 0;
        qq = &g->dat[g->a];
        for (p = &f->dat[g->b], q = &g->dat[g->b], borrow = 0; q >= qq; p--, q--) {
            x = *p - *q - borrow;
            if (x >= 0) { borrow = 0; *p = x; }
            else { borrow = 1; *p = x + r; }
        }
        for (; borrow; p--)
            if (*p) { borrow = 0; *p = *p - 1; }
            else *p = r - 1;
        while (f->dat[f->a] == 0) {
            if (f->a == f->b) { /* the result is zero */
                f->a = f->b = bignum_prec - 1; f->dat[bignum_prec - 1] = 0;
                return;
            }
            f->a++;
        }
        while (f->dat[f->b] == 0) f->b--;
    };
    
    auto incr = ^(_octa y, int delta) { _octa x;
        x.h = y.h; x.l = y.l + delta;
        if (delta >= 0) { if (x.l < y.l) x.h++; }
        else if (x.l > y.l) x.h--;
        return x;
    };
    
    auto shift_left = ^(_octa y, int s) {
        while (s >= 32) { y.h = y.l; y.l = 0; s -= 32; }
        if (s) { _tetra yhl = y.h << s, ylh = y.l >> (32-s);
            y.h = yhl + ylh; y.l <<= s;
        }
        return y;
    };
    
    auto shift_right = ^(_octa y, int s, int u) {
        while (s >= 32) { y.l = y.h; y.h = (u ? 0 : -(y.h>>31)); s -= 32; }
        if (s) { _tetra yhl = y.h << (32 - s), ylh = y.l >> s;
            y.h = (u ? 0 : (-(y.h>>31))<<(32-s)) + (y.h >> s); y.l = yhl + ylh;
        }
        return y;
    };
    
    neg = x.h & (uint32_t)0x80000000;
    
    f = shift_left(x, 1);
    e = f.h >> 21;
    f.h &= 0x1fffff;
    if (!f.h && !f.l) {
        if (!e) { zero(); return; }
        if (e == 0x7ff) { inf(); return; }
        e--;
        f.h = 0x3fffff; f.l = 0xffffffff;
        g.h = 0x400000; g.l = 2;
    } else {
        g = incr(f, 1);
        f = incr(f, -1);
        if (!e) e = 1; /* subnormal */
        else if (e == 0x7ff) {
            nan();
            if (g.h == 0x100000 && g.l == 1) return;
            e = 0x3ff;
        } else f.h |= 0x200000; g.h |= 0x200000;
    }
    
    k = (magic_offset - e) / 28;
    ff.dat[k-1] = shift_right(f, magic_offset+28-e-28*k,1).l & 0xfffffff;
    gg.dat[k-1] = shift_right(g, magic_offset+28-e-28*k,1).l & 0xfffffff;
    ff.dat[k]   = shift_right(f, magic_offset-e-28*k,1).l    & 0xfffffff;
    gg.dat[k]   = shift_right(g, magic_offset-e-28*k,1).l    & 0xfffffff;
    ff.dat[k+1] = shift_left(f, e+28*k-(magic_offset-28)).l  & 0xfffffff;
    gg.dat[k+1] = shift_left(g, e+28*k-(magic_offset-28)).l  & 0xfffffff;
    ff.a = (ff.dat[k-1] ? k-1 : k);
    ff.b = (ff.dat[k+1] ? k+1 : k);
    gg.a = (gg.dat[k-1] ? k-1 : k);
    gg.b = (gg.dat[k+1] ? k+1 : k);
    
    if (e > 0x401) {
        int open = x.l & 1;
        tt.dat[origin] = 10;
        tt.a = tt.b = origin;
        for (e=1;bignum_compare(&gg,&tt)>=open;e++)
            bignum_times_ten(&tt);
        p=s;
        while (1) {
            bignum_times_ten(&ff);
            bignum_times_ten(&gg);
            for (j = '0'; bignum_compare(&ff, &tt) >= 0; j++) {
                bignum_dec(&ff, &tt, 0x10000000);
                bignum_dec(&gg, &tt, 0x10000000); }
            if (bignum_compare(&gg, &tt) >= open) break;
            *p++ = j;
            if (ff.a == bignum_prec - 1 && !open)
                goto done;
        }
        for (k = j; bignum_compare(&gg, &tt) >= open; k++) bignum_dec(&gg, &tt, 0x10000000);
        *p++ = (j + 1 + k) >> 1;
    done:;
    }
    else {
        if (ff.a > origin) ff.dat[origin] = 0;
        for (e = 1, p = s; gg.a > origin || ff.dat[origin] == gg.dat[origin]; ) {
            if (gg.a > origin) e--;
            else { *p++ = ff.dat[origin] + '0'; ff.dat[origin] = 0; gg.dat[origin] = 0; }
            bignum_times_ten(&ff);
            bignum_times_ten(&gg);
        }
        *p++ = ((ff.dat[origin]+1+gg.dat[origin])>>1)+'0';
    }
    
    *p = '\0';
    
    digits(neg, e, s);
}

void
CastToText(
    double value,
    void (^digits)(bool neg, int e, const char *s),
    void (^zero)(), void (^inf)(), void (^nan)()
)
{
    octa y; y.base2 = value;
    _octa x; x.h = y.little_endian.mst; x.l = y.little_endian.lst;
    print_float(x, digits, zero, inf, nan);
}

INNER_DATA double const pi=3.1415926535897932384626433;
INNER_DATA double const twopi=2.0*pi;
INNER_DATA double const two_over_pi= 2.0/pi;
INNER_DATA double const halfpi=pi/2.0;
INNER_DATA double const sixthpi=pi/6.0;
INNER_DATA double const tansixthpi=0.57735026918962576450914878050195745564760175127013;

double
fmod(
     double x,
     double y
)
{
#ifdef __llvm__
    return __builtin_fmodf(x, y);
#else
    double fract; modf(x/y, &fract); for (;;); return fract;
#endif
}

FOCAL
double
arctan(
    double x
)
{
    auto atan_66s = ^(double x) { // Accurate to about 6.6 decimal digits over the range [0, pi/12]
        const double c1 = 1.6867629106, c2 = 0.4378497304, c3 = 1.6867633134;
        double x2 = x*x;
        return (x * (c1 + x2*c2)/(c3 + x2)); };
    
    bool neg = false; bool inv = false; bool reg = false;
    
    if (x < 0) { x = -x; neg = true; }
    
    if (x > 1.0) { x = 1.0/x; inv = true; }
    
    double const tantwelfthpi = 0.26794919243112270647255365849412763305719474618962;
    
    if (x > tantwelfthpi) {
        x = (x - tansixthpi) / (1 + tansixthpi*x); // reduce arg to under tan(pi/12)
        reg = true;
    }
    
    double y = atan_66s(x);
    
    if (reg) y += sixthpi;
    if (inv) y = halfpi - y;
    if (neg) y = -y;
    
    return y;
}

INNER_FUNCTION
float cos_32(float x)
{
    auto cos_32s = ^(float x) {
        const float c1 = 0.99940307, c2 = -0.49558072, c3 = 0.03679168;
        float x2 = x*x;
        return (c1 + x2*(c2 + c3 * x2));
    };
    
    x = fmod(x, twopi);                     // Get rid of values > 2*pi
    
    if (x < 0) x = -x;                      // cos(-x) = cos(x)
    
    int quad = int(x * two_over_pi);        // Get quadrant # (0 to 3) we're in
    
    switch (quad) {
        case 0: return  cos_32s(x);
        case 1: return -cos_32s(pi-x);
        case 2: return -cos_32s(x-pi);
        case 3: return  cos_32s(twopi-x);
    }
    
    return IEEE754BASE2_32BIT_QNAN;
}

INNER_FUNCTION float sin_32(float x) { return cos_32(halfpi-x); }

FOCAL
void
sincos(
    double x,
    double *s,
    double *c
)
{ *s = sin_32(x); *c = cos_32(x); }

FOCAL
double
pinecone_floor(
    double x
)
{
    __m128d value = { x, x };
    __m128d integer = _mm_round_pd(value, _MM_FROUND_FLOOR);
    // octa o; o.base2 = integer[0];
    return integer[0];
}

#pragma mark - Sequential Non-Axiomatics

double
modf(
    double x,
    double *iptr
)
{
    __m128d value = { x, x };
    __m128d integer = _mm_round_pd(value, _MM_FROUND_TRUNC);
    __m128d fraction = _mm_sub_pd(value, integer);
    *iptr = fraction[0];
    return integer[0];
}

double
exp(
    double x
)
{
    const float exp_cst1 = 2139095040.f;
    const float exp_cst2 = 0.f;
    union { int32_t i; float f; } xu, xu2;
    float val2, val3, val4, b;
    int32_t val4i;
    val2 = 12102203.1615614f*x+1065353216.f;
    val3 = val2 < exp_cst1 ? val2 : exp_cst1;
    val4 = val3 > exp_cst2 ? val3 : exp_cst2;
    val4i = (int32_t) val4;
    xu.i = val4i & 0x7F800000;
    xu2.i = (val4i & 0x7FFFFF) | 0x3F800000;
    b = xu2.f;
    
    /* Generated in Sollya with:
     > f=remez(1-x*exp(-(x-1)*log(2)),
     [|(x-1)*(x-2), (x-1)*(x-2)*x, (x-1)*(x-2)*x*x|],
     [1.000001,1.999999], exp(-(x-1)*log(2)));
     > plot(exp((x-1)*log(2))/(f+x)-1, [1,2]);
     > f+x;
     */
    return
    xu.f * (0.509871020343597804469416f + b *
            (0.312146713032169896138863f + b *
             (0.166617139319965966118107f + b *
              (-2.19061993049215080032874e-3f + b *
               1.3555747234758484073940937e-2f))));
}

double
ln(
   double val
)
{
    union { float f; int32_t i; } valu;
    float exp, addcst, x;
    valu.f = val;
    exp = valu.i >> 23;
    /* 89.970756366f = 127 * log(2) - constant term of polynomial */
    if (val <= 0) return IEEE754BASE2_64BIT_NINF;
    addcst = /* val > 0 ? */ -89.970756366f /* : -(float)INFINITY */ ;
    valu.i = (valu.i & 0x7FFFFF) | 0x3F800000;
    x = valu.f;
    
    /* Generated in Sollya using:
     > f = remez(log(x)-(x-1)*log(2),
     [|1,(x-1)*(x-2), (x-1)*(x-2)*x, (x-1)*(x-2)*x*x,
     (x-1)*(x-2)*x*x*x|], [1,2], 1, 1e-8);
     > plot(f+(x-1)*log(2)-log(x), [1,2]);
     > f+(x-1)*log(2)
     */
    return
    x * (3.529304993f + x * (-2.461222105f +
        x * (1.130626167f + x * (-0.288739945f +
            x * 3.110401639e-2f))))
    + (addcst + 0.69314718055995f*exp);
}

float rsqrt(float x)
{
#ifdef __mips__
    float xhalf = 0.5f * x;
    int i = *(int*)&x;            // store floating-point bits in integer
    i = 0x5f3759df - (i >> 1);    // initial guess for Newton's method
    x = *(float*)&i;              // convert new bits into float
    x = x*(1.5f - xhalf*x*x);     // One round of Newton's method
    return x;
#elif defined __x86_64__
    __m128 value = { x, x, x, x };
    __m128 result = _mm_rsqrt_ps(value);
    return result[0];
#endif
}

double
sqrt(
    double x
)
{
    __m128d value = { x, x };
    __m128d result = _mm_sqrt_pd(value); // on some architectures SQRTPD is twice as slow as SQRTSD
    return result[0];
}
