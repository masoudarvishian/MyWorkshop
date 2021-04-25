#include "models/Storage.h"
#include "views/ViewBase.h"
#include "views/ConsoleView.h"
#include "views/WindowView.h"

using namespace UbiWorkshop::Models;
using namespace UbiWorkshop::Views;

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