//
// Autor: Marlene, Marie, Patrick
//
# include "MainWindow.h"
#include "../core/AppManager.h"
#include "InstructionWindow.h"

namespace menu{
    MainWindow::MainWindow()
    : MenuWindow(Instructions)
    {
        theme_ = Classic;

        MenuItem start = MenuItem("Spiel starten",Instructions,50,100);
        MenuWindow::AddMenuItem(start);

        MenuItem changeTheme = MenuItem("Thema wechseln",ChangeTheme,50,150);
        MenuWindow::AddMenuItem(changeTheme);

        MenuItem exit = MenuItem("Spiel beenden",Exit1,50,200);
        MenuWindow::AddMenuItem(exit);


    }

    void MainWindow::Draw(){
        MenuWindow::Draw();

        graphics::GraphicsManager& graphics = core::AppManager::GetAppManager().GetGraphics();

        std::string themeText;
        switch (theme_){
            case Classic:
                themeText = "Bomberman";
                //Male Tile vom Spieler der nach rechts läuft für das Tileset Bomberman
                //graphics.DrawTile(graphics::kPlayer1Tiles.right, graphics::Color(255,255,255,0), 10, 50);
                break;
            case Halloween:
                themeText = "Ghostman";
                //Male Tile vom Spieler der nach rechts läuft für das Tileset Ghostman
                break;
            case Chicken:
                themeText = "Birdman";
                //Male Tile vom Spieler der nach rechts läuft für das Tileset Birdman
                break;
            case Corona:
                themeText = "Coronaman";
                //Male Tile vom Spieler der nach rechts läuft für das Tileset Coronaman
                break;
            default:
                break;
        }
        graphics.WriteText(themeText, graphics::Color(255, 140, 0, 255), graphics::FontSize::kMedium, false, 10, 50);

        std::string creditText[] = {"Credits:",
                                    "Carla, Dennis, Marie, Marlene, Nina, Patrick, Peter, Tobias"};
        int counter = 0;
        for(std::string tmp: creditText){
            graphics.WriteText(tmp, graphics::Color(255, 140, 0, 255), graphics::FontSize::kMedium, false, 10, 250 + counter++ * 20);
        }
    }

    void MainWindow::OnMenuItemSelect(int selected_option){
        InstructionWindow *instruction = new InstructionWindow(theme_);
        switch (selected_option){
            case Instructions:
                core::AppManager::GetAppManager().SetActiveWindow(*instruction);
                break;
            case ChangeTheme:
                theme_ = (theme_+1) % 4;
                break;
            case Exit1:
                // wird sich gegebenenfalls noch verändern, durch quit-funktion im AppManager
                core::AppManager::GetAppManager().GetGraphics().Quit();
                break;
            default:
                break;
        }

    }




}   //namespace menu