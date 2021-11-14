//Author: Marie
//TODO: Rückgabewerte prüfen/ zu OOD hinzufügen
//TODO: Beschreibung der Klasse & Funktionen hinzufügen
//TODO: Konstruktor/ Destruktor hinzufügen? Oder ist die Klasse abstrakt, da wir ja immer nur bestimmte Menüs haben?

#ifndef MENU_MENUGAMEWINDOW_H_
#define MENU_MENUGAMEWINDOW_H_

#include <engine/GameWindow.h>
#include "MenuItem.h"

namespace menu {

class MenuGameWindow {

public:
      void Update(double delta_time);
      void Draw();
      void OnMenuItemSelect(int selected_option);

      int& GetSelectedOption();
      std::vector<MenuItem>& GetMenuItems();

private:
      int selected_option_;
      std::vector<MenuItem> menu_items_;

      void AddMenuItem(MenuItem menu_item);
};

} //namespace menu

#endif
