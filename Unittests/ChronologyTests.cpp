//
//  ChronologyTests.cpp
//  Pinecone Additionals Unit Tests
//

#include <PineconeNucleus.h>
#include <Additions/Chronology.h>

UNITTEST(Chronology_static)
{
    Chronology::Timestamp last = Chronology::LastInstant();
    ENSURE(last == 4294967295, "Error in LastInstant");
    Chronology::Timestamp first = Chronology::FirstInstant();
    ENSURE(first == 0, "Error in FirstInstant");
}

UNITTEST(Chronology_UTC)
{
    Chronology::Timezone tz = Chronology::UTC();
    ENSURE(tz == 0, "Error in UTC");
}

UNITTEST(Chronology_singularconsensus)
{
    Chronology chronology1 = Chronology({}, Chronology::UTC());
    bool syncronized = chronology1.onceSynchronized();
    ENSURE(!syncronized, "Error in onceSynchronized");
}

UNITTEST(Chronology_now)
{
    Chronology chronology = SystemInfoCalendricChronology();
    Chronology::Timestamp instant = chronology.localNow(0);
    Termlog << "Calendric localNow is " << instant << " and in text: " << eol;
    if (TimestampToText(chronology, instant, ^(char c) {
        Termlog << c;
    })) { ENSURE(false, "Error when ToString"); }
    Termlog << eol;
    ENSURE(instant != 0, "Error in localNow");
}

UNITTEST(Chronology_date)
{
    Chronology chronology = MonotonicallyIncreasingChronology();
    Chronology::Timestamp instant = chronology.localNow(0);
    Termlog << "Monotonically increasing localNow is " << instant << " and in text ";
    if (TimestampToText(chronology, instant, ^(char c) {
        Termlog << c;
    })) { ENSURE(false, "Error when TimestampToString"); }
    Termlog << eol;
    Tuple<int32_t, int32_t, int32_t> pre = chronology.date(instant);
    Termlog << "Date is " << (__builtin_int_t)get<0>(pre) << ", " << (__builtin_int_t)get<1>(pre) << ", " << (__builtin_int_t)get<2>(pre) << eol;
    Chronology::Date date = chronology.toDate(pre);
    Termlog << "Terse date is " << (__builtin_int_t)date << eol;
    Tuple<int32_t, int32_t, int32_t> post = chronology.fromDate(date);
    Termlog << "From terse date gives " << (__builtin_int_t)get<0>(post) << ", "
      << (__builtin_int_t)get<1>(post) << ", "
      << (__builtin_int_t)get<2>(post) << eol;
    Termlog << "Date was " << (__builtin_int_t)date << eol;
    ENSURE(get<0>(pre) == get<0>(post), "Error in year");
    ENSURE(get<1>(pre) == get<1>(post), "Error in month");
    ENSURE(get<2>(pre) == get<2>(post), "Error in day");
}

UNITTEST(Chronology_midnight)
{
    Chronology chronology = SystemInfoCalendricChronology();
    int32_t parts[6] = { 1997, 1, 1, 12, 31, 32 };
    Chronology::Timestamp instant = chronology.timestamp(parts, 1);
    Termlog << "Timestamp is " << instant << " and textually ";
    if (TimestampToText(chronology, instant, ^(char c) {
        Termlog << c;
    })) { ENSURE(false, "Error when TimestampToString"); }
    Termlog << eol;
    Tuple<int32_t, int32_t, int32_t, uint32_t> day = chronology.sinceMidnight(instant);
    Termlog << "Since midnight is " << (__builtin_int_t)get<0>(day) << ", "
      << (__builtin_int_t)get<1>(day) << ", " << (__builtin_int_t)get<2>(day)
      << ", " << (__builtin_int_t)get<3>(day) << eol;
}

UNITTEST(Chronology_increment)
{
    Chronology chronology = SystemInfoCalendricChronology();
    int32_t parts[6] = { 1997, 1, 1, 12, 31, 32 };
    Chronology::Timestamp instant = chronology.timestamp(parts, 1);
    Termlog << "Timestamp is " << instant << " and textually ";
    if (TimestampToText(chronology, instant, ^(char c) {
        Termlog << c;
    })) { ENSURE(false, "Error when TimestampToString"); }
    Termlog << eol;
    Chronology::Timestamp later = chronology.addSeconds(instant, 17, 2);
    Termlog << "Later is " << later << " and textually ";
    if (TimestampToText(chronology, later, ^(char c) {
        Termlog << c;
    })) { ENSURE(false, "Error when TimestampToString"); }
    Termlog << eol;
    ENSURE(instant != later, "Error in addSeconds");
    Chronology::Timestamp earlier = chronology.subtractSeconds(instant, 17);
    Termlog << "Earlier is " << earlier << " and textually ";
    if (TimestampToText(chronology, earlier, ^(char c) {
        Termlog << c;
    })) { ENSURE(false, "Error when TimestampToString"); }
    Termlog << eol;
    ENSURE(later != earlier, "Error in subtractSeconds");
}

