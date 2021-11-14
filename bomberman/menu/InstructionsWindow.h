//Author: Marie
//TODO: Rückgabewerte prüfen/ zu OOD hinzufügen
//TODO: Beschreibung der Klasse & Funktionen hinzufügen
//TODO: Destruktor hinzufügen?
//TODO: Boost-Test(-Datei) hinzufügen

#ifndef MENU_INSTRUCTIONSWINDOW_H_
#define MENU_INSTRUCTIONSWINDOW_H_

namespace menu {

class InstructionsWindow : public MenuGameWindow {

public:
      InstructionsWindow();

      void Draw();
      void OnMenuItemSelect(int selected_option);
};

} //namespace menu

#endif
