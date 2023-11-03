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

void DisplayGameOver(int randomNumber, string name, int tries);

// ******************************* Extra Challenges

int CharConverter(int numbers);
char DecConverter(char number);

int Fibonacci(int n);

int main()
{
    // ***************************************************************************************** First Game With Funtions ****************************************************************************

    srand((unsigned)time(0));

    bool keepPlaying = true;

    do {

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
            keepPlaying = false;
            break;
        }

        default:
        {
            system("cls");
            cout << "Invalide Input, Try again. " << endl;
            break;
        }

        }

    } while (keepPlaying);

    
    // ***************************************************************************************** Challenges ***************************************************************************

    cout << "Enter a positive number: ";

    int numbers;
    cin >> numbers;

    for (int i = 1; i <= numbers; i++) {

        if (numbers % i == 0) {

            cout << i << " " << endl;
        }
        
    }

    // ***************************************************************************************** Extra Challenges ***************************************************************************
     

    cout << "Enter a charecter: ";
    
    CharConverter(numbers);

    cout << "Enter a integer: ";

    DecConverter(numbers);

    int t1 = 0, t2 = 1, next = 0, n;

    cout << "Enter a positive number: ";
    cin >> n;

    // To displays first two terms which is always 0 and 1
    cout << "Fibonacci Series: " << t1 << ", " << t2 << ", ";

    next = t1 + t2;

    while (next <= n) {
        cout << next << ", ";
        t1 = t2;
        t2 = next;
        next = t1 + t2;
    }


}

int DisplayWelcomeMessage() {

    int Input;

    do {

        cout << "-------  Welcome to my number guessing game --------" << endl;
        cout << "     you have infinite guesses to guess the correct number betweeen 1 to 20. " << endl;
        cout << "     1) Play Now. " << endl;
        cout << "     2) Quit. " << endl;
        cout << "Press 1 or 2: " << endl;


        cin >> Input;

        if (cin.fail()) {

            cin.clear();
            cin.ignore(100, '\n');
            system("cls");
            cout << "Invalid entry, try again!" << endl;

        }
        else {
            break;
        }

    } while (true);

    return Input;
}

void DisplayMessage(string message) {

    cout << message << endl;
}

void PlayGame() {

    system("cls");
    string name = GetUserName();
    system("cls");

    cout << "Welcome " << name << endl;

    bool isGameOver = false;
    

    do {

        int randomNumber = 1 + rand() % 20;
        cout << randomNumber << endl;

        bool DidGuessCorrect = false;

        int tries = 1;

        do {

            int guess = GetGuess(tries, name);
            bool DidGuessCorrect = ReviewGuess(guess, randomNumber);

            if (DidGuessCorrect) {
                break;
            }
            tries++;

        } while (!DidGuessCorrect);

            DisplayGameOver(randomNumber, name, tries);
            
            isGameOver = true;

    } while (!isGameOver);

}

string GetUserName() {

    cout << "Please enter your name: ";
    string name;
    cin >> name;
    return name;
}

int GetGuess(int turn, string name) {

    int guess;
    
    do{

        cout << "Guess " << turn << " Alright " << name << " Please guess the number: " << endl;

        cin >> guess;

        if (cin.fail()) {

            cin.clear();
            cin.ignore(100, '\n');
            system("cls");
            cout << "Invalid entry, try again!" << endl;

        }
        else {
            break;
        }

    } while (true);

    
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


void DisplayGameOver(int randomNumber, string name, int tries) {

    cout << "Good Job " << name << " it took you " << tries << " tries" << endl;
    cout << "to guess the number " << randomNumber << endl;
}

// ******************************* Extra Challenges

int CharConverter(int numbers) {

    char charecters;
    cin >> charecters;

    char c = charecters;
    cout << "Implicit conversion from Char to ";
    numbers = c;
    cout << "Decimal : " << numbers << endl;

    return c;

}

char DecConverter(char number) {

    int charecters;
    cin >> charecters;

    int c = charecters;
    cout << "Implicit conversion from Char to ";
    number = c;
    cout << "Decimal : " << number << endl;

    return c;

}

int Fibonacci(int n) {


    if (n <= 1) {

        return n;
    }
    else {

        return Fibonacci(n - 1) + Fibonacci(n - 2);
    }
}