#include "Header.h"
#include <string>

void tag(const Map);

int main()
{
		Map newMap;

		std::cout << "Map Generator v1.1\n";
		std::cout << "---------------------\n";
		std::cout << ">> move program to data folder to generate in folder\n";
		std::cout << "<or>\n";
		std::cout << ">> save to path manually\n\n";
		std::string loop;
		do
		{
			std::cout << "Enter x-axis tile count: ";
			Val(newMap.x);

			std::cout << "Enter y-axis tile count: ";
			Val(newMap.y);

			newMap.displayChoices();

			std::cout << "\nEnter choice:	";
			int ch = -1;
			while (!newMap.setChoice(ch))
			{
				rangedVal(ch, 1, newMap.getRange());
			}

			std::string str;
			std::cout << "Name file? (Y/N)";
			inclusive4Val(str, "y", "n", "Y", "N");
			if (str == "y" || str == "Y")
			{
				std::cout << " Name: (ex:\"courtyard\"):	";
				Val(newMap.fileName);
			}

			std::cout << "\n[0] Use default path.";
			std::cout << "\n[1] Specify custom path.";
			std::cout << "\n^Choose: ";

			int test, val1 = 0, val2 = 1;
			inclusiveVal(test, val1, val2);
			if (test)
			{
				std::cout << "\nName path (ex: \"C:\\Users\\<name>\\Desktop\\ \"):	";
				Val(newMap.path);
			}

			newMap.generate();
			tag(newMap);
			newMap.clearFile();

			std::cout << "Again (Y/N):";
			inclusive4Val(loop, "y", "n", "Y", "N");

		} while (loop == "y" || loop == "Y");

		std::cout << "Press any key to exit...";
		std::cin.get();

	return 0;
}

void tag(const Map ob)
{
	std::cout << "\nMap Type:	";
	std::cout << ob.getChoice();
	std::cout << "\nMap Name:	";
	std::cout << ob.fileName;
	std::cout << "\nPath:	";
	std::cout << ob.path;
	std::cout << "\nTile Dimensions:	";
	std::cout << ob.x << " x " << ob.y << std::endl;
}
