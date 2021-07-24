#pragma once

#include "syati.h"
#include "LiveActor/Clipping/ClippingActorInfo.h"
#include "LiveActor/LiveActor.h"

class LodCtrl;

class ClippingActorHolder : public NameObj
{
public:
    ClippingActorHolder();

    virtual ~ClippingActorHolder();
    virtual void movement();

    void initViewGroupTable();
    void entryLodCtrl(LodCtrl *, const JMapInfoIter &);
    void registerActor(LiveActor *);
    void initSystemInfo(LiveActor *, const JMapInfoIter &);

    ClippingActorInfo* startGroupClipping(LiveActor *, const JMapInfoIter &);

    u32 _C;
    u32* _10; // ClippingActorInfoList*
    u32* _14; // ^^
    u32* _18; // ^^
    u32* _1C; // ^^
    u32 _20;
};