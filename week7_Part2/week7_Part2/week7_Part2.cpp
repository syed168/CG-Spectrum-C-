#include <iostream>
#include<conio.h>
#include<windows.h>
#include<fstream>

using namespace std;

constexpr char kPlayerSymbol = '@';
constexpr char WAL = 219;
constexpr char KEY = 232;
constexpr char DOR = 179;
constexpr char GOL = 36;

constexpr int kOpenDoorColour = 10;
constexpr int kClosedDoorColour = 12;
constexpr int kRegularColour = 7;


int GetIndexFromCoordinates(int x, int y, int width);
void DrawLevel(char level[], int width, int height, int playerX, int playerY, bool PlayerHasKey);
bool UpdatePlayerPosition(char level[], int& playerX, int& playerY, int width, bool& playerHasKey);

void PlayDoorClosedSound();
void PlayDoorOpenSound();
void PlayKeyPickupSound();
void PlayWinSound();

char* LoadLevel(string levelName, int& width, int& height);
bool ConvertLevel(char* level, int width, int height, int& playerX, int& playerY);

int main()
{

    int width = 25;
    int height = 15;


    char* LevelArray = LoadLevel("Level1.txt", width, height);

    int playerX = 1;
    int playerY = 1;
    bool anyWarning = ConvertLevel(LevelArray, width, height, playerX, playerY);
    if (anyWarning) {

        cout << "There were warnings in level data, see above." << endl;
        system("pause");
    }

    bool playerHasKey = false;
    bool gameOver = false;


    while (!gameOver) {

        system("cls");
        DrawLevel(LevelArray, width, height, playerX, playerY, playerHasKey);
        gameOver = UpdatePlayerPosition(LevelArray, playerX, playerY, width, playerHasKey);
    }
    system("cls");
    DrawLevel(LevelArray, width, height, playerX, playerY, playerHasKey);
    cout << "YOU WON!!!" << endl;
    PlayWinSound();

    delete[] LevelArray;
}

int GetIndexFromCoordinates(int x, int y, int width) {

    return x + y * width;
}

void DrawLevel(char level[], int width, int height, int playerX, int playerY, bool PlayerHasKey) {

    for (int y = 0; y < height; y++) {

        for (int x = 0; x < width; x++) {

            if (playerX == x && playerY == y) {

                cout << kPlayerSymbol;
            }
            else {

                int index = GetIndexFromCoordinates(x, y, width);
                HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
                if (level[index] == DOR) {

                    if (PlayerHasKey) {
                        SetConsoleTextAttribute(console, kOpenDoorColour);
                    }
                    else {
                        SetConsoleTextAttribute(console, kClosedDoorColour);
                    }
                }
                else {
                    SetConsoleTextAttribute(console, kRegularColour);
                }
                cout << level[index];
            }

        }
        cout << endl;
    }
}

bool UpdatePlayerPosition(char level[], int& playerX, int& playerY, int width, bool& playerHasKey) {

    char input = _getch();

    int newPlayerX = playerX;
    int newPlayerY = playerY;

    switch (input) {
    case 'w':
    case 'W':
    {
        newPlayerY--;
        break;
    }
    case 's':
    case 'S':
    {
        newPlayerY++;
        break;
    }
    case 'a':
    case 'A':
    {
        newPlayerX--;
        break;
    }
    case 'd':
    case 'D':
    {
        newPlayerX++;
        break;
    }
    default:
        break;
    }

    int index = GetIndexFromCoordinates(newPlayerX, newPlayerY, width);

    if (level[index] == ' ') {

        playerX = newPlayerX;
        playerY = newPlayerY;
    }
    else if (level[index] == KEY) {

        playerHasKey = true;
        level[index] = ' ';
        playerX = newPlayerX;
        playerY = newPlayerY;
        PlayKeyPickupSound();
    }
    else if (level[index] == DOR && playerHasKey) {

        level[index] = ' ';
        playerHasKey = false;
        playerX = newPlayerX;
        playerY = newPlayerY;
        PlayDoorOpenSound();

    }
    else if (level[index] == DOR && !playerHasKey) {

        PlayDoorClosedSound();
    }
    else if (level[index] == GOL) {

        level[index] = ' ';
        playerX = newPlayerX;
        playerY = newPlayerY;
        return true;
    }
    return false;
}

void PlayDoorClosedSound() {

    Beep(500, 75);
    Beep(500, 75);
}
void PlayDoorOpenSound() {

    Beep(1397, 200);
}
void PlayKeyPickupSound() {

    Beep(1568, 200);
}
void PlayWinSound() {

    Beep(1568, 200);
    Beep(1568, 200);
    Beep(1568, 200);
    Beep(1245, 1000);
    Beep(1397, 200);
    Beep(1397, 200);
    Beep(1397, 200);
    Beep(1175, 1000);
}

char* LoadLevel(string levelName, int& width, int& height) {

    levelName.insert(0, "../");
    ifstream levelFile;
    levelFile.open(levelName);
    if (!levelFile) {
        cout << "Opening file failed!" << endl;
        return nullptr;
    }
    else {

        constexpr int TempSize = 25;
        char temp[TempSize];

        levelFile.getline(temp, TempSize, '\n');
        width = atoi(temp);

        levelFile.getline(temp, TempSize, '\n');
        height = atoi(temp);

        char* levelData = new char[width * height];
        levelFile.read(levelData, width * height);

        return levelData;

    }

}
bool ConvertLevel(char* level, int width, int height, int& playerX, int& playerY) {

    bool anyWarning = false;
    for (int y = 0; y < height; y++) {

        for (int x = 0; x < width; x++) {

            int index = GetIndexFromCoordinates(x, y, width);

            switch (level[index])
            {
            case '+':
            case '-':
            case '|':
                level[index] = WAL;
                break;
            case '*':
                level[index] = KEY;
                break;
            case 'D':
                level[index] = DOR;
                break;
            case 'X':
                level[index] = GOL;
                break;
            case '@':
                level[index] = ' ';
                playerX = x;
                playerY = y;
                break;
            case ' ':
                break;
            default:
                cout << "Invalide charecter in level file: " << level[index] << endl;
                anyWarning = true;
                break;
            }
        }
    }


    return anyWarning;
}