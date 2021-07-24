#pragma once

#include "syati.h"
#include "System/Nerve/Nerve.h"

class NerveExecutor
{
public:
    NerveExecutor(const char *);

    virtual ~NerveExecutor() { }

    void initNerve(const Nerve *);
    void updateNerve();
    void setNerve(const Nerve *);
    bool isNerve(const Nerve* ) const;
    u32 getNerveStep() const;

    Spine* mSpine; // _4
};
