// Author: Tobias

#ifndef BOMBERMAN_CORE_APPMANAGER_H_
#define BOMBERMAN_CORE_APPMANAGER_H_

#include <chrono>

#include "../graphics/Keys.h"
#include "../graphics/GraphicsManager.h"
#include "../sound/SoundManager.h"
#include "Window.h"

namespace core {

/// AppManager: The main class of the program, containing a static reference to
/// itself, the active window instance and the main loop of the game

class AppManager {

public:
    /// A Getter to return the active AppManager
    ///
    /// \return A reference to the current AppManager
    static AppManager& GetAppManager();

    /// A Getter to return the current GraphicsManager
    ///
    /// \return
    graphics::GraphicsManager& GetGraphics();

    /// A Getter to return the current SoundManager
    ///
    /// \return
    sound::SoundManager& GetSound();

    /// Creates the GraphicsManager and the SoundManager
    ///
    /// init_hardware can be set to false to disable graphical function for testing
    ///
    /// \param title Name of the window
    /// \param init_hardware If the graphic and sound hardware interfaces are started normally or disabled for unit testing
    explicit AppManager(std::string title, bool init_hardware);

    /// Deconstructor of AppManager
    ~AppManager();

    /// Sets the active window and deletes the current window.
    ///
    /// \param window The new Window
    void SetActiveWindow(Window& window);

    /// A Getter for the current active Window
    ///
    /// \return A reference to the current Window
    Window& GetActiveWindow();

    /// Updates and draws the current active Window
    ///
    /// \param deltaTime Time that passed since last call
    void RunFrame(double deltaTime);

    /// Run game forever
    [[noreturn]] void Run();

    ///ends the game after the current frame has completed
    void Quit();

    /// Loads all assets for a theme
    ///
    /// \param theme The theme to load
    /// \return bool if the loading succeeded or not
    bool LoadTheme(std::string theme);

    /// Changes the background color
    ///
    /// \param background_color New background_color
    void ChangeBackgroundColor(graphics::Color background_color);

private:

    Window* active_window_; ///< The current Window

    graphics::GraphicsManager graphics_; ///< The current GraphicsManager
    sound::SoundManager sound_; ///< The current SoundManager

    bool is_running_;   ///< A bool that determins whether the main loop should be terminated

    static AppManager* manager_; ///< The static reference to the current AppManager
};

} // namespace core

#endif // BOMBERMAN_CORE_APPMANAGER_H_
