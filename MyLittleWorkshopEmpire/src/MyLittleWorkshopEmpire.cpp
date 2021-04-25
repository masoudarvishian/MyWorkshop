// MyLittleWorkshopEmpire.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Storage.h"
#include "views/ViewBase.h"
#include "views/ConsoleView.h"
#include "views/WindowView.h"

int main()
{
	/* init storage */
	Storage::GetInstance()->init();

	/* init View */
	// note: you can init ConsoleView as well, since both WindowView & ConsoleView are derived from ViewBase
	std::unique_ptr<ViewBase> view = std::make_unique<WindowView>();
	view->Run();

	return EXIT_SUCCESS;
}