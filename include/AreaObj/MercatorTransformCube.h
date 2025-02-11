#pragma once

#include "AreaObj/AreaObj.h"
#include "LiveActor/LiveActor.h"

class MercatorTransformCube : public AreaObj
{
public:
	MercatorTransformCube(int, const char *pName);

	virtual ~MercatorTransformCube();
	virtual void init(const JMapInfoIter &rIter);

	void convertTransAndRotate(TVec3f *, TPositionMtx *, const TVec3f &, bool) const;
	f32 getSphereRadius() const;
	void calcUV(TVec2f * pUV, const TVec3f &) const;
	void calcLocalBoxSize(TVec3f *pLocalBoxSize) const;

	Mtx mZonePlacementMtx; // _48
};

class DivideMercatorRailPosInfo
{
	virtual void setPosition(s32, const TVec3f &mPosition) = 0;

	LiveActor* mActor; // _4
};

namespace MR
{
	MercatorTransformCube* getMercatorCube();
	f32 calcRailClippingInfoForMercator(TVec3f *, f32 *, LiveActor *, f32, f32);
	void getDivideMercatorRailPosition(DivideMercatorRailPosInfo *, const LiveActor *, u32, f32, u32);
};
