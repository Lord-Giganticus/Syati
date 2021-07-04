#pragma once

#include "kamek.h"
#include "LiveActor/LiveActor.h"
#include "LiveActor/State/ActorStateParamScale.h"

class RingBeam : public LiveActor
{
public:
	RingBeam(const char *, LiveActor *, bool, bool, bool, bool, const char * pName);

	virtual ~RingBeam();
	virtual void init(const JMapInfoIter &);
	virtual void movement();
	virtual void appear();
	virtual void kill();
	virtual void makeActorDead();
	virtual void control();
	virtual void attackSensor(HitSensor *, HitSensor *);
	virtual bool receiveMsgPlayerAttack(u32, HitSensor *, HitSensor *);

	void initWithParamScale(const JMapInfoIter &, const ActorStateParamScale *);

	void setSpeed(f32);
	void setLife(s32);
	void setColor(f32);

	s32 _90;
	s32 _94;
	s32 _98;
	f32 mSpeed;
	s32 mLife;
	bool _A4;
	bool _A5;
	bool _A6;
	bool _A7;
	s32 _A8;
	s32 _AC;
	s32 _B0[13];
	f32 mColor;
	f32 _E8;
	f32 _EC;
};
