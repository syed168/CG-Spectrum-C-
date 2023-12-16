#pragma once
#include <iostream>
#include "Character.h"

class Enemy : public Character {

public:
	void Draw() override {

		std::cout << "*" << std::endl;

	}

};
