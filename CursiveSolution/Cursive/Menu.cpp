#include "Menu.h"
#include "MenuItems.h"
#include <iostream>
#include <conio.h>

menu::menu() {
	//Creates an empty menu object.
	this->_menuSize = 0;
	this->_activeItem = 0;		//There is no item to be active, when an item is added for the first time, make this 0.
	this->_menuMessage = "";	//No Message.
	this->_menuTitle = "";		//No Title.
	this->active = false;		//Is not active yet.

}

menu::menu(std::string title) {
	//Creates a menu with only a title.
	this->_menuSize = 0;
	this->_activeItem = 0;			//There is no item to be active, when an item is added for the first time, make this 0.
	this->_menuMessage = "";		//No Message.
	this->_menuTitle = "";			//No Title.
	this->active = false;			//Is not active yet.

}

menu::menu(std::string title, std::string message) {
	//Creates a menu with a title and a user message.
	this->_menuSize = 0;
	this->_activeItem = 0;			//There is no item to be active, when an item is added for the first time, make this 0.
	this->_menuMessage = message;	//No Message.
	this->_menuTitle = title;		//No Title.
	this->active = false;			//Is not active yet.

}

int menu::getSize() {
	//returns the size of the item vector of the Menu.
	return menuItems.size();

}

void menu::addItem(std::string item) {
	//Adds an Item object to the MenuItems vector.
	menuItems.push_back(item);
}

std::string menu::getMessage() {
	//Returns the Message stored in the Menu Object.
	return _menuMessage;
}

void menu::setMessage(std::string message) {
	//Sets a message for the Menu Object.
	_menuMessage = message;
}

void menu::setColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void menu::setCoord(int x, int y) {
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void menu::displayMenu() {


	//Display the menu. set to active at the end? ill try it.
	if (this->_menuTitle != "")
	{
		//Display the Title
		setColor(7);
		std::cout << this->_menuTitle << std::endl;
	}

	if (getMessage() != "")
	{
		//Display the Message
		setColor(7);
		std::cout << getMessage() << std::endl << std::endl;
	}

	for (int i = 0; i < this->getSize(); i++)
	{
		setCoord(10, (7 + i));
		if (i == _activeItem)
		{
			setColor(12);
			std::cout << this->menuItems[i];
		}
		else
		{
			setColor(7);
			std::cout << this->menuItems[i];
		}


	}
	std::cout << std::endl;



}

void menu::closeMenu() {
	COORD topLeft = { 0, 0 };
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen;
	DWORD written;

	GetConsoleScreenBufferInfo(console, &screen);
	FillConsoleOutputCharacterA(
		console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	);
	FillConsoleOutputAttribute(
		console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
		screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	);
	SetConsoleCursorPosition(console, topLeft);

	//this->active = false;

}

void menu::selectItem() {
	//Cycle through items, this will do something based on the item you choose.

	int _size = this->getSize();

	_activeItem = 0;

	char key;
	bool flag = true;

	do
	{

		//get the key input.
		key = _getch();

		//decrement counter (going up the list)
		if (key == 72 && _activeItem != 0)//up arrow
		{
			_activeItem--;
		}

		//increment counter (going down list)
		if (key == 80 && _activeItem < _size - 1)//down arrow
		{
			_activeItem++;
		}

		if (key == '\r') //enter key
		{
			//the active item is what the user wants. now we process the selection


		}
		setCoord(0, 0);
		displayMenu();

	} while (flag);
}