// Author: Tobias

#ifndef BOMBERMAN_CORE_APPMANAGER_H_
#define BOMBERMAN_CORE_APPMANAGER_H_

#include "Window.h"

#include <chrono>

#include "../graphics/Keys.h"
#include "../graphics/GraphicsManager.h"
#include "../sound/SoundManager.h"

namespace core {

/// AppManager: The main class of the program, containing a static reference to
/// itself and the main loop of the game

class AppManager {

public:
    static AppManager& GetAppManager();

    graphics::GraphicsManager& GetGraphics();
    sound::SoundManager& GetSound();

    /// Creates the GraphicsManager and the SoundManager
    ///
    /// init_graphics can be set to false to disable graphical function for testing
    ///
    /// \param title Name of the window
    /// \param init_hardware If the graphic and sound hardware interfaces are started in normal-mode or Unit-Testmode
    explicit AppManager(std::string title, bool init_hardware);

    /// Deconstructor of AppManager
    ~AppManager();

    /// sets the active window and deletes the current window.
    void SetActiveWindow(Window& window);
    Window& GetActiveWindow();
    void RunFrame(double deltaTime);
    /// Run game for ever
    [[noreturn]] void Run();

    ///ends the game after the current frame has completed
    void Quit();

    /// Loads all assets for a theme
    ///
    /// \param theme Graphic theme to load
    /// \return bool if the loading succeeded or not
    bool LoadTheme(std::string theme);
    void ChangeBackgroundColor(graphics::Color background_color);

private:

    Window* active_window_; ///< The current Window which is managed by the AppManager

    graphics::GraphicsManager graphics_;
    sound::SoundManager sound_;

    bool is_running_;


    static AppManager* manager_; ///< The static reference to the current AppManager
};

} // namespace core

#endif // BOMBERMAN_CORE_APPMANAGER_H_
