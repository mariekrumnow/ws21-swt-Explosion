//Author: Tobias

#ifndef ENGINE_APPMANAGER_H_
#define ENGINE_APPMANAGER_H_

#include "Window.h"

#include <chrono>

#include "GraphicsManager.h"

namespace core {

//AppManager: The main class of the program, containing a static reference to
//itself and the main loop of the game
    class AppManager {

    public:
        static AppManager& GetAppManager();

        graphics::GraphicsManager& GetGraphics();

        //init_graphics can be set to false to disable graphical function for testing
        explicit AppManager(bool init_graphics);
        ~AppManager();

        //sets the active game window. DOESN'T delete the current window.
        void SetActiveGameWindow(Window& window);
        Window& GetActiveWindow();
        void RunFrame(double deltaTime);
        //Run game for ever
        [[noreturn]] void Run();

    private:
        Window* active_window_;

        graphics::GraphicsManager graphics_;

        //The static reference to the current AppManager
        static AppManager* manager_;
    };

} //namespace engine

#endif
