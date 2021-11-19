//
// Created by Dennis Neuhaus on 15.11.21.
//

#ifndef BOMBERMAN_GAMEOBJECT_H
#define BOMBERMAN_GAMEOBJECT_H

namespace game {
    class GameObject {
    private:

    public:
        GameObject();
        ~GameObject();

        void SetPosition(int x, int y);
        void OnPlayerCollision();
        void OnExplosion();

        Tile GetTile();
        Color GetColor();
    };
} //namespace game


#endif //BOMBERMAN_GAMEOBJECT_H
