#pragma once
#ifndef MENUITEMS_H
#define MENUITEMS_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

/*
*	Represents a vector of Item Objects.
*/
class MenuItems
{
public:
	MenuItems();
	int getSize();
private:
	int _size;

};

#endif MENUITEMS_H
