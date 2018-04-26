//
//  main.cpp
//  Pinecone Unit Tests
//

#include <PineconeNucleus.h>
#include <System/macOS/AppSymbols.h>

#define BUILDINFO_BRAND "Pinecone Society"
#define PROGRESS_START_YEAR __STRING(2016)
#define PROGRESS_BUILD_YEAR __STRING(2018)

extern const char *_myUnitTests[];

SETUP_LOGGING("Pinecone", "Unittests")

INNER_FUNCTION
void
printGreetings()
{
    Termlog << "Test harness or 𝘌𝘯𝘤𝘭𝘢𝘷𝘦 𝘤𝘰𝘭𝘭𝘦𝘤𝘵𝘪𝘰𝘯 for "
        << "PineconeTest, release " << PROGRESS_VERSION
        << " (" << PROGRESS_VERSION_SHA1 << ")"                 << eol
        // << "Log file (\u0001F648) at: '" << TestlogPath << "'"  << eol
        << BUILDINFO_COPYRIGHT_MESSAGE                          << sep;
    
    Termlog << "Give regex followed by optional list of "
        << "exclusion regexes to this command to limit scope or "
        << "flag -l to list available unit tests."
        << eol;
}

INNER_FUNCTION
void
runUnitTest(
    void *addr,
    const char *symbol,
    void (^completion)(const char *symbol, uint64_t dt)
)
{
    typedef void (*Testcase)(); void (*testcase)() = (Testcase)addr;
    uint64_t startInstant = __rdtsc(); testcase();
    uint64_t dt = __rdtsc() - startInstant;
    completion(symbol, dt);
}

INNER_FUNCTION
void
lastChance()
{
#if _DEBUG
    Termlog << eol << "Please note that this binary is a debug build" << eol;
#else
    Termlog << eol << "Please note that this binary is a release build" << eol;
#endif
}

int
UnitTestTraverse(
    const char * execfilePath,
    String regex,
    String blacklist,
    bool doNotRun,
    uint64_t *total
)
{
    __block unsigned count = 0;
    
    AppSymbols syms(execfilePath);
    
    syms.symbols(^(const char * sym, uint64_t addr, bool& stop) {
        
        if (addr && EightBitHasPrefix((char *)sym, (char *)"_UnitTest_")) {

            Termlog << "\nRunning " << sym << " from 0x" << (__builtin_uint_t)addr << sep;

            runUnitTest((void *)addr, sym, ^(const char *symbol, uint64_t dt) {
                Termlog << "\n\nEND, ";
                Base(dt, 10, 0,^(char digit) { Termlog << digit; });
                Termlog << " ns when running " << symbol << eol;
                *total += dt; count++;
            });
        }
    });
    
    return count;
}

int
main(
    int argc,
    const char *utf8Argv[]
)
{
    printGreetings();
    
    //String arguments = Arguments(argc, utf8Argv);
    
    String regex = StringLiteral((argc >= 2) ? utf8Argv[1] : ".*");
    
    bool list = false; // IsEqual(StringLiteral(utf8Argv[1]), StringLiteral("-l"));
    
    //Termlog << "Running the following unit tests:" << sep;
    
    const char *execfilePath = utf8Argv[0];
    
    String blacklist = String::epsilon();
    
    uint64_t total = 0; uint64_t unitCount = UnitTestTraverse(execfilePath,
      regex, blacklist, list, &total);
    
    atexit(lastChance);
    
    Termlog << eol
        << "Unit(s): " << unitCount << eol
        << "Total: " << total << " ns" << sep;
    
    Termlog << "'𝙰𝚞𝚝𝚘𝚖𝚊𝚝𝚎𝚍 𝚞𝚗𝚒𝚝 𝚝𝚎𝚜𝚝𝚜 𝚍𝚒𝚍 𝚗𝚘𝚝 𝚏𝚒𝚗𝚍 𝚊𝚗𝚢 𝚎𝚛𝚛𝚘𝚛𝚜' 😐 " << sep;
    
    return EXIT_OK;
}
