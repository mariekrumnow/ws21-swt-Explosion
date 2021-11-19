//
// Created by Dennis Neuhaus on 15.11.21.
//

#ifndef BOMBERMAN_GAMEMANAGER_H
#define BOMBERMAN_GAMEMANAGER_H

#include "GameObject.h"

namespace game {

    class GameManager {

    private:

    public:
        GameManager();
        ~GameManager();

        GameObject GetObjectAtPos();
        void RemoveGameObjectAtPos();
        void AddGameObjectAtPos();
    };

};


#endif //BOMBERMAN_GAMEMANAGER_H
