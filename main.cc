//Autor: Tobias, Carla, Dennis

#include "game/GameWindow.h"
#include "core/AppManager.h"
#include "GameFactory.h"
#include "game/GameManager.h"
#include "game/Player.h"
#include "game/upgrade/ExplosionRadiusUpgrade.h"
#include "game/upgrade/BombCountUpgrade.h"
#include "../game/block/DestructibleBlock.h"
#include "../game/block/IndestructibleBlock.h"
#include "sound/SoundEffect.h"
#include "sound/Music.h"
#include "sound/SoundManager.h"

int main(int argc, char** argv)
{
    /// Initialize the app manager
    core::AppManager app = core::AppManager("Bomberman Explosion", true);

    game::GameFactory factory = game::GameFactory(15, 12);
    factory.GenerateGame(2, 85);

    game::GameWindow game_window = game::GameWindow();
    app.SetActiveWindow(game_window);

    sound::LoadSoundEffects("default");
    sound::LoadMusic("default");

    sound::SoundManager& sound = app.GetSound();

    sound.SetMasterVolume(0.7);
    sound.SetMusicVolume(0.9);

    sound.PlayRandomBattleMusic();

    srand(time(0));

    app.Run();

    return 0;
}
