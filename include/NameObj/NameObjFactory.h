#pragma once

#include "kamek.h"
#include "NameObj/NameObj.h"

struct ActorEntry
{
    const char* pActorName; // _0
    NameObj* (*mCreationFunc)(const char *); // _4
};

class NameObjFactory
{
public:

    static void* getCreator(const char *);

    static NameObj* initChildObj(const JMapInfoIter &, int);

    static ActorEntry cCreateTable[0x3EB];

    // custom functions
    static ActorEntry getEntry(s32 idx)
    {
        return cCreateTable[idx];
    }
};