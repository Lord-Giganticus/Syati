#pragma once

#include "System/Nerve/Nerve.h"
#include "syati.h"

class ActorStateKeeper;

class Spine
{
public:
    Spine(void *, const Nerve *, s32);

    void update();
    void setNerve(const Nerve *);
    const Nerve* getCurrentNerve() const;
    void changeNerve();
    void initStateKeeper(s32);

    void* mExecutor; // _0
    const Nerve* mCurState; // _4
    const Nerve* mNextState; // _8
    u32 mNerveStep; // _C
    ActorStateKeeper* mStateKeeper; // _10
};