//
// Autor: Marlene, Marie, Patrick
//

#include "MainWindow.h"
#include "InstructionWindow.h"
#include "../core/AppManager.h"


namespace menu{
    MainWindow::MainWindow()
    : MenuWindow(Instructions)
    {
        theme_ = Classic;

        MenuItem start = MenuItem("Spiel starten", Instructions, 50, 100);
        MenuWindow::AddMenuItem(start);

        MenuItem changeTheme = MenuItem("Thema wechseln", ChangeTheme, 50, 150);
        MenuWindow::AddMenuItem(changeTheme);

        MenuItem exit = MenuItem("Spiel beenden", Exit1, 50, 200);
        MenuWindow::AddMenuItem(exit);
    }

    void MainWindow::Draw(){
        MenuWindow::Draw();

        graphics::GraphicsManager& graphics = core::AppManager::GetAppManager().GetGraphics();

        std::string themeText;
        switch (theme_) {
            case Classic:
                themeText = "Bomberman";
                //Setze Player-Tiles auf Bomberman
                break;
            case Halloween:
                themeText = "Ghostman";
                //Setze Player-Tiles auf Ghostman
                break;
            case Chicken:
                themeText = "Birdman";
                //Setze Player-Tiles auf Birdman
                break;
            case Corona:
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
                                    "Carla, Dennis, Marie, Marlene, Nina, Patrick, Peter, Tobias"};
        int counter = 0;
        for (std::string tmp: creditText) {
            graphics.WriteText(tmp, graphics::Color(255, 140, 0, 255), graphics::FontSize::kMedium, false, 10, 250 + counter++ * 20);
        }
    }

    void MainWindow::OnMenuItemSelect(int selected_option){
        bool openInstructions = false;
        switch (selected_option) {
            case Instructions:
                openInstructions = true;
                break;
            case ChangeTheme:
                theme_ = (theme_+1)%4;
                break;
            case Exit1:
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
