#include <iostream>
#include "Car.h"

int main()
{
    Car myCar(2018, 300, "BMW");
    myCar.Display();
    myCar.Driver(200);
    myCar.Display();
}