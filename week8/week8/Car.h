#pragma once
#include<string>
class Car {

	//Member Variables
	int m_year;
	int m_miles;
	std::string m_brand;


public:

	//Constructors
	Car();
	Car(int year, int miles, std::string brand);

	//Deconstructors
	~Car();

	//Member Functions
	void Display();
	void Driver(int miles);


};