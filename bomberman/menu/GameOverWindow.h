//Author: Marie
//TODO: Rückgabewerte prüfen/ zu OOD hinzufügen
//TODO: Beschreibung der Klasse & Funktionen hinzufügen
//TODO: Destruktor hinzufügen?
//TODO: Boost-Test(-Datei) hinzufügen

#ifndef MENU_GAMEOVERWINDOW_H_
#define MENU_GAMEOVERWINDOW_H_

namespace menu {

class GameOverWindow : public MenuGameWindow {

public:
      GameOverWindow(Player* winner);

      void Draw();
      void OnMenuItemSelect(int selected_option);

      string& GetWinner();
      Color& GetWinnerColor();

private:
      string winner_name_;
      Color winner_color_;
};

} //namespace menu

#endif
