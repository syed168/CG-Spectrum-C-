#pragma once
#include "Point.h"

class Player {

	Point m_position;
	bool m_haskey;

public:

	//Constructor

	Player();
	~Player();

	//Deconstructor

	int GetXPosition() { return m_position.x; }
	int GetYPosition() { return m_position.y; }

	int* GetXPositionPointer() { return &(m_position.x); }
	int* GetYPositionPointer() { return &(m_position.y); }

	//Member Function

	void SetPosition(int x, int y);

	bool HasKey();
	void PickupKey();
	void UseKey();

	void Draw();

};