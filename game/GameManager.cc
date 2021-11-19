//
// Created by Dennis Neuhaus on 15.11.21.
//

#include "GameManager.h"

namespace game {

GameManager* GameManager::current_game_;

GameManager::GameManager(){}

GameManager::~GameManager(){}

void GameManager::Update(double delta_time) {}

GameManager& GameManager::GetCurrentGame() {
	return * GameManager::current_game_;
}

void GameManager::RemoveGameObject(GameObject& game_object) {}

void GameManager::AddGameObject(GameObject& game_object) {}

void GameManager::ChangeObjectPosition(GameObject& game_object, int x, int y) {}

GameObject *GameManager::GetObjectsAtPos(int x, int y) { return nullptr;}

GameObject *GameManager::GetAllObjects() { return nullptr;}

} //namespace game
