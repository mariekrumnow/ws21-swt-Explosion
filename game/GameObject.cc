//Autor: Nina, Tobias, Marie

#include "GameObject.h"

#include "GameManager.h"
#include "../graphics/Tile.h"
#include "../graphics/Color.h"

namespace game {

GameObject::GameObject() {
    x_ = 0;
    y_ = 0;
    destroyed_ = false;
}

bool GameObject::IsDestroyed() {
    return destroyed_;
}

void GameObject::Destroy() {
    GameManager::GetCurrentGame().DestroyGameObject(*this);
    destroyed_ = true;
}

GameObject::~GameObject() {
    GameManager::GetCurrentGame().DestroyGameObject(*this);
}

bool GameObject::SetPosition(int x, int y) {

    if (x == this->x_ && y == this->y_) return true;

    GameManager &game = GameManager::GetCurrentGame();

    bool collision = false;
    for (GameObject *object: game.GetObjectsAtPos(x, y)) {
        collision |= object->OnCollision(*this);
    }

    if (!collision && game.ChangeObjectPosition(*this, x, y)) {
        x_ = x;
        y_ = y;
        return true;
    }
    return false;
}

bool GameObject::OnExplosion(GameObject &source) {
    return false;
}

bool GameObject::OnPlayerCollision(Player &player) {
    return false;
}

bool GameObject::OnCollision(GameObject &source) {
    return false;
}

int GameObject::GetX() {
    return x_;
}

int GameObject::GetY() {
    return y_;
}


} // namespace game
