#pragma once

#include "System/NerveExecutor.h"

class ActorStateBaseInterface : public NerveExecutor
{
public:
    virtual void init();
    virtual void appear();
    virtual void kill();
    virtual bool update();
    virtual void control();

    u8 mIsDead; // _8
};