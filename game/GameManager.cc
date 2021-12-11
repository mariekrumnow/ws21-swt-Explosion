//Autor: Peter, Nina, Tobias, Dennis

#include "GameManager.h"

#include <vector>
#include "block/IndestructibleBlock.h"
#include "block/DestructibleBlock.h"
#include "Player.h"

#include <iostream>

#include "GameObject.h"


namespace game {

GameManager* GameManager::current_game_;

GameManager::GameManager(const int width, const int height, const int indest_prop, const int playerCount, graphics::PlayerKeys* player_keys, win_condition::BaseWinCondition *winCondition) :
            width_(width),
            height_(height),
            playerCount_(playerCount),
            winCondition_(winCondition)
            {
		width_ = width;
		height_ = height;

		// enforce singleton
        delete GameManager::current_game_;


		GameManager::current_game_ = this;

		// create the object arrays
		objects_by_pos_ = new std::vector<GameObject*>*[width];
		for (int i=0; i<width; i++) {
			objects_by_pos_[i] = new std::vector<GameObject*>[height];
		}

        // generate map
        this->GenerateMap(indest_prop);

        // player
        Player* players[playerCount_];

        for (int i = 0; i < playerCount_; i++) {
            if (i == 0) {
                players[i] = Player::CreatePlayer(1,1, player_keys[i], graphics::player1Tiles);
            }
            else if (i == 1) {
                players[i] = Player::CreatePlayer((width_-2),(height_-2), player_keys[i], graphics::player2Tiles);
            }
            else if (i == 2) {
                players[i] = Player::CreatePlayer(1,(height_-2), player_keys[i], graphics::player1Tiles);
            }
            else if (i == 3) {
                players[i] = Player::CreatePlayer((width_-2), 1, player_keys[i], graphics::player2Tiles);
            }
        }

}

GameManager::~GameManager(){
	if (GameManager::current_game_ == this) {
		GameManager::current_game_ = nullptr;
	}

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
}

void GameManager::Update(double delta_time) {
	for (GameObject* obj : GetAllObjects()) {
		obj->Update(delta_time);
	}

    if (this->winCondition_->checkWin()) {
        core::AppManager::GetAppManager().Quit();
    }
}

GameManager& GameManager::GetCurrentGame() {
	return * GameManager::current_game_;
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

int GameManager::GetPlayerCount() const {
    return playerCount_;
}

void GameManager::GenerateMap(const int indes_prop) const {

    obstacles::IndestructibleBlock::CreateIndestructibleBlock(0,0);

    // Outer walls (minus 0,0: somehow won't be placed)
    for (int i=0; i<width_; i++) {
        obstacles::IndestructibleBlock::CreateIndestructibleBlock(i,0); // Upper wall
        obstacles::IndestructibleBlock::CreateIndestructibleBlock(i,(height_-1)); // Lower wall

        if (i==0 || i==(width_-1)) { // Left or right wall
            for (int j=1; j <(height_-1); j++) {
                obstacles::IndestructibleBlock::CreateIndestructibleBlock(i,j);
            }
        }
    }


    // Indestructible blocks in the middle
    for (int i=2; i<=(width_-3); i+=2) {
        for(int j=2; j<=(height_-3); j+=2){
            obstacles::IndestructibleBlock::CreateIndestructibleBlock(i,j);
        }
    }



    // Randomly placed destructible blocks
    for (int i=1; i<width_-1; i++) {
        for (int j=1; j<height_-1; j++) {
            // Is a destructible block allowed?

            if ((i%2 || j%2) && !(
                    ( (i == (1) && j == (1)) || (i == (1) && j == (2)) || (i == (2) && j == (1)) ) ||                                               // top left
                    ( (i == (1) && j==(height_-2)) || (i == (1) && j ==(height_-3)) || (i == (2) && j == (height_-2)) ) ||                          // bottom left
                    ( (i == (width_-3) && j == (1)) || (i == (width_-2) && j == (1)) || (i == (width_-2) && j == (2)) ) ||                          // top right
                    ( (i == (width_-3) && j == (height_-2)) || ( i == (width_-2)) && (j == (height_-2)) || (i == (width_-2) && (j == (height_-3)))) // bottom right
                    )) {
                if (rand()%100 <= indes_prop) { // Places destructible block with a 85% chance
                    obstacles::DestructibleBlock::CreateDestructibleBlock(i,j);
                }
            }

        }

    }

}

void GameManager::ReducePlayerCount() {
    this->playerCount_--;
}

} // namespace game
