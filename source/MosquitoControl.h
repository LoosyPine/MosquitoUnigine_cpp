#pragma once

#include "Mosquito.h"

class MosquitoControl : public Mosquito
{
public:

	void PlayerKeysInput();

private:

	//forces variables...
	float force = 1.0f;
};

