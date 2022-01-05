// Autor Dennis, Peter

#ifndef BOMBERMAN_GAMEFACTORY_H
#define BOMBERMAN_GAMEFACTORY_H

#include "../graphics/Keys.h"
#include "win_condition/BaseWinCondition.h"

namespace game {

class GameFactory {
public:
    GameFactory(int width, int height);

    void GenerateGame(int player_count, int indest_prop);

private:
    void GenerateMap(int indest_count) const;
    void GeneratePlayers(int player_count, graphics::PlayerKeys* player_keys) const;

    int width_, height_;
};

//initializes a new classic mode game
void StartClassicGame();

} // namespace game

#endif //BOMBERMAN_GAMEFACTORY_H
