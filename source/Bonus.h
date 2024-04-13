#pragma once

#include "Unigine.h"
#include "Health.h"
#include "global.h"

class Bonus : public Unigine::ComponentBase
{
public:

	COMPONENT_DEFINE(Bonus, ComponentBase)
		COMPONENT_INIT(Init)
		COMPONENT_UPDATE(Update)

	PROP_PARAM(Int, HealthCost, 25)
	PROP_PARAM(Float, Radius, 1.0f)

private:

	Unigine::ShapeSpherePtr bonus_collision;

	Health* find = nullptr;

	void Init();
	void Update();

};