UNITTEST(Chronology_dayOfWeek)
{
    Chronology chronology = SystemInfoCalendricChronology();
    Chronology::Timestamp instant = chronology.localNow(0);
    int weekday = chronology.dayOfWeek(instant);
    Termlog << "Weekday is " << (__builtin_uint_t)weekday;
    auto weeknoToWeekday = ^(int weekday) {
        switch (weekday) {
            case 0: return "Sunday";
            case 1: return "Monday";
            case 2: return "Tuesday";
            case 3: return "Wednesday";
            case 4: return "Thursday";
            case 5: return "Friday";
            case 6: return "Saturday";
        }
        return "Unknown";
    };
    Termlog << " ...and in text " << weeknoToWeekday(weekday) << eol;
    ENSURE(weekday > 0 && weekday < 7, "Error in dayOfWeek");
}

UNITTEST(Chronology_move)
{
    Chronology::Timezone approxGreenwitch = Chronology::UTC();
    Chronology inNewtonsPocket = Chronology({}, approxGreenwitch);
    Chronology::Timestamp here = inNewtonsPocket.localNow(0);
    Termlog << "Here is ";
    if (TimestampToText(inNewtonsPocket, here, ^(char c) {
        Termlog << c;
    })) { ENSURE(false, "Error when TimestampToString"); }
    Termlog << eol;
    Chronology::Timezone NepalStandardTime = Chronology::UTC() + 5*60 + 45;
    Chronology::Timestamp there = inNewtonsPocket.move(NepalStandardTime, here);
    Termlog << "There is ";
    if (TimestampToText(inNewtonsPocket, there, ^(char c) {
        Termlog << c;
    })) { ENSURE(false, "Error when TimestampToString"); }
    Termlog << eol;
    ENSURE(here != there, "Error in move");
}

UNITTEST(Chronology_easter)
{
    Chronology::Timezone approxGreenwitch = Chronology::UTC();
    Chronology PaulusIIQuickGlance = Chronology({}, approxGreenwitch);
    Tuple<__builtin_int_t, __builtin_int_t, __builtin_int_t> day =
        PaulusIIQuickGlance.easter(2000);
    Termlog << "Easter is " << get<0>(day) << ", " << get<1>(day) << ", " << get<2>(day) << eol;
    ENSURE(get<0>(day) == 2000, "Error on easter");
    ENSURE(get<1>(day) == 4, "Error on easter");
    //ENSURE(get<2>(day) == 23, "Error on easter");
}

UNITTEST(Chronology_leap)
{
    bool l1 = Chronology::isLeapyear(2000);
    bool l2 = Chronology::isLeapyear(2018);
    bool l3 = Chronology::isLeapyear(2020);
    ENSURE(l1 && !l2 && l3, "Error when isLeapyear");
}

UNITTEST(Chronology_monotonicallyIncreasing)
{
    Chronology mono = MonotonicallyIncreasingChronology();
    Chronology calendric = SystemInfoCalendricChronology();
    Chronology::Timestamp monopre = mono.localNow(0);
    Chronology::Timestamp calpre = calendric.localNow(0);
    ENSURE(monopre == calpre, "Error in pre");
    // TODO: Pass a change winter/summer time.
    Chronology::Timestamp monopost = mono.localNow(0);
    Chronology::Timestamp calpost = calendric.localNow(0);
    // TODO: Pass a change (leap second).
    //ENSURE(monopost != calpost, "Error in post");
}

UNITTEST(Chronology_ordinal)
{
    uint64_t ord1 = Chronology::ordinal();
    uint64_t ord2 = Chronology::ordinal();
    uint64_t ord3 = Chronology::ordinal();
    ENSURE(ord1 != ord2 && ord1 != ord3, "Error when acquire ordinal");
    ENSURE(ord2 != ord3, "Error when acquire ordinal");
    ENSURE(ord1 < ord2, "Error when acquire ordinal");
    ENSURE(ord1 < ord3, "Error when acquire ordinal");
    ENSURE(ord2 < ord3, "Error when acquire ordinal");
}

UNITTEST(Chronology_onetzconsensus)
{
    Vector<const char *> timesources = { "0.ch.pool.ntp.org", "3.ch.pool.ntp.org" };
    __block Chronology chronology = Chronology(timesources, Chronology::UTC());
    bool syncronized = chronology.onceSynchronized();
    ENSURE(!syncronized, "Error in onceSynchronized");
#ifdef NTP_VIA_WIFI
    if (chronology.synchronize(^(const char *ip, Chronology::Timestamp instant) {
        Termlog << ip << ": ";
        if (TimestampToText(chronology, instant, ^(char c) { Termlog << c; }))
        { ENSURE(false, "Error in TimestampToString"); }
        Termlog << eol;
    })) { ENSURE(false, "Error in synchronize"); }
#endif
}

UNITTEST(Chronology_twotz)
{
    Vector<const char *> timesources = { "3.us.pool.ntp.org", "3.ch.pool.ntp.org" };
    Chronology chronology = Chronology(timesources, Chronology::UTC());
    bool syncronized = chronology.onceSynchronized();
    ENSURE(!syncronized, "Error in onceSynchronized");
#ifdef NTP_VIA_WIFI
    if (chronology.synchronize(^(const char *ip, Chronology::Timestamp instant) {
        Termlog << ip << ": ";
        if (TimestampToText(chronology, instant, ^(char c) { Termlog << c; }))
        { ENSURE(false, "Error in TimestampToString"); }
        Termlog << eol;
    })) { ENSURE(false, "Error in synchronize"); }
#endif
}

