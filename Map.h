#ifndef MAP_H
#define MAP_H

#include <string>
#include <vector>

class Map
{
public:
	Map();
	~Map();

	void generate();
	/*
	Pre-Condition:
	- Members must be set, else defaults assumed
	Post-Condition:
	- A .txt file is is written to path
	Side Effects:
	- Must call clearFile() to generate a new file from the same instance
	*/

	void clearFile();

	/*
     *  - Clears fileName and path specs in instance
     */

	void displayChoices(bool describe = true, int margin = 5);
	/*
	 * - Displays the map names and, optionally, map discriptions
	 * - Call with int to set margin between names and discription
	 */


	int getChoice() const;
	/* returns current map id */

	int getRange() const;
	/* sets current map id */

	bool setChoice(int);
	bool setWallThickness(int, int);

	int x, // x in x * y tilemap
	  	y; // y in x * y tilemap

	static int count;


	std::string fileName, //file name and type (ex: file.txt)
							path;	   //file output path

private:
	void initMaps();
	void setPath();
	void printBlank(bool inverse = false);
	void printWalled(bool inverse = false);
	void save(std::string&);
	void name(std::string&);
	void formatSet(int);

	std::vector<std::string> maps;
	std::vector<std::string> info;
	std::vector<int> set;

	int choice, range;
	int xthick, ythick;
	static int xpass, ypass;
};

#endif
