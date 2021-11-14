//Author: Marie
//TODO: Beschreibung der Klasse hinzufügen
//TODO: Konstruktor/ Destruktor hinzufügen?
//TODO: Boost-Test(-Datei) hinzufügen

#ifndef MENU_GAMEOVERWINDOW_H_
#define MENU_GAMEOVERWINDOW_H_

namespace menu {

class MenuItem {
public:
      string& GetText();
      int& GetX();
      int& GetY();

private:
      string text_;
      int x_;
      int y_;
};

} //namespace menu

#endif
