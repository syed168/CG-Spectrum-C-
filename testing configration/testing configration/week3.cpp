#include <iostream>
#include <string>
#include <time.h>



using namespace std;

int main()
{
    // ****************************************************************************************** Rational Operators *********************************************************************

    int a = 10;
    int b = 20;

    bool result;

    result = (a == b); // false
    result = (a != b); // true

    result = (a < 10); // false
    result = (a <= 10); // true
    
    result = (10 > b); // false
    result = (10 >= b); // false

    bool isEven = ((a % 2) == 0); // true

    bool isOdd = ((a % 2) != 0); // true

    isOdd = ((a % 2) == 1); // true

    bool isPositive = (b > 0); // true


    // ****************************************************************************************** If Statement *********************************************************************

    int number;

    cout << "Please enter a number: ";
    cin >> number;

    if(number > 0){

        cout << "The entered number is Positive and ";
    }

    if (number < 0) {

        cout << "The entered number is Negative and " << endl;
    }

    if (number == 0) {

        cout << "The entered number is zero " << endl;
    }

    bool IsEven = (number % 2 == 0);

    if (IsEven == true) {

        cout << "The entered number is Even " << endl;
    }

    if (IsEven == false) {

        cout << "The entered number is Odd " << endl;
    }

    // ****************************************************************************************** Else Statement *********************************************************************

    int number1;

    cout << "Please enter a number: ";
    cin >> number1;

    if (number1 > 0) {

        cout << "The entered number is Positive and " << endl;
    }

    else {
        cout << "The entered number is Negative and " << endl;
    }

    bool IS_Even = (number1 % 2 == 0);

    if (IS_Even == true) {

        cout << "The entered number is Even " << endl;
    }
    
    else {
        cout << "The entered number is Odd " << endl;
    }

    // ****************************************************************************************** Else If Statement *********************************************************************

    int grade;

    cout << "Please enter a numarical grade: ";
    cin >> grade;

    if (grade > 90) {

        cout << "A+" << endl;
    }

    else if (grade > 80) {

        cout << "A" << endl;
    }

    else if (grade > 70) {

        cout << "B" << endl;
    }

    else if (grade > 60) {

        cout << "C" << endl;
    }

    else if (grade > 50) {

        cout << "D" << endl;
    }

    else {
        cout << "F" << endl;
    }

    // ****************************************************************************************** Scope and Nested Selection Statement *********************************************************************

    cout << "Please enter a Positive number: ";
    float firstnumber;
    cin >> firstnumber;

    if (firstnumber > 0) {

        cout << "Please enter a non-zero number: ";
        float secondnumber;
        cin >> secondnumber;

        if (secondnumber != 0) {

            cout << firstnumber << "/" << secondnumber << "=" << firstnumber/secondnumber << endl;
        }
        else {
            cout << " Is zero, Goodbye" << endl;
        }
    }
    else {
        cout << firstnumber << " is not Positive, Goodbye" << endl;
    }

    // ****************************************************************************************** Logical Operator *********************************************************************

    cout << "Please enter an Integer: ";
    int num;
    cin >> num;

    bool is_Positive = (num > 0);
    bool is_Negative = (num < 0);
    bool isZero = !is_Positive && !is_Negative;
    bool isNonzero = !isZero;

    bool IS_even = (num % 2 == 0);
    bool IS_odd = !IS_even;

    if (isPositive) {

        if (IS_even) {
            cout << "is Positive and even" << endl;
        }
    }
    if (is_Positive && IS_even) {

        cout << "is Positive and even" << endl;
    }
    else if (is_Negative && IS_odd) {

        cout << "is Negative and Odd" << endl;
    }
    else {
        cout << "Invalide Output, Goodbye." << endl;
    }

    // ****************************************************************************************** Switch Statement *********************************************************************

    cout << "-------  Welcome to my program --------" << endl;
    cout << "     What whould you like to do: " << endl;
    cout << "     1) Check if a number is even. " << endl;
    cout << "     2) Check if a number is Positive. " << endl;
    cout << "     3) Check if a number is Multiple of 7. " << endl;
    cout << "Press 1, 2 or 3: " << endl;

    int Input;
    cin >> Input;

    switch (Input) {
    
    case 1:
    {
        cout << "Please enter a number: ";
        int num2;
        cin >> num2;

        if (num2 % 2 == 0) {
            cout << "is Even." << endl;
        }
        else {
            cout << "is Odd." << endl;
        }

        break;
    }

    case 2:
    {
        cout << "Please enter a number: ";
        int num2;
        cin >> num2;

        if (num2 > 0) {
            cout << "is Positive." << endl;
        }
        else {
            cout << "is not Positive." << endl;
        }
        break;
    }

    case 3:
    {
        cout << "Please enter a number: ";
        int num2;
        cin >> num2;

        bool isMultiple = (num2 % 7 == 0);

        if (isMultiple) {
            cout << "is Multiple of 7." << endl;
        }
        else {
            cout << "is not Multiple of 7." << endl;
        }
        break;
    }

    default:
    {
        cout << "Invalide Input, Goodbye. " << endl;
        break;
    }

    }

    // ****************************************************************************************** First game ****************************************************************************

    srand((unsigned)time(0));
    constexpr int kPlayMenu = 1;
    constexpr int kQuitMenu = 2;

    cout << "-------  Welcome to my number guessing game --------" << endl;
    cout << "     you have 2 guesses to guess the correct number betweeen 1 to 20. " << endl;
    cout << "     1) Play Now. " << endl;
    cout << "     2) Quit. " << endl;
    cout << "Press 1 or 2: " << endl;

    int Input1;
    cin >> Input1;

   
    switch (Input1) {

    case kPlayMenu:
    {
        cout << "Please enter your name: ";
        string name2;
        cin >> name2;

        cout << "Welcome " << name2 << endl;

        int randomNumber = 1 + rand() % 20;

        cout << randomNumber << endl;
        cout << "Guess1: " << "Alright " << name2 << " Please guess the number: " << endl;

        int guess;
        cin >> guess;

        if (guess == randomNumber) {

            cout << "You are correct!!!" << endl;
            break;
        }
        else {

            if (guess > randomNumber) {

                cout << "Your guess is too high, try again" << endl;
            }
            else {

                cout << "Your guess is too low, try again" << endl;

            }
        }

        cout << "Guess2: " << "Alright " << name2 << " Please guess the number: " << endl;

        cin >> guess;

        if (guess == randomNumber) {

            cout << "You are correct!!!" << endl;
        }
        else {

            if (guess > randomNumber) {

                cout << "Your guess is too high." << endl;
            }
            else {

                cout << "Your guess is too low." << endl;

            }

            cout << "Better luck next time." << endl;
        }


        break;
    }

    case kQuitMenu:
    {
        cout << "Goodbye! " << endl;
        break;
    }

    default:
    {
        cout << "Invalide Input, Goodbye. " << endl;
        break;
    }

    }

    // ****************************************************************************************** Challenges ****************************************************************************

    cout << "Enter the current year: ";

    int year;
    cin >> year;

    if (year % 4 == 0) {

        cout << "The current Year is a leap year." << endl;
    }
    else {
        cout << "The current Year is not a leap year." << endl;
    }

}
