#include "Player.h"
#include <iostream>

using namespace std;

constexpr char kPlayerSymbol = '@';

//Constructor

Player::Player()
	: m_haskey(false)
{


}

//Deconstructor

Player::~Player() {


}

//Member Function

void Player::SetPosition(int x, int y) {

	m_position.x = x;
	m_position.y = y;

}

bool Player::HasKey() {

	return m_haskey;
}

void Player::PickupKey() {

	m_haskey = true;
}

void Player::UseKey() {

	m_haskey = false;
}

void Player::Draw() {

	cout << kPlayerSymbol;
}