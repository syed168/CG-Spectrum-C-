#include <iostream>
#include <string>

using namespace std;

int main()
{
    // Variables and datatypes
    int age;
    float weight;
    double distance;
    bool isAlive;
    char initial;
    string name;

    age = 20;
    weight = 190.5f;
    distance = 1212.987;
    isAlive = true;
    initial = 's';
    name = "syed";
    
    cout << "my name is " << name << " and I am " << age << endl;
    cout << "Am I alive " << isAlive << endl;

    int newage;
    newage = age;

    newage = 25;


    // Basic Operators

    int a = 10;
    int b = 3;

    int add = a + b;
    int subtract = a - b;
    int multiply = a * b;
    int division = a / b;
    int mod = a % b;
    float div2 = 10 / 3.0f;

    cout << div2 << endl;

    int result = (1 + 2) * (3 + 4);

    cout << result << endl;

    // Compound Operators

    int X = 10;
    X = X + 20;
    X += 20; // Same as X + 20;

    X -= 10;
    X *= 10;
    X /= 10;
    X %= 10;

    //Type Conversion

    float MyFloat = 30.5f;
    int Myint = (int)MyFloat;

    int A = 20;
    float B = A;

    int result2 = (int)(2.4 + 1.6);

    cout << result2 << endl;
    

}
