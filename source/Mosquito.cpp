#include "Mosquito.h"


REGISTER_COMPONENT(Mosquito)





void Mosquito::Init()
{
	//get RigidBody from node
	MosquitoBody = node->getObjectBodyRigid();
	//Visualizer Enabled
	Unigine::Visualizer::setEnabled(true);
}

void Mosquito::Update()
{
	//Y - green
	Unigine::Visualizer::renderVector(node->getWorldPosition(), node->getWorldPosition() + Unigine::Math::Vec3(node->getWorldDirection(Unigine::Math::AXIS_Y)), Unigine::Math::vec4_green);
	//X - red
	Unigine::Visualizer::renderVector(node->getWorldPosition(), node->getWorldPosition() + Unigine::Math::Vec3(node->getWorldDirection(Unigine::Math::AXIS_X)), Unigine::Math::vec4_red);
	//Z - blue
	Unigine::Visualizer::renderVector(node->getWorldPosition(), node->getWorldPosition() + Unigine::Math::Vec3(node->getWorldDirection(Unigine::Math::AXIS_Z)), Unigine::Math::vec4_blue);
	
}

void Mosquito::Update_Physics()
{
	float fly_force = 9.2f;
	//vetor from forces to fly narrow corection
	Unigine::Math::vec3 narrow_forces = Unigine::Math::vec3_up * fly_force;
	//forward/rear
	if (Unigine::Input::isKeyPressed(Unigine::Input::KEY_W))
	{
		narrow_forces += node->getWorldDirection(Unigine::Math::AXIS_Y) * Forward_Force;
	}
	if (Unigine::Input::isKeyPressed(Unigine::Input::KEY_S))
	{
		narrow_forces += node->getWorldDirection(Unigine::Math::AXIS_Y) * -Forward_Force;
	}
	//torque left/right
	if (Unigine::Input::isKeyPressed(Unigine::Input::KEY_A))
	{
		MosquitoBody->addTorque(Unigine::Math::vec3_up * Torque_Force);
	}
	if (Unigine::Input::isKeyPressed(Unigine::Input::KEY_D))
	{
		MosquitoBody->addTorque(Unigine::Math::vec3_up * -Torque_Force);
	}
	//up/down
	if (Unigine::Input::isKeyPressed(Unigine::Input::KEY_SPACE))
	{
		narrow_forces += node->getWorldDirection(Unigine::Math::AXIS_Z) * Lifting_Force;
	}
	if (Unigine::Input::isKeyPressed(Unigine::Input::KEY_ANY_CTRL))
	{
		narrow_forces -= (node->getWorldDirection(Unigine::Math::AXIS_Z) * Lifting_Force) / Down_Force;
	}
	//aplying vector of force to body
	MosquitoBody->addWorldForce(node->toWorld(v3_rotor), narrow_forces);
	//visualize of narrow_forces
	Unigine::Visualizer::renderVector(node->toWorld(v3_rotor), (node->toWorld(v3_rotor) + Unigine::Math::Vec3(narrow_forces / fly_force)), Unigine::Math::vec4_white, 0.25f, true, 0.0f, false);
}
