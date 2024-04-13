#pragma once

#include "Unigine.h"

class Health : public Unigine::ComponentBase
{
public:

	COMPONENT_DEFINE(Health, ComponentBase)
		COMPONENT_INIT(Init)
		COMPONENT_UPDATE(Update)

	PROP_PARAM(Int, HealthCount, 50)
	PROP_PARAM(Int, Delta_Heath, 2)
	PROP_PARAM(Int, Time_Of_Damage, 1)
	
	void Health::HealthBuff(int num);

	int local_health = HealthCount;
	int local_delta_health = Delta_Heath;
	int local_time_of_damage = Time_Of_Damage;

private:

	//GUI
	Unigine::Gui gui; //create gui object
	Unigine::WidgetLabelPtr Health_Bar;
	//Timer
	Unigine::Timer time_of_life;

	void Init();
	void Update();

};

