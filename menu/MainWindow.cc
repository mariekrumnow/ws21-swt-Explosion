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

    MenuItem start = MenuItem("Spiel starten", kInstructions, 50, 100);
    MenuWindow::AddMenuItem(start);

    MenuItem change_theme = MenuItem("Thema wechseln", kChangeTheme, 50, 150);
    MenuWindow::AddMenuItem(change_theme);

    MenuItem exit = MenuItem("Spiel beenden", kExit1, 50, 200);
    MenuWindow::AddMenuItem(exit);
}

void MainWindow::Draw(){
    MenuWindow::Draw();

    graphics::GraphicsManager& graphics = core::AppManager::GetAppManager().GetGraphics();

    std::string theme_text;
    switch (theme_) {
        case kClassic:
            theme_text = "Bomberman";
            //Setze Player-Tiles auf Bomberman
            break;
        case kHalloween:
            theme_text = "Ghostman";
            //Setze Player-Tiles auf Ghostman
            break;
        case kChicken:
            theme_text = "Birdman";
            //Setze Player-Tiles auf Birdman
            break;
        case kCorona:
            theme_text = "Coronaman";
            //Setze Player-Tiles auf Coronaman
            break;
        default:
            break;
    }
    //graphics::kPlayer2Tiles.right
    graphics.DrawTile(graphics::kTilePlayer, graphics::Color(255,255,255,0), 20, 50);
    graphics.WriteText(theme_text, graphics::Color(255, 140, 0, 255), graphics::FontSize::kMedium, false, 100, 50);

    std::string credit_text[] = {"Credits:",
                                "Peter Dechering, Carla Eckelt, Marie Krumnow, Marlene Mendler,",
                                "Patrick Möbius, Dennis Neuhaus, Tobias Oehme, Nina Willms"};
    int counter = 0;
    for (std::string tmp: credit_text) {
        graphics.WriteText(tmp, graphics::Color(255, 140, 0, 255), graphics::FontSize::kMedium,
                                                                        false, 10, 250+counter*20);
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
            break;
        case kExit1:
            // wird sich gegebenenfalls noch verändern, durch quit-funktion im AppManager
            core::AppManager::GetAppManager().GetGraphics().Quit();
            break;
        default:
            break;
    }
    if (open_instructions) {
          InstructionWindow *instruction = new InstructionWindow(theme_);
          core::AppManager::GetAppManager().SetActiveWindow(*instruction);
    }
}

}   //namespace menu
