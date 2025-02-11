#pragma once

#include "AreaObj/AreaObj.h"

class AudioEffectArea : public AreaObj
{
public:
	AudioEffectArea(const char *pName);

	virtual ~AudioEffectArea();
	virtual void init(const JMapInfoIter &rIter);
	virtual void movement();
	virtual const char* getManagerName() const;

	s32 mAudEffectArg0; // _48
	s32 mAudEffectArg1; // _4C
};
