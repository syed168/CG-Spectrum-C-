#include <iostream>
#include <string>
#include <time.h>


using namespace std;

constexpr int g_kPlayMenu = 1;
constexpr int g_kQuitMenu = 2;

void DisplayMessage(string message);

int DisplayWelcomeMessage();

void PlayGame();

string GetUserName();

int GetGuess(int turn, string name);

bool ReviewGuess(int guess, int randomNumber);

void DisplayGameOver(int randomNumber, string name);

// ******************************* Challenges


int Cube(int number);


int main()
{
    // ***************************************************************************************** First Game With Funtions ****************************************************************************

    srand((unsigned)time(0));



    int Input = DisplayWelcomeMessage();


    switch (Input) {

    case g_kPlayMenu:
    {

        PlayGame();
        break;
    }

    case g_kQuitMenu:
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
    // ***************************************************************************************** Challenges *********************************************************************************

    int number;
    cout << "Type the number to be cubed: ";
    cin >> number;
    int num = Cube(number);
    cout << "The cube of the number is: " << num; //Calling Function

}

int DisplayWelcomeMessage() {

    cout << "-------  Welcome to my number guessing game --------" << endl;
    cout << "     you have 2 guesses to guess the correct number betweeen 1 to 20. " << endl;
    cout << "     1) Play Now. " << endl;
    cout << "     2) Quit. " << endl;
    cout << "Press 1 or 2: " << endl;

    int Input;
    cin >> Input;
    return Input;
}

void DisplayMessage(string message) {

    cout << message << endl;
}

void PlayGame() {

    cout << "Please enter your name: ";
    string name;
    cin >> name;

    cout << "Welcome " << name << endl;

    int randomNumber = 1 + rand() % 20;
    cout << randomNumber << endl;
    int guess = GetGuess(1, name);
    bool DidGuessCorrect = ReviewGuess(guess, randomNumber);

    if (DidGuessCorrect == false) {

        guess = GetGuess(2, name);
        ReviewGuess(guess, randomNumber);
        if (!DidGuessCorrect == false) {
            DisplayGameOver(randomNumber, name);
        }

    }

}

string GetUserName() {

    cout << "Please enter your name: ";
    string name;
    cin >> name;
    return name;
}

int GetGuess(int turn, string name) {

    cout << "Guess " << turn << " Alright " << name << " Please guess the number: " << endl;
    int guess;
    cin >> guess;
    return guess;

}

bool ReviewGuess(int guess, int randomNumber) {

    if (guess == randomNumber) {

        cout << "You are correct!!!" << endl;
        return true;
    }
    else {
        if (guess > randomNumber) {

            cout << "Your guess is too high" << endl;
        }
        else {

            cout << "Your guess is too low" << endl;
            return false;

        }
    }

}


void DisplayGameOver(int randomNumber, string name) {

    cout << "Too bad " << name << " the number was " << randomNumber << endl;
    cout << "Better luck next time!" << endl;
}

// ******************************* Challenges

int Cube(int number) {

    return (number * number * number);
}
