#pragma once
#include "GameObject.h"
#include "Goomba.h"

#define KOOPAS_GRAVITY 0.002f
#define KOOPAS_WALKING_SPEED 0.05f


#define KOOPAS_BBOX_WIDTH 16
#define KOOPAS_BBOX_HEIGHT 24
#define KOOPAS_BBOX_SHELL_HEIGHT 16

#define KOOPAS_STATE_WALKING 100
#define KOOPAS_STATE_SHELL_STAND 200
#define KOOPAS_STATE_SHELL_MOVE 201

#define ID_ANI_KOOPAS_WALKING_LEFT 6000
#define ID_ANI_KOOPAS_WALKING_RIGHT 6001
#define ID_ANI_KOOPAS_SHELL_STAND 6002
#define ID_ANI_KOOPAS_SHELL_MOVE 6003

class CKoopas: public CGameObject
{
protected:
	float ax;
	float ay;

	ULONGLONG die_start;

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void Render();

	virtual int IsCollidable() { return 1; };
	virtual int IsBlocking();
	virtual void OnNoCollision(DWORD dt);

	virtual void OnCollisionWith(LPCOLLISIONEVENT e);

public:
	CKoopas(float x, float y, int state);
	virtual void SetState(int state);
	void SetShellStateMoveSpeedLeft();
	void SetShellStateMoveSpeedRight();
	void SetYWhenColide();
};