#include <sstream>

template <typename T>
void Val(T &data)
{
	std::string line;
	while (getline(std::cin, line))
	{
		std::stringstream ss(line);
		if (ss >> data && ss.eof())
			break;
		else
			std::cout << "Invalid Data. Re-enter:";
	}
}

template <typename T, typename B>
void rangedVal(T &data, B min, B max)
{
	bool range = true;
	std::string line;
	while (getline(std::cin, line))
	{
		range = true;
		std::stringstream ss(line);
		if (ss >> data && ss.eof())
		{
			if (data >= min && data <= max) //specify range 
				break;
			else
				range = false;
		}
		else
			std::cout << "Invalid Data. Re-enter:  ";
		if (!range)
			std::cout << "Invalid Range. Re-enter: ";
	}
}
template <typename T, typename B>
void inclusiveVal(T &data, B val1, B val2)
{
	bool range = true;
	std::string line;
	while (getline(std::cin, line))
	{
		std::stringstream ss(line);
		if (ss >> data && ss.eof())
		{
			if (data == val1 || data == val2)
				break;
			else
				range = false;
		}
		else
			std::cout << "Invalid  Data. Re-enter: ";
		if (!range)
			std::cout << "Invalid Range. Re-enter: ";
	}
}

template <typename T, typename B>
void inclusive4Val(T &data, B val1, B val2, B val3, B val4)
{
	bool range = true;
	std::string line;
	while (getline(std::cin, line))
	{
		std::stringstream ss(line);
		if (ss >> data && ss.eof())
		{
			if (data == val1 || data == val2 || data == val3 || data == val4)
				break;
			else
				range = false;
		}
		else
			std::cout << "Invalid Data. Re-enter:";
		if (!range)
			std::cout << "Invalid Range. Re-enter:";
	}
}

template <typename T>
void exclusiveVal(T &data, T val1, T val2)
{
	bool range;
	std::string line;

	while (std::getline(std::cin, line))
	{
		std::stringstream ss(line);
		if (ss >> data && ss.eof())
		{
			if (x != val1 || x != val2)
				break;
			else
				range = false;
		}
		else
			std::cout << "Invalid Data. Re-enter: ";
		if (!range)
			std::cout << "Invalid Range. Re-enter: ";

	}
}