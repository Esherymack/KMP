#include "Utility.h"

#include <iostream>
#include <fstream>
#include <ios>
#include <random>
#include <array>
#include <iterator>
#include <algorithm>
#include <sstream>


std::string make_string(int length)
{
	std::string result = "";
	std::array<std::string, 2> possible = { "A", "B" };

	std::random_device r;
	std::mt19937 engine(r());
	std::uniform_int_distribution<int> dist(0, 1);

	do
	{
		result = "";
		std::stringstream builder;

		for (int i = 0; i < length; ++i)
		{
			builder << possible[dist(engine)];
		}

		result = builder.str();

	// If "AAAB" doesn't occur at least once, yeet the string
	} while (result.find("AAAB") == std::string::npos);

	// std::cout << "String: " << result << std::endl;

	return result;	
}

bool writeToCSV(std::string file_name, int length, int d1)
{
	std::ofstream file;

	file.open(file_name, std::ios_base::app);
	file << length << ", " << d1 << std::endl;
	file.close();

	if (file.std::ios::fail())
	{
		return false;
	}

	return true;
}