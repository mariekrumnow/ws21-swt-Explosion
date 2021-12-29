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
// #include "sound/SoundEffect.h"
// #include "sound/Music.h"
// #include "sound/SoundManager.h"

#include "../menu/MainWindow.h"

int main(int argc, char** argv)
{
    srand(time(0)); //seed the rng with the current unix time

    /// Initialize the app manager
    core::AppManager app = core::AppManager("Bomberman Explosion", true);

    // In Init. vom Appmanager oder MainWindow packen?
    app.LoadTheme("default");

    // sound::SoundManager& sound = app.GetSound();
    //
    // sound.SetMasterVolume(0.7);
    // sound.SetMusicVolume(0.9);

    menu::MainWindow mainW = menu::MainWindow();
    app.SetActiveWindow(mainW);

    app.Run();

    return 0;
}
