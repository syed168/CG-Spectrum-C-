#include "Car.h"
#include <iostream>

using namespace std;

//Construtors

Car::Car() 
	: m_year(2019)
    , m_miles (0)
    , m_brand  ("unspecified")

{

}

Car::Car(int year, int miles, std::string brand)

     : m_year(year)
     , m_miles(miles)
     , m_brand(brand)

    {

    }

//Deconstructors
Car::~Car() {


}

//Member Functions
void Car::Display() {

    cout << "Brand: " << m_brand << endl;
    cout << "Year: " << m_year << endl;
    cout << "Miles: " << m_miles << endl;
}
void Car::Driver(int miles) {

    m_miles = m_miles + miles;
}