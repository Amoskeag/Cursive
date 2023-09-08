#include "menu.h"
#include "MenuItems.h"

menu::menu() {
	//Creates an empty menu object.
	this->_menuSize = 0;
	this->_activeItem = NULL;	//There is no item to be active, when an item is added for the first time, make this 0.
	this->_menuMessage = "";	//No Message.
	this->_menuTitle = "";		//No Title.
	this->active = false;		//Is not active yet.

}

menu::menu(std::string title) {
	//Creates a menu with only a title.
	this->_menuSize = 0;
	this->_activeItem = NULL;		//There is no item to be active, when an item is added for the first time, make this 0.
	this->_menuMessage = "";		//No Message.
	this->_menuTitle = "";			//No Title.
	this->active = false;		//Is not active yet.

}

menu::menu(std::string title, std::string message) {
	//Creates a menu with a title and a user message.
	this->_menuSize = 0;
	this->_activeItem = NULL;		//There is no item to be active, when an item is added for the first time, make this 0.
	this->_menuMessage = message;	//No Message.
	this->_menuTitle = title;		//No Title.
	this->active = false;		//Is not active yet.
	
}

int menu::getSize() {
	//returns the size of the item vector of the Menu.
	return 0;
}

void menu::addItem() {
	//Adds an Item object to the MenuItems vector.
}

void menu::getMessage() {
	//Returns the Message stored in the Menu Object.
}

void menu::setMessage() {
	//Sets a message for the Menu Object.
}

void menu::selectItem() {
	//When you select an Item, this will do something based on the item you choose.
}
