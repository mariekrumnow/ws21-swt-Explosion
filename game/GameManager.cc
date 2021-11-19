//
// Created by Dennis Neuhaus on 15.11.21.
//

#include "GameManager.h"

namespace game {

GameManager::GameManagerWindow(){}

GameManager::~GameManagerWindow(){}

void GameManager::Update(double delta_time) {}

GameManager &GameManager::GetCurrentGame() {}

void GameManager::RemoveGameObject(GameObject game_object) {}

void GameManager::AddGameObject(GameObject game_object) {}

void GameManager::ChangeObjectPosition(GameObject game_object, int x, int y) {}

GameObject *GameManager::GetObjectsAtPos(int x, int y) {}

GameObject *GameManager::GetAllObjects() {}

} //namespace game