//
// Created by Dennis Neuhaus on 15.11.21.
//

#ifndef BOMBERMAN_GAMEMANAGER_H
#define BOMBERMAN_GAMEMANAGER_H

#include <vector>

#include "GameObject.h"
#include "../core/AppManager.h"

namespace game {

class GameManager {
public:
    GameManager(const int width, const int height);
    ~GameManager();

    void Update(double delta_time);
    static GameManager& GetCurrentGame();
    void RemoveGameObject(GameObject& game_object);
    void AddGameObject(GameObject& game_object);
    //returns false if position isn't valid
    bool ChangeObjectPosition(GameObject& game_object, int x, int y);
    void Draw();
    std::vector<GameObject*>& GetObjectsAtPos(int x, int y);
    std::vector<GameObject*> GetAllObjects();

    int GetWidth();
    int GetHeight();

    //WinCondition win_condidion_;

private:
    std::vector<GameObject*>** objects_by_pos_;
    std::vector<GameObject*> empty_object_vector_; //as a default for oob positions
    static GameManager* current_game_;

    int width_;
    int height_;

    };

} //namespace game


#endif //BOMBERMAN_GAMEMANAGER_H
