//
//  TimeserieTests.cpp
//  Helixstore Unit Tests
//

#include <PineconeNucleus.h>
#include <Helixstore/Timeserie.hpp>

UNITTEST(Timeserie_1)
{
    __builtin_int_t revision = 102;
    
    typedef double TimeserieType;
    
    using DoubleTimeSerie = Timeserie<String, TimeserieType, const char *>;
    
    auto commit = ^(const char * ref, TimeserieType *amend,
      DoubleTimeSerie::Version ver) { Termlog << "Committing version "
      << ver << ", having value " << *amend << ", (" << ref << ")" << eol; };
    
    DoubleTimeSerie timeserie(revision);
    
    timeserie.create(StringLiteral(Endianness::Native, U"Alice", -1), 200.00, "abcd-1");
    timeserie.commit(commit); // Transaction 102 (0x65)
    revision++;
    
    timeserie.create(StringLiteral(Endianness::Native, U"Bob", -1), 300.00, "abcd-2");
    timeserie.commit(commit); // Transaction 103
    revision++;
    
    timeserie.update(StringLiteral(Endianness::Native, U"Alice", -1), 500.00,"abcd-3");
    timeserie.create(StringLiteral(Endianness::Native, U"Bobo", -1),  100.00,"abcd-4");
    timeserie.commit(commit); // Transaction 104
    revision++;
    
    timeserie.commit(commit); // Transaction 105
    revision++;
    
    timeserie.create(StringLiteral(Endianness::Native, U"Ella", -1), 700.00, "abcd-5");
    timeserie.create(StringLiteral(Endianness::Native, U"Jim", -1),  400.00, "abcd-6");
    timeserie.commit(commit); // Transaction 106 (0x69)
    revision++;
    
    timeserie.remove(StringLiteral(Endianness::Native, U"Alice", -1));
    timeserie.remove(StringLiteral(Endianness::Native, U"Jim", -1));
    timeserie.commit(commit); // Transaction 107 (0x6a)
    revision++;
    
    timeserie.remove(StringLiteral(Endianness::Native, U"Bob", -1));
    timeserie.commit(commit); // Transaction 108 (0x6b)
    revision++;
    
    String expected = StringLiteral(
    
R"(
CURRENT TABLE
Bobo 100
Ella 700
...
)");
    
    String serializedTimeserie = Present(timeserie);
    if (UnicodeNonapproximativeCompare(serializedTimeserie, expected, true,
    ^(bool isEqual) { ENSURE(isEqual, ""); },
    ^(UnicodeDifference delta, bool& stop) { return false; },
    ^(bool& stop) { }
    )) {}
}
