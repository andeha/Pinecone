//
//  MemoryRegion.h
//  Pinecone
//

#ifndef __MEMORYREGION_H
#define __MEMORYREGION_H

#include <PineconeLite/Pinecone.h>

struct MemoryRegion {
    
    INLINED static
    Optional<MemoryRegion>
    abduct(
        bool allowWrites,
        __builtin_uint_t bytes,
        __builtin_int_t pagesOffset = 0
    );

    INLINED static
    Optional<MemoryRegion>
    reflect(
        String filepath,
   	 	__builtin_int_t pagesOffset = 0,
    	__builtin_uint_t bytes = 0,
        bool allowWrites = false
    );
    
    /**  Pointer to the start of the abducted or reflected memory. */
    
    INLINED uint8_t * pointer(__builtin_int_t increment) const;
    
    /**  The number of bytes constituting the memory. */
    
    INLINED __builtin_int_t bytes(bool whenAligned) const;
	
#pragma mark A Current View of 'Memory'
    
    INLINED
    int
    incorporate(
		PhysicalDirection dir,
        Vector<RegionPrimitive> augment,
        uint8_t *loc,
        void (^ping)(int64_t bytesIncluded, int64_t cumulativeOffset, uint8_t *loc),
        void (^completion)(int64_t totalBytesIncorporated, int64_t finalOffset, uint8_t *loc)
    ) const;
 
    INLINED
    int
    exclude(
        Vector<RegionPrimitive> exclusion,
        void (^ping)(uint8_t *loc, int64_t bytesRemoved, int64_t bytesUntilEnd),
        void (^completion)(int64_t totalBytesExcluded, uint8_t *lo, uint8_t *hi)
    ) const;
		
	/**  Return an identical region in constant time. */
    
	ENCLAVED MemoryRegion clone() const;
		
	/** 
     
	 Protect a memory region from read, write and/or execution. If protection
	is considered violated, an SIGBUS or SIGSERV is signaled.
     
	 */
    
	ENCLAVED void secure(bool disallowRead, bool disallowWrite, bool disallowExecute) const;
	
#pragma mark Persistency

    /**  Asynchronously preserve changes made in primary memory to drive. */
    
    void
    preserve( // While preserving, access to region is cached and written back after preservation has occurred.
        //void (^ping)(uint64_t bytesDone, uint64_t bytesLeft) = ^{},
        //void (^completion)(uint64_t bytes) = ^{}
    ) const;

#pragma mark Errors
    
    enum class ErrorCode { unableToSecure };
    
    MACRO static void Error(ErrorCode code) {
        switch (code) {
            case ErrorCode::unableToSecure: BLURT("Unable to secure");
        }
        BLURT("General error");
    }

#pragma mark Little and Big Endians

    /**  Toggle between network and native order. */

    INLINED void toggleNetworkAndNative(void (^touchbase)(bool &toggleback)) const; // REQ1: O(1).

#pragma mark Bit Manipulation
	
    bool operator[] (int64_t slot) const;
    int set(int64_t slot, bool value);

😐;

#endif
