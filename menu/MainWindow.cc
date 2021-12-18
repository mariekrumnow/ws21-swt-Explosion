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

        MenuItem changeTheme = MenuItem("Thema auswaehlen",ChangeTheme,50,150);
        MenuWindow::AddMenuItem(changeTheme);

        MenuItem exit = MenuItem("Spiel beenden",Exit1,50,200);
        MenuWindow::AddMenuItem(exit);


    }

    void MainWindow::Draw(){
        MenuWindow::Draw();

        graphics::GraphicsManager& graphics = core::AppManager::GetAppManager().GetGraphics();

        switch (theme_){
            case Classic:
                graphics.WriteText("Bomberman",
                                   graphics::Color(0, 0, 255, 255), graphics::FontSize::kSmall, false, 10, 50);
                break;
            case Halloween:
                graphics.WriteText("Ghostman",
                                   graphics::Color(0, 0, 255, 255), graphics::FontSize::kSmall, false, 10, 50);
                break;
            case Chicken:
                graphics.WriteText("Birdman",
                                   graphics::Color(0, 0, 255, 255), graphics::FontSize::kSmall, false, 10, 50);
                break;
            case Corona:
                graphics.WriteText("Coronaman",
                                   graphics::Color(0, 0, 255, 255), graphics::FontSize::kSmall, false, 10, 50);
                break;
            default:
                break;
        }
        //graphics.DrawTile(graphics::kPlayer1Tiles.right, graphics::Color(255,255,255,0), 10, 50);

        graphics.WriteText("Credits:",
                           graphics::Color(0, 0, 255, 255), graphics::FontSize::kSmall, false, 10, 250);
        graphics.WriteText("Carla, Dennis, Marie, Marlene, Nina, Patrick, Peter, Tobias",
                           graphics::Color(0, 0, 255, 255), graphics::FontSize::kSmall, false, 10, 270);



    }

    void MainWindow::OnMenuItemSelect(int selected_option){
        InstructionWindow instruction = InstructionWindow();
        switch (selected_option){
            case Instructions:
                // Start Game
                core::AppManager::GetAppManager().SetActiveWindow(instruction);
                break;
            case ChangeTheme:
                // change theme
                theme_ = (theme_+1) % 4;
                break;
            case Exit1:
                // exit game
                // wird sich gegebenenfalls noch verändern, durch quit-funktion im AppManager
                core::AppManager::GetAppManager().GetGraphics().Quit();
                break;
            default:
                break;
        }

    }




}   //namespace menu