#pragma once

#include "AreaObj/AreaObj.h"

class ShadowColorArea : public AreaObj
{
public:
	ShadowColorArea(const char *pName);

	virtual ~ShadowColorArea();
	virtual void init(const JMapInfoIter &rIter);
};
