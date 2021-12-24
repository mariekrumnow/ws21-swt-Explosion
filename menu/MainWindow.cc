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

    MenuItem changeTheme = MenuItem("Thema wechseln", kChangeTheme, 50, 150);
    MenuWindow::AddMenuItem(changeTheme);

    MenuItem exit = MenuItem("Spiel beenden", kExit1, 50, 200);
    MenuWindow::AddMenuItem(exit);
}

void MainWindow::Draw(){
    MenuWindow::Draw();

    graphics::GraphicsManager& graphics = core::AppManager::GetAppManager().GetGraphics();

    std::string themeText;
    switch (theme_) {
        case kClassic:
            themeText = "Bomberman";
            //Setze Player-Tiles auf Bomberman
            break;
        case kHalloween:
            themeText = "Ghostman";
            //Setze Player-Tiles auf Ghostman
            break;
        case kChicken:
            themeText = "Birdman";
            //Setze Player-Tiles auf Birdman
            break;
        case kCorona:
            themeText = "Coronaman";
            //Setze Player-Tiles auf Coronaman
            break;
        default:
            break;
    }
    //graphics::kPlayer2Tiles.right
    graphics.DrawTile(graphics::kTilePlayer, graphics::Color(255,255,255,0), 20, 50);
    graphics.WriteText(themeText, graphics::Color(255, 140, 0, 255), graphics::FontSize::kMedium, false, 100, 50);

    std::string creditText[] = {"Credits:",
                                "Peter Dechering, Carla Eckelt, Marie Krumnow, Marlene Mendler,",
                                "Patrick Möbius, Dennis Neuhaus, Tobias Oehme, Nina Willms"};
    int counter = 0;
    for (std::string tmp: creditText) {
        graphics.WriteText(tmp, graphics::Color(255, 140, 0, 255), graphics::FontSize::kMedium,
                                                                        false, 10, 250+counter*20);
        counter++;
    }
}

void MainWindow::OnMenuItemSelect(int selected_option){
    bool openInstructions = false;
    switch (selected_option) {
        case kInstructions:
            openInstructions = true;
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
    if (openInstructions) {
          InstructionWindow *instruction = new InstructionWindow(theme_);
          core::AppManager::GetAppManager().SetActiveWindow(*instruction);
    }
}

}   //namespace menu
