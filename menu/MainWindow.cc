//
// Autor: Marlene, Marie, Patrick
//

#include "MainWindow.h"

#include "../core/AppManager.h"
#include "InstructionWindow.h"


namespace menu{

MainWindow::MainWindow()
: MenuWindow(kInstructions)
{
    theme_ = kClassic;

    MenuItem start = MenuItem("Spiel starten", kInstructions, 400, 300);
    MenuWindow::AddMenuItem(start);

    MenuItem change_theme = MenuItem("Thema wechseln", kChangeTheme, 400, 400);
    MenuWindow::AddMenuItem(change_theme);

    MenuItem exit = MenuItem("Spiel beenden", kExit1, 400, 500);
    MenuWindow::AddMenuItem(exit);
}

void MainWindow::Draw(){
    MenuWindow::Draw();

    graphics::GraphicsManager& graphics = core::AppManager::GetAppManager().GetGraphics();

    std::string theme_text;
    switch (theme_) {
        case kClassic:
            theme_text = "Bomberman";
            break;
        case kHalloween:
            theme_text = "Ghostman";
            break;
        case kChicken:
            theme_text = "Birdman";
            break;
        case kCorona:
            theme_text = "Coronaman";
            break;
        default:
            break;
    }
    graphics.DrawTile(graphics::kPlayer1Tiles.right, graphics::Color(255,255,255,0), 370, 100);
    graphics.WriteText(theme_text, graphics::Color(255, 140, 0, 255), graphics::FontSize::kLarge, false, 450, 115);

    std::string credit_text[] = {"Credits:",
                                "Peter Dechering, Carla Eckelt, Marie Krumnow, Marlene Mendler,",
                                "Patrick Möbius, Dennis Neuhaus, Tobias Oehme, Nina Willms"};
    int counter = 0;
    for (std::string tmp: credit_text) {
        graphics.WriteText(tmp, graphics::Color(255, 140, 0, 255), graphics::FontSize::kMedium,
                                                                        false, 20, 800+counter*30);
        counter++;
    }
}

void MainWindow::OnMenuItemSelect(int selected_option){
    bool open_instructions = false;
    switch (selected_option) {
        case kInstructions:
            open_instructions = true;
            break;
        case kChangeTheme:
            theme_ = (theme_+1)%4;
            switch (theme_) {
                case kClassic:
                    core::AppManager::GetAppManager().LoadTheme("default");
                    break;
                case kHalloween:
                    core::AppManager::GetAppManager().LoadTheme("halloween");
                    break;
                case kChicken:
                    core::AppManager::GetAppManager().LoadTheme("farm");
                    break;
                case kCorona:
                    core::AppManager::GetAppManager().LoadTheme("corona");
                    break;
                default:
                    break;
            }
            core::AppManager::GetAppManager().GetSound().PlayMusic(sound::menu_music);
            break;
        case kExit1:
            core::AppManager::GetAppManager().Quit();
            break;
        default:
            //Error, a button should always be selected
            break;
    }
    if (open_instructions) {
          InstructionWindow *instruction = new InstructionWindow();
          core::AppManager::GetAppManager().SetActiveWindow(*instruction);
    }
}

}   //namespace menu
