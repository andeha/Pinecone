//
//  ExceptionTests.cpp
//  Pinecone Unit Tests
//

#include <Pinecone.h>

#pragma mark Traditional C Exception

jmp_buf2 resumeHere;

void hello(void)
{
    Termlog << "Hey, I'm in hello" << eol;
    longjmp2(resumeHere, 1);
    // Code not executed
    Termlog << "Can't be reached here because I did longjmp" << eol;
}

UNITTEST(Exception_1)
{
    Termlog << "Beginning of Exception_1" << eol;
    
    if (setjmp2(resumeHere)) {
        Termlog << "After longjump, back in main" << eol;
    } else {
        Termlog << "setjmp returns first time" << eol;
        hello();
    }
    
    Termlog << "End of Exception_1" << eol;
}

#pragma mark - try-catch and Finally try-catch-finally Exception

INNER_DATA const char *descr = "Division with zero";

int foo(int n, int d)
{
    if (d == 0) { BLURT(descr); return 0; }
    else { return n/d; }
}

UNITTEST(Exception_2)
{
    Termlog << "Beginning of Exception_2" << eol;
    TRY
        Termlog << "Entering try" << eol;
        int x = foo(7, 3);
        Termlog << "Middle of try" << eol;
        x = foo(3, 0);
        Termlog << "End of try" << eol;
    CATCH
        Termlog << "In catch clause with e " << (__builtin_uint_t)__e
          << " and string " << (__builtin_uint_t)descr << eol;
    END_TRY
    Termlog << "End of Exception_2" << eol;
}

#pragma mark - No Runaway Exceptions

int fie(int arg) NEVERBLURTS
{
    int x = 7;
    TRY
        Termlog << "Entering try" << eol;
        x = foo(7, 3);
    CATCH
        Termlog << "In catch clause with e " << (__builtin_uint_t)__e
          << " and string " << (__builtin_uint_t)descr << eol;
    END_TRY
    return x;
}

UNITTEST(Exception_3)
{
    int y = fie(5); // We're guaranteed that fie is not passing exceptions
    Termlog << "y is " << (__builtin_int_t)y << eol;
}

