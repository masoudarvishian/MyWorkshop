// MyLittleWorkshopEmpire.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Storage.h"
#include "views/ConsoleView.h"

int main()
{
	// init storage
	Storage::GetInstance()->init();

	// handle UI
	auto consoleView = std::make_unique<ConsoleView>();
	consoleView->run();

	return EXIT_SUCCESS;
}
