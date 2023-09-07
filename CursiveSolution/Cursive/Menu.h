#pragma once
#ifndef MENU_H
#define MENU_H

#include <Windows.h>
#include <iostream>
#include <vector>
#include <string>

/*
*	An action is a task to be performed by the computer accociated with an 
*	option. Examples include File System manipulate, open, close, and save files.
*	Exit the application. Open a submenu. etc.
*/
class MenuOption {
public:
	MenuOption(std::string option, int action);

	std::string getOption() const;

	int getAction() const;

private:
	std::string option;
	int action;

};

/*
*	Menu's can have a title, position on screen, and content. This class encapsulates the data required
*	to show a menu.
*/
class Menu {
public:
	Menu(std::string title);
	void addMenuOption(std::string option, int action);
	void display() const;
	int getUserChoice() const;
	void setMenuPosition(int x, int y);
	COORD getMenuPosition();
	void setTextColor(int color);

private:
	std::string title;
	std::vector<MenuOption> menuOptions;
	COORD pos;
};

#endif //MENU_H
