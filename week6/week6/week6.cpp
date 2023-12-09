#include <iostream>
#include <assert.h>

using namespace std;

//********************************************************************************* Arrays and Function
constexpr int kSize = 5;

void Populatarray(float TheArray[], int size);
float GetAvereage(float TheArray[], int size);
void DisplayArray(float TheArray[], int size);
float GetLargestGrade(float TheArray[], int size);
float GetSmallestGrade(float TheArray[], int size);

//********************************************************************************* Multidimentional Arrays

constexpr int kHeight = 5;
constexpr int kWidth = 6;

void DisplayMap(char map[kHeight][kWidth]);

void DisplayOneDMap(char map[], int width, int height);

int GetIndexFromXY(int x, int y, int width);


//********************************************************************************* Array with assertion

void ChangeGrades(float TheArray[], int index, float newValue, int size);

//********************************************************************************* Challenge

void DisplayArray(int TheArray[], int size);
int GetLargestInteger(int TheArray[], int size);

int main()
{
    //********************************************************************************* Arrays ********************************************************************************


    float MyGrades[5] = { 90.5f, 56.5f, 60.6f, 95.5f, 59.9f }; 

    // Calculate Average

    float sum = 0;
    for (int i = 0; i < 5; i++) {

        sum += MyGrades[i];
    }
    float Avereage = sum / 5;
    cout << "My grades for fall semester are: ";
    for (int i = 0; i < 5; i++) {

        cout << MyGrades[i] << " ";
    }
    cout << endl;
    cout << "Avereage grade is: " << Avereage << endl;

    //********************************************************************************* Arrays and Function ********************************************************************


    float myGrade[kSize];
    cout << "please enter 5 grades: " << endl;
    Populatarray(myGrade, kSize);
    float average = GetAvereage(myGrade, kSize);
    cout << "the averege of the grade ";
    DisplayArray(myGrade, kSize);
    cout << "is " << average << endl;

    cout << "Largest garde is: " << GetLargestGrade(myGrade, kSize) << endl;
    cout << "Smallest garde is: " << GetSmallestGrade(myGrade, kSize) << endl;


    //********************************************************************************* Multidimentional Arrays *****************************************************************

    char Mymap[kHeight][kWidth]{  {'+', '-', '-', '-', '-', '+'},
                                  {'|', '@', ' ', ' ', ' ', '|'},
                                  {'|', ' ', ' ', ' ', ' ', '|'},
                                  {'|', ' ', ' ', ' ', 'X', '|'},
                                  {'+', '-', '-', '-', '-', '+'},
                               };

    DisplayMap(Mymap);


    char myMap[]               {   '+', '-', '-', '-', '-', '+',
                                   '|', '@', ' ', ' ', ' ', '|',
                                   '|', ' ', ' ', ' ', ' ', '|',
                                   '|', ' ', ' ', ' ', 'X', '|',
                                   '+', '-', '-', '-', '-', '+',
                               };

    DisplayOneDMap(myMap, kWidth, kHeight);

    //********************************************************************************* Array with assertion ****************************************************************

    /*ChangeGrades(myGrade, 0, 40.5f, kSize);
    ChangeGrades(myGrade, 3, 40.5f, kSize);
    ChangeGrades(myGrade, 5, 40.5f, kSize);
    ChangeGrades(myGrade, -1, 40.5f, kSize);*/

    //********************************************************************************* Challenge ****************************************************************

    int ArrayList[5] = { 40, 30, 70, 80, 30 };
    cout << "The Largest Integer in ";
    DisplayArray(ArrayList, 5);
    cout << " is: " << GetLargestInteger(ArrayList, 5);
    
}

//********************************************************************************* Arrays and Function

void Populatarray(float TheArray[], int size) {

    for (int i = 0; i < size; i++) {

        cin >> TheArray[i];
    }

}
float GetAvereage(float TheArray[], int size) {

   float sum = 0;
    for (int i = 0; i < size; i++) {

        sum += TheArray[i];
    }
    return sum / size;

}
void DisplayArray(float TheArray[], int size) {

    for (int i = 0; i < size; i++) {

        cout << TheArray[i] << " ";
    }

}
float GetLargestGrade(float TheArray[], int size) {

    float Largest = TheArray[0];

    for (int i = 1; i < size; i++) {

        if (TheArray[i] > Largest) {

            Largest = TheArray[i];
        }
    }
    return Largest;
}
float GetSmallestGrade(float TheArray[], int size) {

    float Smallest = TheArray[0];

    for (int i = 1; i < size; i++) {

        if (TheArray[i] < Smallest) {

            Smallest = TheArray[i];
        }
    }
    return Smallest;
}

//********************************************************************************* Multidimentional Arrays

void DisplayMap(char map[kHeight][kWidth]) {

    for (int y = 0; y < kHeight; y++) {

        for (int x = 0; x < kWidth; x++) {

            cout << map[y][x];
        }
        cout << endl;
    }
}

void DisplayOneDMap(char map[], int width, int height) {

    for (int y = 0; y < height; y++) {

        for (int x = 0; x < width; x++) {

            int index = GetIndexFromXY(x, y, width);
            cout << map[index];
        }
        cout << endl;
    }

}

int GetIndexFromXY(int x, int y, int width) {

    return x + y * width;
}

void ChangeGrades(float TheArray[], int index, float newValue, int size) {

    //assert(index >= 0 && index < size);
    TheArray[index] = newValue;
}

//********************************************************************************* Challenge

void DisplayArray(int TheArray[], int size) {

    for (int i = 0; i < size; i++) {

        cout << TheArray[i] << " ";
    }
}

int GetLargestInteger(int TheArray[], int size) {

    int Largest = TheArray[0];

    for (int i = 1; i < size; i++) {

        if (TheArray[i] > Largest) {

            Largest = TheArray[i];
        }
    }
    return Largest;
}