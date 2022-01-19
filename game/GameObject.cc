//Autor: Nina, Tobias, Marie

#include "GameObject.h"

#include "GameManager.h"

namespace game {

GameObject::GameObject() {}

GameObject::~GameObject() {
    GameManager::GetCurrentGame().DestroyGameObject(*this);
}

bool GameObject::OnExplosion(GameObject& source) {
    return false;
}

bool GameObject::OnPlayerCollision(Player& player) {
    return false;
}

bool GameObject::OnCollision(GameObject& source) {
    return false;
}

int GameObject::GetX() {
    return x_;
}

int GameObject::GetY() {
    return y_;
}

bool GameObject::SetPosition(int x, int y) {

    if (x == this->x_ && y == this->y_)
        return true;

    GameManager& game = GameManager::GetCurrentGame();

    bool collision = false;
    for (GameObject* object: game.GetObjectsAtPos(x, y)) {
        collision |= object->OnCollision(*this);
    }

    if (!collision && game.ChangeObjectPosition(*this, x, y)) {
        x_ = x;
        y_ = y;
        return true;
    }
    return false;
}

void GameObject::Destroy() {
    GameManager::GetCurrentGame().DestroyGameObject(*this);
    destroyed_ = true;
}

} // namespace game
