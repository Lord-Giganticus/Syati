#pragma once

#include "syati.h"

class JMapIdInfo;

namespace GameSequenceFunction {
public:
	void changeSceneStage(const char *, s32, s32, JMapIdInfo *);
	const char* getClearedStageName();
};
