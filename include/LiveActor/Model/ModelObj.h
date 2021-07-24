#pragma once

#include "LiveActor/LiveActor.h"

class ModelObj : public LiveActor
{
public:
    ModelObj(const char *, const char *, MtxPtr, s32, s32, s32, bool);

    virtual ~ModelObj();
    virtual void init(const JMapInfoIter &);
    virtual void calcAndSetBaseMtx();

    Mtx* _8C;
};