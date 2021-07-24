#pragma once

#include "syati.h"
#include "NameObj/NameObj.h"
#include "JGeometry/TVec3.h"

class CoinRotater : public NameObj
{
	CoinRotater(const char *);

	virtual ~CoinRotater();
	virtual void movement();

	f32 mRotateY;
	f32 mHiSpeedRotateY;
	f32 mInWaterRotateY;
	Mtx mMtxRotateY;
	Mtx mMtxHiSpeedRotateY;
	Mtx mMtxInWaterRotateY;
};

namespace MR
{
	CoinRotater* createCoinRotater();
	Mtx* getCoinRotateYMatrix();
	Mtx* getCoinHiSpeedRotateYMatrix();
	Mtx* getCoinInWaterRotateYMatrix();
};
