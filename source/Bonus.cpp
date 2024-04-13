#include "Bonus.h"

REGISTER_COMPONENT(Bonus)

void Bonus::Init()
{
	//Visualizer enabled in Mosquito.cpp

	//Make a shape-collision to bonus
	bonus_collision = Unigine::ShapeSphere::create();
	bonus_collision->setRadius(Radius);
	bonus_collision->setPosition(node->getWorldPosition());

	//finding first needed node
	Unigine::Vector<Unigine::NodePtr> nodes;
	Unigine::World::getRootNodes(nodes);
	for (int i = 0; i < nodes.size(); i++)
	{
		if (auto componentPtr = Unigine::ComponentSystem::get()->getComponentInChildren<Health>(nodes.get(i)))
		{
			find = componentPtr;
			break;
		}
	}
}

void Bonus::Update()
{
	Unigine::Visualizer::renderSphere(Radius, node->getWorldTransform(), Unigine::Math::vec4_green);

	//Collisions with mosquito detecting
	Unigine::Vector<Unigine::ShapeContactPtr> V_shape_contact;
	if (bonus_collision->getCollision(V_shape_contact))
	{
		node.deleteLater();
		find->local_health += HealthCost;
		--bonus_counts;
	}
}

