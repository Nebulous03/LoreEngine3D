#pragma once
#include <iostream>
#include <fstream>
#include <string>

/*
std::string readFile(const char* file)	// slow C++ way
{
	std::ifstream	_file;
	std::string		_line;
	std::string		_result;

	_file.open(file);

	if (_file.is_open())
	{
		while (_file.good())
		{
			std::getline(_file, _line);
			_result.append(_line);
		}
	}
	else
	{
		std::cout << "An error occured reading file as string: Unable to open file!" << std::endl;
	}

	return _result;
}
*/

std::string readFile(const char* path);	// fast C way
