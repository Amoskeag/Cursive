#include "MenuItems.h"

MenuItems::MenuItems() {
	//Create an empty vector called MenuItems.
	std::vector <std::string> menuItems{};
	_size = 0;
}

int MenuItems::getSize() {
	//Return the number of items in the vector.
	return _size;
	
}


