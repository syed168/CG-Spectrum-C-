#include <iostream>

using namespace std;

// ****************************************************************************************** Functions ************************************************************************************

// function declerations

void PrintMessage(string message);

int Add(int num1, int num2);

float Max(float n1, float n2, float n3);

bool is_Even(int number);
bool is_Odd(int number);

// ************** Passing By Reference

void AnalizeNumber(int number, bool& isEven, bool& isOdd,bool& isZero, bool& isPositive, bool& isNegative);

// ************** Local & Global Scope

bool g_testing = false;

// ************** Recursion

int power(int base, int exponent);

// ************** Function overloading

int sum(int a, int b);
float sum(float a, float b);
double sum(double a, double b);

// Or

template < typename T>
T sum(T a, T b);

void DisplayMessage(string message);
void DisplayMessage(string message, int a);
void DisplayMessage(string message, float a);
void DisplayMessage(string message, double a);

// Or
// Template Function

template < typename T>
void DisplayMessage(string message, T number);

template < typename T> 
T sum(T v);  // For Only One Parameter

template < typename T, typename...Args>
T sum(T first, Args...rest); // For To Take Any Amount Of Parameters


int main()
{
 // function calls

    PrintMessage("Testing Add");

    int r = Add(1, 2);
    cout << "1 + 2 = " << r << endl;
    // Or 
    cout << "2 + 3 = " << Add(2, 3) << endl;

    PrintMessage("Testing Max");

    cout << "The highest number in 20.6f, 30.8f, 40.4f is " << Max(20.6f, 30.8f, 40.4f) << endl;

    PrintMessage("Testing Even/Odd");
    
    int number = 11;
    bool IsEven = is_Even(number);
    bool IsOdd = is_Odd(number);

    if (IsEven) {
        cout << "number is even" << endl;
    }
    if (IsOdd) {
        cout << "number is odd" << endl;
    }
    
    // ****************************************************************************************** Passing By Reference ************************************************************************************

    int number2 = -21;
    bool isEven = false;
    bool isOdd = false;
    bool isZero = false;
    bool isPositive = false;
    bool isNegative = false;


     AnalizeNumber(number2, isEven, isOdd, isZero, isPositive, isNegative);

     cout << "Analizing number: " << number2 << endl;

     if (isEven) {
         cout << "is even" << endl;
     }
     if (isOdd) {
         cout << "is odd" << endl;
     }
     if (isZero) {
         cout << "is zero" << endl;
     }
     if (isPositive) {
         cout << "is positive" << endl;
     }
     if (isNegative) {
         cout << "is negative" << endl;
     }


     // ****************************************************************************************** Local & Global Scope ************************************************************************************
     
     cout << "Testing global variable: ";
     
     if (g_testing == false) {
         cout << "The testing was a success!" << endl;
     }
     else {
         cout << "The testing was a failure!" << endl;
     }
     
     // ****************************************************************************************** Recursion ************************************************************************************
     
     cout << power(3, 0) << endl;
     cout << power(3, 1) << endl;
     cout << power(3, 2) << endl;
     cout << power(3, 3) << endl;
     cout << power(3, 4) << endl;
     cout << power(3, 5) << endl;
     cout << power(3, 6) << endl;
     cout << power(3, 7) << endl;
     cout << power(3, 8) << endl;

     // ****************************************************************************************** Function overloading ************************************************************************************

     int i = sum(1, 2, 3);
     float f = sum(3.3f, 6.6f, 4.32f, 55.4f);
     double d = sum(4.4, 2.4);


     DisplayMessage("Testing Overloaded Functions.");
     DisplayMessage("Integer Addition = ", i);
     DisplayMessage("Float Addition = ", f);
     DisplayMessage("Double Addition = ", d);


}

// function definitions

void PrintMessage(string message){

    cout << message << endl;
}

int Add(int num1, int num2) {
    
    int r = num1 + num2;

    return r;
}

float Max(float n1, float n2, float n3){

    float max = n1;

    if(n2 > max){
        max = n2;
    }

    if (n3 > max) {
        max = n3;
    }
    return max;

}

bool is_Even(int number) {

    if (number % 2 == 0) {
        return true;
    }
    else {
        return false;
    }
    
}

bool is_Odd(int number) {
    
    return !is_Even(number);
}

// ************** Passing By Reference

void AnalizeNumber(int number, bool& isEven, bool& isOdd, bool& isZero, bool& isPositive, bool& isNegative) {

    if (number % 2 == 0) {
        isEven = true;
        isOdd = false;
    }
    else {
        isEven = false;
        isOdd = true;
    }
    if (number > 0) {
        isNegative = false;
        isPositive = true;
        isZero = false;
    }
    else if (number < 0) {
        isNegative = true;
        isPositive = false;
        isZero = false;
    }
    else {
        isNegative = false;
        isPositive = false;
        isZero = true;
    }
}

// ************** Recursion

int power(int base, int exponent) {

    if (exponent == 0) {
        return 1;
    }
    else {
        return base * power(base, exponent - 1);
    }
}

// ************** Function overloading

int sum(int a, int b) {

    return a + b;
}

float sum(float a, float b) {

    return a + b;
}

double sum(double a, double b) {

    return a + b;
}

// Or

template < typename T>
T sum(T a, T b) {

    return a + b;
}

void DisplayMessage(string message) {
  
    cout << message << endl;
}


void DisplayMessage(string message, int number) {

    cout << message << number << endl;
}

void DisplayMessage(string message, float number) {

    cout << message << number << endl;
}

void DisplayMessage(string message, double number) {

    cout << message << number << endl;
}

// Or
// Template Function

template < typename T>
void DisplayMessage(string message, T number) {

    cout << message << number << endl;
}

template < typename T>
T sum(T v) { 

    return v;  // For Only One Parameter
}

template < typename T, typename...Args>
T sum(T first, Args...rest) {

    return first + sum(rest...); // For To Take Any Amount Of Parameters
}