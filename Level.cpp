#include <iostream>
#include <fstream>
#include "Level.h"

using namespace std;

constexpr char WAL = (char)219;
constexpr char KEY = (char)232;
constexpr char DOR = (char)179;
constexpr char GOL = (char)36;

Level::Level() 
	: m_pLevelData(nullptr)
	 ,m_height(0)
	 ,m_width(0)
{


}
Level::~Level() {

	if (m_pLevelData != nullptr) {

		delete[] m_pLevelData;
		m_pLevelData = nullptr;
	}
}

bool Level::Load(std::string levelName, int* playerX, int* playerY) {

    levelName.insert(0, "../");
    ifstream levelFile;
    levelFile.open(levelName);
    if (!levelFile) {
        cout << "Opening file failed!" << endl;
        return false;
    }
    else {

        constexpr int TempSize = 25;
        char temp[TempSize];

        levelFile.getline(temp, TempSize, '\n');
        m_width = atoi(temp);

        levelFile.getline(temp, TempSize, '\n');
        m_height = atoi(temp);

        m_pLevelData = new char[m_width * m_height];
        levelFile.read(m_pLevelData, (long long)m_width * (long long)m_height);

        bool anyWarning = Convert(playerX, playerY);
        if (anyWarning) {

            cout << "There were warnings in level data, see above." << endl;
            system("pause");
        }

        return true;
    }
}
void Level::Draw(int x, int y) {

    int index = GetIndexFromCoordinates(x, y);
    cout << m_pLevelData[index];
}

bool Level::IsSpace(int x, int y) {

    return m_pLevelData[GetIndexFromCoordinates(x, y)] == ' ';
}
bool Level::IsDoor(int x, int y) {

    return m_pLevelData[GetIndexFromCoordinates(x, y)] == DOR;
}
bool Level::IsKey(int x, int y) {

    return m_pLevelData[GetIndexFromCoordinates(x, y)] == KEY;
}
bool Level::IsGoal(int x, int y) {

    return m_pLevelData[GetIndexFromCoordinates(x, y)] == GOL;
}

void Level::PickupKey(int x, int y) {

    m_pLevelData[GetIndexFromCoordinates(x, y)] = ' ';
}
void Level::OpenDoor(int x, int y) {

    m_pLevelData[GetIndexFromCoordinates(x, y)] = ' ';
}

bool Level::Convert(int* playerX, int* playerY) {

    bool anyWarning = false;
    for (int y = 0; y < m_height; y++) {

        for (int x = 0; x < m_width; x++) {

            int index = GetIndexFromCoordinates(x, y);

            switch (m_pLevelData[index])
            {
            case '+':
            case '-':
            case '|':
                m_pLevelData[index] = WAL;
                break;
            case '*':
                m_pLevelData[index] = KEY;
                break;
            case 'D':
                m_pLevelData[index] = DOR;
                break;
            case 'X':
                m_pLevelData[index] = GOL;
                break;
            case '@':
                m_pLevelData[index] = ' ';
                if (playerX != nullptr && playerY != nullptr)
                {
                    *playerX = x;
                    *playerY = y;
                }
                break;
            case ' ':
                break;
            default:
                cout << "Invalide charecter in level file: " << m_pLevelData[index] << endl;
                anyWarning = true;
                break;
            }
        }
    }


    return anyWarning;
}
int Level::GetIndexFromCoordinates(int x, int y) {

    return x + y * m_width;

}