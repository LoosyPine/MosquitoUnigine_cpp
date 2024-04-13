#include "Spawner.h"

REGISTER_COMPONENT(Spawner)

void Spawner::Init()
{
	Unigine::Visualizer::renderBox(SpawnBox, node->getWorldTransform(), Unigine::Math::vec4_blue);
}

void Spawner::Update()
{
	if (bonus_counts < Max_Counts)
	{
		const auto bon = Unigine::NodeReference::create(node_reference);
		bonus_counts++;
		const auto rand_pos = Unigine::Math::Vec3(
			Unigine::Game::getRandomFloat(-Size_Spawn_X, Size_Spawn_X),
			Unigine::Game::getRandomFloat(-Size_Spawn_Y, Size_Spawn_Y),
			Unigine::Game::getRandomFloat(-Size_Spawn_Z / 2, Size_Spawn_Z)
		);

		bon->setWorldPosition(node->getWorldPosition() + rand_pos);
		bon->getChild(0)->worldRotate(0, Unigine::Game::getRandomFloat(-180.0f, 180.0f), 0);
	}
}
