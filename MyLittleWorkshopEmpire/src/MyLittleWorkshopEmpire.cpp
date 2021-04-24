// MyLittleWorkshopEmpire.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "views/ConsoleView.h"
#include "Storage.h"

int main()
{
	// init storage
	Storage::GetInstance()->init();

	// handle UI
	auto consoleView = std::make_unique<ConsoleView>();
	consoleView->display();

	// release singleton memories
	delete ToolManager::GetInstance();
	delete Storage::GetInstance();

	return EXIT_SUCCESS;
}
