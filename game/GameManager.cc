//Autor: Peter, Nina, Tobias, Dennis

#include "GameManager.h"

#include <iostream>
#include <vector>

#include "../core/AppManager.h"
#include "../graphics/Keys.h"
#include "../menu/GameOverWindow.h"
#include "GameObject.h"
#include "Player.h"

namespace game {

GameManager* GameManager::current_game_;

GameManager::GameManager(const int width, const int height, win_condition::BaseWinCondition *winCondition) :
            win_condition_(winCondition),
            width_(width),
            height_(height)
            {

		// enforce singleton
        delete GameManager::current_game_;
		GameManager::current_game_ = this;

		// create the object arrays
		objects_by_pos_ = new std::vector<GameObject*>*[width];
		for (int i=0; i<width; i++) {
			objects_by_pos_[i] = new std::vector<GameObject*>[height];
		}
}

GameManager::~GameManager(){
	for (GameObject* obj : GetAllObjects()) {
		obj->Destroy();
	}

	for (GameObject* obj : destroyed_game_objects_) {
		delete obj;
	}

	for (int i=0; i<GetWidth(); i++) {
		delete [] objects_by_pos_[i];
	}

	delete [] objects_by_pos_;

    if (GameManager::current_game_ == this) {
		GameManager::current_game_ = nullptr;
	}
}

void GameManager::Update(double delta_time) {
	for (GameObject* obj : GetAllObjects()) {
		obj->Update(delta_time);
	}

    if (this->win_condition_)
        this->win_condition_->CheckWin();
}

GameManager& GameManager::GetCurrentGame() {
	return *GameManager::current_game_;
}

void GameManager::RemoveGameObject(GameObject& game_object) {
	std::vector<GameObject*>& object_vector =
		GetObjectsAtPos(game_object.GetX(), game_object.GetY());

	int i=0;
	for (auto it = object_vector.begin();
		i<object_vector.size(); i++, it++) {

		if (object_vector[i] == &(game_object)) {
			object_vector.erase(it);
			break;
		}
	}
}

void GameManager::DestroyGameObject(GameObject &game_object) {
	RemoveGameObject(game_object);
	destroyed_game_objects_.push_back(&game_object);
}

void GameManager::AddGameObject(GameObject& game_object) {
	std::vector<GameObject*>& object_vector = objects_by_pos_
		[game_object.GetX()][game_object.GetY()];

	object_vector.push_back(&game_object);
}

bool GameManager::ChangeObjectPosition(GameObject& game_object, int x, int y) {
	///check if position is in bounds
	if (x < 0 || x>=GetWidth() || y < 0 || y>=GetHeight()) return false;

	RemoveGameObject(game_object);
	//game_object.Destroy();

	std::vector<GameObject*>& object_vector = GetObjectsAtPos(x, y) ;

	object_vector.push_back(&game_object);
	return true;
}

std::vector<GameObject*>& GameManager::GetObjectsAtPos(int x, int y) {
	if (x < 0 || x>=GetWidth() || y < 0 || y>=GetHeight()) return empty_object_vector_;

	return objects_by_pos_[x][y];
}

std::vector<GameObject*> GameManager::GetAllObjects() {
	std::vector<GameObject*> all_objects;

	for (int x=0; x<GetWidth(); x++) {
		for (int y=0; y<GetHeight(); y++) {
			for (GameObject* game_object : GetObjectsAtPos(x, y)) {
				all_objects.push_back(game_object);
			}
		}
	}
	return all_objects;
}

int GameManager::GetWidth() const {
	return width_;
}

int GameManager::GetHeight() const {
	return height_;
}

void GameManager::RemovePlayer(Player &player) {
    int i=0;

    for (auto it = players_.begin();
         i<players_.size(); i++, it++) {

        if (players_[i] == &(player)) {

            players_.erase(it);
            break;
        }
    }
}

void GameManager::AddPlayer(Player* player) {
    this->AddGameObject(*player);
    players_.push_back(player);
}

std::vector<Player*> GameManager::GetPlayers() {
    return players_;
}

void GameManager::AddDestructibleBlock() {
    ++destructible_block_count_;
}

void GameManager::RemoveDestructibleBlock() {
    --destructible_block_count_;
}

int GameManager::GetDestructibleBlockCount() {
    return destructible_block_count_;
}


} // namespace game
