#pragma once
#ifndef MENU_H
#define MENU_H

#include "MenuItems.h"
#include <Windows.h>

class menu
{
public:
	menu();
	menu(std::string title);
	menu(std::string title, std::string message);
	int getSize();								//Get Size of Menu (the number of options).
	void addItem(std::string item);				//Add an Item to the Menu Object.
	std::string getMessage();					//Gets the stored message of the menu object.
	void setMessage(std::string message);		//A Menu can have a message displayed, such as "Confirm?" or general user feedback such as "File Saved".
	void selectItem();							//Select the active item in the Menu.
	bool active;								//Stores if the Menu is active, if it is active, it should be shown.
	void displayMenu();
	void closeMenu();
	void setCoord(int x, int y);
	void setColor(int color);

private:
	int _menuSize;								//Size of the menu
	int _activeItem;							//holds the index of the active item, starts at 0 when a Menu is selected (top of the menu).
	std::string _menuTitle;						//Menu Titles belong to each instance, I dont want this to be changed.	
	std::string _menuMessage;
	std::vector <std::string> menuItems{};

};

#endif MENU_H
