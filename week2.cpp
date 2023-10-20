#include <iostream>
#include <string>

using namespace std;

int main()
{
    // ******************************************************************************************Variables and datatypes*********************************************************************

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


    // *******************************************************************************************Basic Operators****************************************************************************

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

    // ******************************************************************************************Compound Operators**************************************************************************

    int X = 10;
    X = X + 20;
    X += 20; // Same as X + 20;

    X -= 10;
    X *= 10;
    X /= 10;
    X %= 10;

    //********************************************************************************************Type Conversion*******************************************************************************

    float MyFloat = 30.5f;
    int Myint = (int)MyFloat;

    int A = 20;
    float B = A;

    int result2 = (int)(2.4 + 1.6);

    cout << result2 << endl;

    //*******************************************************************************************Age Calculator********************************************************************************

    // prompt for name
    cout << "Please enter your name: ";

    // get the name
    string name2;
    cin >> name2;

    // prompt user for date of birth
    cout << "Please enter your date of birth: ";

    // get the date of birth
    int DOB;
    cin >> DOB;

    // prompt usrr for current year
    cout << "Please enter the current year: ";

    // get the current year
    int currentyear;
    cin >> currentyear;

    // display info to the user
    int age2 = currentyear - DOB;
    cout << name2 << " You are " << age2 << " years old" << endl;

    //*******************************************************************************************Celcius Convertor********************************************************************************


     // Prompt user to enter the temp in celcius
    cout << "Please enter temparature in celcius: ";

    // Get Temp
    float celcius;
    cin >> celcius;

    // Convert celcius to fahrenheit
    float fahrenheit = (celcius * 9.0f) / 5.0f + 32;

    // Display temp in fahrenheit
    cout << celcius << " celcius in fahrenheit is " << fahrenheit << endl;

    //**************************************************************************************Centimeter to Feet and Inches****************************************************************************

    // Prompt user to enter the distance in centimeter
    cout << "Please enter the distance in CM: ";

    // Get CM
    int centimeters;
    cin >> centimeters;

    // Calculate feet
    float totalfeet = centimeters / 30.48f;
    int justfeet = (int)totalfeet;

    // Calculate inches
    int justinches = (int)((totalfeet - justfeet) * 12);

    // Display info to user
    cout << "Feet " << justfeet << endl;
    cout << "Inches " << justinches << endl;

    //********************************************************************************************Challenges*********************************************************************************************

    // prompt user for first number
    cout << "Please enter the first number: ";

    // get numbers
    int firstNum;
    cin >> firstNum;

    // prompt user for first number
    cout << "Please enter the second number: ";

    // get numbers
    int secondNum;
    cin >> secondNum;

    // prompt user for first number
    cout << "Please enter the third number: ";

    // get numbers
    int thirdNum;
    cin >> thirdNum;

    // calculate the Sum
    int sum = firstNum + secondNum + thirdNum;

    // calculate the Average
    int average = sum / 3;

    // Display the info to the user
    cout << "The Sum is " << sum << "the Average is " << average << endl;
}
