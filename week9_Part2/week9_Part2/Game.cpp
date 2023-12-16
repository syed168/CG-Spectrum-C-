#include "Game.h"
#include <iostream>
#include<conio.h>
#include<windows.h>

#include "Enemy.h"
#include "Key.h"
#include "Door.h"
#include "Goal.h"
#include "Money.h"

using namespace std;


constexpr int kArrowInput = 224;
constexpr int kLeftArrow = 75;
constexpr int kRightArrow = 77;
constexpr int kUpArrow = 72;
constexpr int kDownArrow = 80;
constexpr int kEscapeKey = 27;


Game::Game() 
	: m_isGameOver(false)
    
{


}

Game::~Game() {


}

bool Game::Load() {

	return m_level.Load("Level1.txt", m_player.GetXPositionPointer(), m_player.GetYPositionPointer());
}

void Game::Run() {

	Draw();

	m_isGameOver = Update();

	if (m_isGameOver) {

		Draw();
	}
}


bool Game::IsGameOver() {

	return m_isGameOver;
}

bool Game::Update() {

    int input = _getch();
    int arrowInput = 0;
    int newPlayerX = m_player.GetXPosition();
    int newPlayerY = m_player.GetYPosition();
    
    //One Of the arrow keys were pressed

    if (input == kArrowInput) {

        arrowInput = _getch();
     }
                
    if ((input == kArrowInput && arrowInput == kLeftArrow) || 
        (char)input == 'A' || (char)input == 'a') {

        newPlayerX--;
    }
    else if ((input == kArrowInput && arrowInput == kRightArrow) || 
        (char)input == 'D' || (char)input == 'd') {

        newPlayerX++;
    }
    else if ((input == kArrowInput && arrowInput == kUpArrow) ||
        (char)input == 'W' || (char)input == 'w') {

        newPlayerY--;
    }
    else if ((input == kArrowInput && arrowInput == kDownArrow) ||
        (char)input == 'S' || (char)input == 's') {

        newPlayerY++;
    }
    else if (input == kEscapeKey) {

        m_UserQuit = true;
        return true;
    }       
    else if ((char)input == 'Z' || (char)input == 'z') {

        m_player.DropKey();
    }
       
     // If position never changed
        
    if (newPlayerX == m_player.GetXPosition() && newPlayerY == m_player.GetYPosition()) {

        return false;
    }
    else {

        return HandleCollision(newPlayerX, newPlayerY);
    }
            
}

// Returns true if player beats the game or loses all lives
bool Game::HandleCollision(int newPlayerX, int newPlayerY) {

    PlacableActor* collidedActor = m_level.UpdateActors(newPlayerX, newPlayerY);

    if (collidedActor != nullptr && collidedActor->IsActive()) {

        Enemy* collidedEnemy = dynamic_cast<Enemy*>(collidedActor);
        if (collidedEnemy) {

            collidedEnemy->Remove();
            m_player.SetPosition(newPlayerX, newPlayerY);

            m_player.DecrementLives();
            if (m_player.GetLives() < 0) {

                return true;
            }
        }
        Money* collidedMoney = dynamic_cast<Money*>(collidedActor);
        if (collidedMoney) {

            collidedMoney->Remove();
            m_player.AddMoney(collidedMoney->GetWorth());
            m_player.SetPosition(newPlayerX, newPlayerY);
        }
        Key* collidedKey = dynamic_cast<Key*>(collidedActor);
        if (collidedKey) {

            if (!m_player.HasKey()) {

                m_player.PickupKey(collidedKey);
                collidedKey->Remove();
                m_player.SetPosition(newPlayerX, newPlayerY);
                //PlayKeyPickupSound();
            }
        }
        Door* collidedDoor = dynamic_cast<Door*>(collidedActor);
            
        if (collidedDoor) {

            if (!collidedDoor->IsOpen()) {

                if (m_player.HasKey(collidedDoor->GetColor())) {

                    collidedDoor->Open();
                    collidedDoor->Remove();
                    m_player.UseKey();
                    m_player.SetPosition(newPlayerX, newPlayerY);
                    // (PlayDoorOpenSound();
                }
                else {

                    //PlayDoorClosedSound();
                }
            }
            else {

                m_player.SetPosition(newPlayerX, newPlayerY);
            }
        }
        Goal* collidedGoal = dynamic_cast<Goal*>(collidedActor);

        if (collidedGoal) {

            collidedGoal->Remove();
            m_player.SetPosition(newPlayerX, newPlayerY);
            return true;
        }
            
    }
    else if (m_level.IsSpace(newPlayerX, newPlayerY)) { // no collision

        m_player.SetPosition(newPlayerX, newPlayerY);
    }
    else if (m_level.IsWall(newPlayerX, newPlayerY)) {

        // wall collision, do nothing.
    }

    return false;
}


void Game::Draw() {


    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    system("cls");

    m_level.Draw();

    // Set cursor position for player
    COORD actorCursorPosition;
    actorCursorPosition.X = m_player.GetXPosition();
    actorCursorPosition.Y = m_player.GetYPosition();
    SetConsoleCursorPosition(console, actorCursorPosition);
    m_player.Draw();

    // Set the cursor to the end of the level
    COORD currentCursorPosition;
    currentCursorPosition.X = 0;
    currentCursorPosition.Y = m_level.GetHeight();
    SetConsoleCursorPosition(console, currentCursorPosition);
}