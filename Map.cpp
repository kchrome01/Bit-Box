#include <fstream>
#include <iomanip>
#include "Header.h"

int Map::count = 0;
int Map::xpass = 0;
int Map::ypass = 0;

enum doc{ Blank = 1, Inverse_Blank, Walled, Inverse_Walled };

template <typename T>
std::string NumToString(T num){
	std::stringstream ss;
	ss << num;

	return ss.str();
}

Map::Map()
{
	x = 16;
	y = 16;
	choice = 1;
	fileName = "";
	path = "";

	setWallThickness(1, 1);
	initMaps();
}

Map::~Map()
{
	x = 16;
	y = 16;
	choice = 1;
	fileName = "";
	path = "";
	initMaps();
}

void Map::generate()
{
	switch (choice)
	{
		case 1: printBlank();
			break;
		case 2: printBlank(true);
			break;
		case 3: printWalled();
			break;
		case 4: printWalled(true);
			break;
	}
}

void Map::initMaps()
{
	maps = { "Blank", "Inverted-Blank", "Walled", "Inverted-Walled" };
    info = { "->]X by Y tilemap, all zeros",
			 "->]X by Y tilemap, all ones",
		     "->]X by Y tilemap, walls == 1, floor == 0",
		     "->]X by Y tilemap, walls == 0, floor == 1" };

	
	range = maps.size();
}

void Map::displayChoices(bool describe, int margin)
{
	formatSet(margin);

	for (int i = 0; i < range; i++)
	{
		std::cout << i + 1 << ". " << maps[i] << " " << "Map";

		if (describe)
			std::cout << std::setw(set[i]) << info[i] << std::endl;
		else
			std::cout << std::endl;
	}
}

bool Map::setWallThickness(int xthick, int ythick)
{
	this->xthick = xthick;
	this->ythick = ythick;

	if (xthick > 0 && ythick > 0)
		return true;

	else
		return false;
}

void Map::printBlank(bool invert)
{

	int neg;
	std::string id, temp;
	if (!invert){
		neg = 0;
		xpass++;
		temp = "Blank";
		id = NumToString(xpass);
		temp += id;
	}
	else{
		neg = 1;
		ypass++;
		temp = "Inverse_Blank";
		id = NumToString(ypass);
		temp += id;
	}

	save(temp);
	std::ofstream fout(path);
	for (int r = 0; r < y; r++)
	{
		for (int c = 0; c < x; c++)
		{
			fout << neg;
			if (r != (y - 1) || c != (x - 1))
				fout << ", ";
		}
		fout << std::endl;
	}
}


void Map::printWalled(bool invert)
{
	int pos, neg;
	std::string id, temp;

	if (!invert) 
	{
		pos = 1;
		neg = 0;
		xpass++;
		temp = "Walled";	
		id = NumToString(xpass);
		temp += id;
	}
	else
	{
		pos = 0,
		neg = 1;
		ypass++;
		temp = "Inverse_Walled";
		id = NumToString(ypass);
		temp += id;
	}

	save(temp);
	std::ofstream fout(path);

	for (int r = 0; r < y; r++)
	{
		for (int c = 0; c < x; c++)
		{
			if (r < ythick)
			{
				fout << pos;
				fout << ", ";
			}
			else if (r < (y - ythick))
			{
				
				if (c < xthick)
				{
					fout << pos;
					fout << ", ";
				}
				else if (c < (x - xthick))
				{
					fout << neg;
					fout << ", ";
				}
				else
				{
					fout << pos;
					fout << ", ";
				}
			}
			else
			{
				fout << pos;
				if (r != (y - 1) || c != (x - 1))
				{
					fout << ", ";
				}
			}
			
		}
		fout << std::endl;
	}
}

void Map::formatSet(int margin)
{
	int max1;

	for (unsigned int i = 0; i < maps.size(); i++)
	{
		if (i + 1 < maps.size())
		{
			max1 = (maps[i].length() > maps[i + 1].length()) ? i : i + 1;
		}
	}

	for (unsigned int i = 0; i < maps.size(); i++)
	{
		int k = 0;

		k += (maps[max1].length() - maps[i].length() + margin + info[i].length());
		set.push_back(k);
	}

}

void Map::clearFile()
{
	path = "";
	fileName = "";
}

void Map::save(std::string &temp)
{
	
	if (path != "")
	{
		char test = '\\';
		if (path[path.length() - 1] != test)
			path += test;	
	}

	fileName = (fileName == "") ? temp : fileName;
	name(fileName);
	setPath();
}

void Map::name(std::string &str)
{
	str += ".txt";
}


void Map::setPath()
{
	this->path += fileName;
}

bool Map::setChoice(int choice)
{
	if (choice < 0 || choice > range)
	{
		return false;
	}
	else
	{
		this->choice = choice;
		return true;
	}
}

int Map::getChoice() const
{
	return choice;
}

int Map::getRange() const
{
	return range;
}