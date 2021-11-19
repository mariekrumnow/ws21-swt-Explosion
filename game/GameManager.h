//
// Created by Dennis Neuhaus on 15.11.21.
//

#ifndef BOMBERMAN_GAMEMANAGER_H
#define BOMBERMAN_GAMEMANAGER_H

#include "GameObject.h"
#include "../core/AppManager.h"

namespace game {

class GameManager {
public:
    GameManager();
    ~GameManager();

    void Update(double delta_time);
    static GameManagerWindow& GetCurrentGame();
    void RemoveGameObject(GameObject game_object);
    void AddGameObject(GameObject game_object);
    void ChangeObjectPosition(GameObject game_object, int x, int y);
    void Draw();
    GameObject* GetObjectsAtPos(int x, int y);
    GameObject* GetAllObjects();

    //WinCondition win_condidion_;

private:
    std::vector<GameObject>** objects_by_pos_;
    static GameManagerWindow* current_game_;

    };

} //namespace game


#endif //BOMBERMAN_GAMEMANAGER_H
