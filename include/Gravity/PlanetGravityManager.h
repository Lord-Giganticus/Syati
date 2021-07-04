#pragma once

#include "NameObj/NameObj.h"
#include "Gravity/GravityInfo.h"
#include "Gravity/PlanetGravity.h"

class PlanetGravityManager : public NameObj
{
public:
	PlanetGravityManager(const char*);

	virtual ~PlanetGravityManager();
	virtual void init(const JMapInfoIter &);

	void calcTotalGravityVector(TVec3f *, GravityInfo *, const TVec3f &, u32, u32) const;
	void registerGravity(PlanetGravity *);

	PlanetGravity* mGravities[128];
	s32 mNumGravities;
};
