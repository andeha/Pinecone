//
//  Chronology.h
//  Pinecone Additions
//

#ifndef __CHRONOLOGY_H
#define __CHRONOLOGY_H

#include <Pinecone.h>

/**
     
     Timestamps, timezones, calendric increments and NTP clock synchronization.
     Calendric computations are similar yet not 'too similar' to the Gregorian
     calendar.
     
     With 'prompt> sysctl', note kern.clockrates { hz = 100, tick = 10000,
     tickadj = 2, profhz = 100, stathz = 100 } as in the
     
        [], 😐😐, 😐😐😐😐, ...  but sometimes fortunately no 😐😐😐.
     
     pattern.
     
 */

struct Chronology {
    
    /**
     
     A @c Timestamp represents a 136 year interval (an era), with an 𝜖 equal
     to 232 ps.  Prime epoch defined as 0am, 1 January 1900.
     
     😐📖: See https://en.wikipedia.org/wiki/David_L._Mills for a background.
     
     */
    
    typedef uint64_t Timestamp;
    
    /**
     
     In this class, a timezone alters the instant with a positive or negative
     number of hours.
     
     TODO: Maybe daylight saving and fractional offsets.
     
     */

    typedef uint64_t Timezone;
    
#pragma mark Constructors and Destructors

    Chronology(
        Vector<String> userTimesources = {}, // 🎓 'I promise to replace one or more.' ☜😐
        Timezone tz = Chronology::UTC()
    );

    ~Chronology();
        
#pragma mark - Timestamp Boundaries and the Default Timezone

    INLINED static Timestamp LastInstant();
    
    INLINED static Timestamp FirstInstant();
        
    INLINED static Timezone UTC(); // UTC(DRIFTING)
    
#pragma mark - Consensus
    
    /** 
     
     Return @c true if @c this has been connected to at least one time
     source in the past.
     
     */
     
#ifndef NO_NTP_VIA_WIFI
    bool onceSynchronized() const;
#endif 
	
    /**
     
     The current version of the NTP sends a request and then listens for
     responses via UDP (which has been suceptible to denial of service
     attacks in the past.)
     
     */
    
#ifndef NO_NTP_VIA_WIFI
    void
    synchronize(
        void (^ping)(String *ip, Timestamp instant)
    ) const;
#endif

    /**  Time sources used to ensure 'a consistent time base'. */
    
    Vector<String> timesources() const;

    /**  The time without NTP correction. When bad-apple NTP, will change to now(). */
    
    Timestamp localNow(uint32_t fractSec) const;

#pragma mark - Creation and Interpretation of an Instant

    /**  Given a timestamp, return year, month (1-12) and day (1-31). 
	
	Consider representing dates x = ((y<<4 + m)<<5+d, where 
	d = x mod 32, m = (x>>5) mod 16, y = x>>9
	
	*/
    
    Tuple<int64_t, int64_t, int64_t> date(Timestamp instant) const;
    
    /** 
     
     Return hour (0-23), minute (0-59), seconds (0-59) and fractional
     precision since midnight.
     
     */
    
    Tuple<int64_t, int64_t, int64_t, uint32_t> sinceMidnight(Timestamp instant) const;
    
    /** 
     
     Create a timestamp from a date and a time.
        
     @param parts  Contains year, month (1-12), day (1-31), hour (0-23),
         minutes (0-59) and seconds (0-59)
     
     @param fractSec  Fractional seconds currently expected to be a 32 bit
         unsigned value expressing the number of 232 ps intervals.
          
     */
    
    Timestamp timestamp(int64_t parts[6], uint32_t fractSec) const;

#pragma mark - Δt
    
    /**  Return a future instant. */
    
    Timestamp
    addSeconds(
        Timestamp instant,
        uint32_t seconds, 
		uint32_t fractSec = 0
    ) const;
    
    /**  Return a historical instant. */
    
    Timestamp
    subtractSeconds(
        Timestamp instant,
        uint32_t seconds
    ) const BLURTS;
 
#pragma mark - Localization
    
    /**  Return weekday assuming a week starts on a Sunday. (Encoded as 0.) */
    
    int dayOfWeek(Timestamp instant) const;
    
#pragma mark - Spatial Relocation
    
    /**  Corresponding instant in a time zone indicated by @c destination. */

    Timestamp move(const Timezone &destination, const Timestamp &instant) const;

#pragma mark - Peculiarities

    /**  Daylight saving, leap seconds and other artifacts. */

    void addCorrection(Timestamp prev, Timestamp later) const;

    /**  Given a year, return a estimate when easter may expect to occur. */

    Tuple<int64_t, int64_t, int64_t> easter(int64_t year) const;

	/**  Return @c true if @y is a leap year. */

    static bool isLeapyear(uint64_t year);

    /**

     Retrieve a - since the program started - unique value in an pseudo-'ever
     increasing' serie.

     */

     static uint64_t ordinal();

😐;

/**  Given a chronology, convert a textual expression reminicent to an instant. */

Optional<Chronology::Timestamp>
TS(
   Chronology chronology,
   String datetime
) NEVERBLURTS;

/**  The fractional part in an instant. */

#define TwoThreeTwoPSMultiples(x) x
 
#pragma mark - Typed System Info

/**  The chronology of the users' choice. */

ENCLAVED Chronology& SystemInfoCalendricChronology();

/**  The unperturbed — yet based on Caesium 133 — chronology. */

ENCLAVED Chronology& MonotonicallyIncreasingChronology();

// TODO: /consider adding a strictly monotonically increasing chronology and investigate its relationship to chip area. Also its application when increasing probability for hard RT.

#pragma mark - Scheduled Sequent

FOCAL
ENCLAVED
int
Sequent(
    String rope,
    const Chronology &chronology,
    Chronology::Timestamp notBefore,
    void (^closure)()
);
    
#endif
