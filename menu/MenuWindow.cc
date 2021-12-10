//
// Autor: Marlene, Marie, Patrick
//
#include <vector>

#include "MenuWindow.h"


namespace menu{
    MenuWindow::MenuWindow(){}
    MenuWindow::~MenuWindow(){}


    void MenuWindow::Update(double delta_time){}

    void MenuWindow::Draw(){}


    void MenuWindow::OnMenuItemSelect(int selected_option){}

    int MenuWindow::GetSelectedOption(){}

    std::vector<MenuItem>& MenuWindow::GetMenuItems(){}

    void MenuWindow::AddMenuItem(MenuItem menu_item){}

}   // namespace menu

