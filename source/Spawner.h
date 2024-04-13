#pragma once

#include "Unigine.h"
#include "global.h"

class Spawner : public Unigine::ComponentBase
{
public:
	COMPONENT_DEFINE(Spawner, ComponentBase)
		COMPONENT_UPDATE(Init)
		COMPONENT_UPDATE(Update)

		PROP_PARAM(File, node_reference, nullptr, "Node Reference")
		PROP_PARAM(Int, Max_Counts, 10)
		PROP_PARAM(Float, Size_Spawn_X, 10)
		PROP_PARAM(Float, Size_Spawn_Y, 10)
		PROP_PARAM(Float, Size_Spawn_Z, 10)

private:

	Unigine::Math::vec3 SpawnBox = Unigine::Math::vec3(Size_Spawn_X, Size_Spawn_Y, Size_Spawn_Z);

	void Init();
	void Update();

};

