#include <iostream>
#include <windows.h>
#include "Door.h"

Door::Door(int x, int y, int color, int closedColor)
	: PlacableActor(x, y, color)
	, m_IsOpen(false)
	, m_closedColor(closedColor)
{

}

void Door::Draw() {

	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	if (m_IsOpen) {

		SetConsoleTextAttribute(console, m_color);
	}
	else {

		SetConsoleTextAttribute(console, m_closedColor);
	}
	std::cout << "|";
	SetConsoleTextAttribute(console, kRegularColor);
}