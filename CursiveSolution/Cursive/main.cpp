/*
* Version 0.02
*
* Programmer: Arthur W. Aznive Jr.
* Date: 3/15/2022
* Comments:
* Updates:
* Patch Notes: Added the Menu and MenuItem Class.
*
*/

#include "Menu.h"

#include <conio.h>

//#include <vector>

//using namespace std;

//Function Declarations

void color(int color);
void gotoxy(int x, int y);
void ShowConsoleCursor(bool show);
void DisplayOptions(int Set[], std::vector <std::string> options);
void clear();
bool YesNoMenu(std::string message);


int main()
{
	std::cout << "Cursive\nBy: Arthur W. Aznive Jr.";
	int Set[] = { 7,7,7 }; //Default colors;
	int counter = 2;
	//char key;
	bool flag = true;

	std::vector <std::string> mainOptions{ "Option 1", "Option 2", "Quit" };

	ShowConsoleCursor(false);

	DisplayOptions(Set, mainOptions);

	return 0;
}

void color(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void gotoxy(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

/*
* Disables the cursor on the screen when I dont want to prompt the user to type.
*/
void ShowConsoleCursor(bool show)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO	cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = show; //Sets visability

	SetConsoleCursorInfo(out, &cursorInfo);
}

void clear()
{
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
}

/***
	A work in progress... The idea is you can store a bunch of options you want to have like windows, and then pass the menu options you want
	to display and have a dynamic menu selection. I can do differently.
/***/
void DisplayOptions(int Set[], std::vector <std::string> options)
{
	int _size = options.size();

	int _counter = _size;
	char key;
	bool flag = true;

	do
	{
		//display the options
		for (int i = 0; i < _size; i++)
		{
			gotoxy(10, (5 + i));
			color(Set[i]);
			std::cout << options[i];

		}

		//get the key input.
		key = _getch();

		//decrement counter (going up the list)
		if (key == 72 && _counter != 1)//up arrow
		{
			_counter--;
		}

		//increment counter (going down list)
		if (key == 80 && _counter != _size)//down arrow
		{
			_counter++;
		}

		if (key == '\r') //enter key
		{
			//Do something based of the counter number. This is why classes exist isnt it. I can make a class called Options. and each one will be fully 
			//customizable and defined. Or I could make this GUI in a Win App. But where's the fun in that!? For now, Quit on 3.

			if (_counter == 3)
			{
				if (YesNoMenu("Quit?"))
				{
					return;
				}
				
			}

		}

		//set all options to white
		for (int i = 0; i < _size; i++)
		{
			Set[i] = 7; //default white color.
		}

		//Hightlight the selected option.
		Set[_counter - 1] = 12;


	} while (flag);
}

/*
Confirmation Window
*/
bool YesNoMenu( std::string message )
{
	clear();
	std::cout << message + "\n";
	int counter = 1;
	char key;
	bool flag = true;
	int Set[] = { 7,7 }; //Default colors;

	do
	{
		//display the options

		gotoxy(10, 5);
		color(Set[0]);
		std::cout << "Yes";

		gotoxy(10, 6);
		color(Set[1]);
		std::cout << "No";

		//get the key input.
		key = _getch();

		//decrement counter (going up the list)
		if (key == 72 && counter != 1)//up arrow
		{
			counter--;
		}

		//increment counter (going down list)
		if (key == 80 && counter != 2)//down arrow
		{
			counter++;
		}

		if (key == '\r') //enter key
		{
			if (counter == 1)
			{
				//Confirmed.
				return true;
			}

			if (counter == 2)
			{
				//Denied.
				return false;
			}

		}

		//set all options to white
		for (int i = 0; i < 2; i++)
		{
			Set[i] = 7; //default white color.
		}

		//Hightlight the selected option.
		Set[counter - 1] = 12;


	} while (flag);
}