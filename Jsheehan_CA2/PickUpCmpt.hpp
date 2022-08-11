#pragma once
#include "Component.hpp"
enum Type { HEALTH, SPEED, INVINCIBILITY };
class PickUpCmpt : public Component
{
public:
	PickUpCmpt(Type type);
	~PickUpCmpt();
	void Update(float timeDelta){
	}

private:
	Type m_type;
	bool active = false;

};

