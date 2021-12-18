//Author: Tobias

#include "AppManager.h"

#include <chrono>

#include "Window.h"
#include "../graphics/GraphicsManager.h"
#include "../graphics/Keys.h"
#include "../sound/SoundManager.h"

namespace core {


AppManager* AppManager::manager_;

AppManager& AppManager::GetAppManager() {
    return *AppManager::manager_;
}

graphics::GraphicsManager& AppManager::GetGraphics() {
  return graphics_;
}

sound::SoundManager& AppManager::GetSound() {
    return sound_;
}


AppManager::AppManager(std::string title, bool init_hardware) :
        graphics_(graphics::GraphicsManager(title, init_hardware)),
        sound_(sound::SoundManager(init_hardware)) {
    //ensure the reference to the AppManager stays active, and there is only one.


    if(AppManager::manager_ != nullptr) {
        delete AppManager::manager_;
    }

    AppManager::manager_ = this;
    active_window_ = nullptr;

}

AppManager::~AppManager() {
    AppManager::manager_ = nullptr;
}

void AppManager::SetActiveWindow(Window &window) {
    active_window_ = &window;
}

Window& AppManager::GetActiveWindow() {
    return *active_window_;
}

void AppManager::RunFrame(double delta_time) {
    if (active_window_ != nullptr) {
        graphics_.BeginFrame();

        active_window_->Update(delta_time);
        active_window_->Draw();

        graphics_.EndFrame();
    }
}

void AppManager::Run() {
    double delta_time = 0.05;
    bool fullscreen = false;

			const int min_delta_time = 1000000 / 60; //limit to ~60 fps

    while (true) {
        auto start_time = std::chrono::high_resolution_clock::now();
        RunFrame(delta_time);
        auto elapsed = std::chrono::high_resolution_clock::now() - start_time;

        if (graphics_.IsKeyPressed(graphics::key_fullscreen)) {
          fullscreen = !fullscreen;
          graphics_.SetFullscreen(fullscreen);
        }

        if (graphics_.IsKeyPressed(graphics::key_escape)) {
          graphics_.Quit();
        }

					int elapsed_microsecs = std::chrono::duration_cast<std::chrono::microseconds>(elapsed)
                             .count();

        if (elapsed_microsecs < min_delta_time) {
          graphics_.Sleep((min_delta_time - elapsed_microsecs)/1000);
          elapsed_microsecs = min_delta_time;
        }

        delta_time = elapsed_microsecs/1000000.0;
    }
}


} // namespace core
