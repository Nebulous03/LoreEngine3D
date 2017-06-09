#include <Windows.h>
#include <iostream>

int main()
{

	// DOES NOT WORK
	HMODULE dll = LoadLibrary("LoreEngine2D.dll");

	if (!dll)
	{
		std::cout << "Failed" << std::endl;
	}

	system("PAUSE");
}