#pragma once
#include <iostream>
#include "Character.h"

class Player : public Character {

public:
	void Draw() override {

		std::cout << "@" << std::endl;

	}

};