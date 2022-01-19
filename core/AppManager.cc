//Author: Tobias

#include "AppManager.h"

#include <chrono>
#include <iostream>

#include "../graphics/GraphicsManager.h"
#include "../graphics/Keys.h"
#include "../sound/Music.h"
#include "../sound/SoundEffect.h"
#include "../sound/SoundManager.h"
#include "Window.h"

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
        sound_(sound::SoundManager(init_hardware)),
        is_running_(true) {
        //ensure the reference to the AppManager stays active, and there is only one.

        if(AppManager::manager_ != nullptr) {
            delete AppManager::manager_;
        }
        AppManager::manager_ = this;
        active_window_ = nullptr;
        LoadTheme("default");
}

AppManager::~AppManager() {
    AppManager::manager_ = nullptr;
}

void AppManager::SetActiveWindow(Window &window) {
    delete active_window_;
    active_window_ = &window;
}

Window& AppManager::GetActiveWindow() {
    return *active_window_;
}

void AppManager::Quit() {
    is_running_ = false;
}

bool AppManager::LoadTheme(std::string theme) {
    bool success = true;
    success &= graphics_.LoadTileset(theme);
    success &= graphics_.LoadFonts(theme);

    sound_.StopPlayback();
     success &= sound::LoadSoundEffects(theme);
     success &= sound::LoadMusic(theme);

    return success;
}

void AppManager::ChangeBackgroundColor(graphics::Color background_color){
      graphics_.SetBackgroundColor(background_color);
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

        while (is_running_) {
            auto start_time = std::chrono::high_resolution_clock::now();
            RunFrame(delta_time);
            auto elapsed = std::chrono::high_resolution_clock::now() - start_time;

            if (graphics_.IsKeyPressed(graphics::key_fullscreen)) {
              fullscreen = !fullscreen;
              graphics_.SetFullscreen(fullscreen);
            }

            if (graphics_.IsKeyPressed(graphics::key_escape)) {
              Quit();
            }

           if (GetGraphics().IsKeyPressed(graphics::key_volume_louder)) {
               GetSound().SetMasterVolume(GetSound().GetMasterVolume() + 0.02);
           }

           if (GetGraphics().IsKeyPressed(graphics::key_volume_quieter)) {
               GetSound().SetMasterVolume(GetSound().GetMasterVolume() - 0.02);
           }

          int elapsed_microsecs = std::chrono::duration_cast<std::chrono::microseconds>(elapsed)
                     .count();

          if (elapsed_microsecs < min_delta_time) {
            graphics_.Sleep((min_delta_time - elapsed_microsecs)/1000);
            elapsed_microsecs = min_delta_time;
          }

          delta_time = elapsed_microsecs/1000000.0;
      }
      std::cout << "Quitting..." << std::endl;
      graphics_.Quit();
}


} // namespace core
