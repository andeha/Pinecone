//
//  Versioning.hpp
//  Helixstore
//

#ifndef __VERSIONING_HPP
#define __VERSIONING_HPP

#include <PineconeNucleus.h>

typedef __builtin_int_t Version;

template <typename E>
struct Versioning {
    
    Vector<Tuple<Version, __builtin_uint_t>> versions;
    
    Vector<Tuple<Chronology::Timestamp, Version>> instantToRevision;
    
    Version nextRevision;
    
    Versioning() { nextRevision = 3; }
    
    Interval<__builtin_uint_t> uncommitted(Vector<E>& events) {
        if (versions.count() == 0)
        { return Interval<__builtin_uint_t> { 0, events.count() - 1 }; }
        else { auto start = events.startIndex +
          get<1>(versions[versions.count() - 1]) + 1;
            return Interval<__builtin_uint_t> { start, events.endIndex };
        }
    }
    
    void append(Chronology::Timestamp instant, Vector<E>& events) {
        auto top = events.count - 1;
        versions.pushback(Tuple<Version, __builtin_uint_t>(nextRevision, top));
        instantToRevision.pushback(Tuple<Chronology::Timestamp, Version>(
          instant, nextRevision));
        Termlog << "Committed version '" << (__builtin_int_t)nextRevision
          << "'" << eol;
        nextRevision++;
    }
    
};

#endif
