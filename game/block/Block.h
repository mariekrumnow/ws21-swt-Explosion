//
// Autor: Nina, Marie
//

#ifndef BOMBERMAN_BLOCK_H
#define BOMBERMAN_BLOCK_H

#include "../game/GameObject.h"

namespace game {
class Block : public GameObject{
public:
    Block();
    ~Block();
    bool OnCollision();

};
}// namespace game

#endif //BOMBERMAN_BLOCK_H
