//
//  Guid.h
//  Pinecone Additions
//

#ifndef __GUID_H
#define __GUID_H

#include <Pinecone.h>

typedef sexdeca Guid;

int NewGuid(void (^touchbase)(Guid *guid));

String GuidToString(Guid *guid);

String GUID();

#endif
