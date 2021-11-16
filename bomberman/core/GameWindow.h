//Author: Tobias
#ifndef CORE_GAMEWINDOW_H_
#define CORE_GAMEWINDOW_H_

namespace core {

//GameWindow: Abstract class to represent different program display modes,
//like the main game, or menus.
class GameWindow {
public:
	virtual void Update(double delta_time) = 0;
	virtual void Draw() = 0;
};

} //namespace core

#endif
