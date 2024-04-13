#pragma once

#include "Unigine.h"

class Mosquito : public Unigine::ComponentBase 
{
public:
	COMPONENT_DEFINE(Mosquito, ComponentBase)
		COMPONENT_INIT(Init)
		COMPONENT_UPDATE(Update)
		COMPONENT_UPDATE_PHYSICS(Update_Physics)

		PROP_PARAM(Float, Torque_Force, 1.0f)
		PROP_PARAM(Float, Forward_Force, 1.0f)
		PROP_PARAM(Float, Lifting_Force, 1.0f)
		PROP_PARAM(Float, Down_Force, 2.0f)
		PROP_PARAM(Float, Rotor_Point, 0.3f)

		

private:

	Unigine::BodyRigidPtr MosquitoBody;
	Unigine::Math::vec3 v3_rotor = Unigine::Math::vec3(0.0f, 0.0f, Rotor_Point);

	

	void Init();
	void Update();
	void Update_Physics();

};

