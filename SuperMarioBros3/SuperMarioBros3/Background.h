#include "Animation.h"
#include "Animations.h"
#include "GameObject.h"

class CBackground : public CGameObject {
public:
	CBackground(float x, float y) : CGameObject(x, y) {};
	void Render();
	void Update(DWORD dt) {};
	void GetBoundingBox(float& l, float& t, float& r, float& b) {};
};
