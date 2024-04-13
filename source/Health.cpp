#include "Health.h"

REGISTER_COMPONENT(Health)

void Health::Init()
{
	//Health label line
	Health_Bar = Unigine::WidgetLabel::create(); //create label
	Health_Bar->setText(Unigine::String::format("Health: %d", int(local_health))); //set text to label
	Health_Bar->setFontSize(50);
	Health_Bar->setFontColor(Unigine::Math::vec4_green);
	gui.getCurrent()->addChild(Health_Bar, Unigine::Gui::ALIGN_LEFT); //get current gui and add our label

	//Timer Start
	time_of_life.begin();
}

void Health::Update()
{
	//Life-Time Logick
	if (local_health > 0)
	{
		if (int(time_of_life.endSeconds()) == local_time_of_damage)
		{
			local_health -= local_delta_health;
			time_of_life.begin();
		}
		Health_Bar->setText(Unigine::String::format("Health: %d", int(local_health)));
	}
	else
	{
		Health_Bar->setFontColor(Unigine::Math::vec4_red);
		Health_Bar->setText("YOU LOSE!!!");
	}

}

void Health::HealthBuff(int num)
{
	local_health += num;
}
