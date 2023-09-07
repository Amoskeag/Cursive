#include "Menu.h"

MenuOption::MenuOption(std::string option, int action) : option(option), action(action) {}

std::string MenuOption::getOption() const {
	return option;
}

int MenuOption::getAction() const {
	return action;
}

Menu::Menu(std::string title) : title(title) {}


void Menu::addMenuOption(std::string option, int action) {
	menuOptions.push_back(MenuOption(option, action));
}

void Menu::display() const {
	COORD tempPos = pos;
	tempPos.X = pos.X;
	tempPos.Y = pos.Y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), tempPos);
	std::cout << "==== " << title << " ====" << std::endl;

	for (size_t i = 0; i < menuOptions.size(); ++i) {
		//SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), getMenuPosition());
		
		tempPos.Y++;

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), tempPos);
		std::cout << menuOptions[i].getOption() << std::endl;
		
		
	}
}


int Menu::getUserChoice() const {
	return 0;
}

//Given a coordinate location in the console, set the Cursor Location for printing.
void Menu::setMenuPosition(int x, int y)
{
	//Define a coordinate.
	//this->pos;

	//define the coordinate values.
	pos.X = x;
	pos.Y = y;

	//Set the data.
	//SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

COORD Menu::getMenuPosition() {
	//SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	return pos;
}

//Set Color of Printed text
void Menu::setTextColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}