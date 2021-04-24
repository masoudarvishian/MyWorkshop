#include "ConsoleView.h"
#include "cmd/DisplayJobsCommand.h"
#include "cmd/AcceptJobCommand.h"

ConsoleView::ConsoleView()
{
	m_cmdManager = std::make_unique<CommandManager>();
}

ConsoleView::~ConsoleView()
{
	std::cout << "ConsoleView is destroyed!\n";
}

void ConsoleView::run()
{
	auto gameIsRunning{ true };
	std::string command;

	std::cout << "Hello Player!\nYou are about to lead your own Workshop.\n";
	std::cout << "In order to be successful you should : \n - keep an eye on your money\n - always have a set of Tools in your inventory\n - finish Jobs to earn Money which you can spent in the Hardware shop\n";

	while (gameIsRunning)
	{

		std::cout << "\nWhat do you want to do now? ";
		std::getline(std::cin, command);

		// in case of entering empty input
		if (command.empty())
		{
			std::cout << "Wrong Input! press 'h' for more information.\n";
			continue;
		}

		// these states can be handled by a state machine pattern
		switch (command.at(0))
		{
		case 'h':   // help, listing all commands
		{
			// a command for help option
			m_cmdManager->add(std::make_shared<HelpCommand>());
		}
		break;
		case 'i':   // inventory
		{
			// a command for inventory option
			m_cmdManager->add(std::make_shared<InventoryCommand>());
		}
		break;
		case 'j':   // jobs
		{
			// command for displaying jobs
			m_cmdManager->add(std::make_unique<DisplayJobsCommand>());
		}
		break;
		case 'a':   // accept job
		{
			auto id = 0;
			if (command.length() > 1)
			{
				id = std::stoi(command.substr(1, command.length()));
			}

			// a command for accepting a job
			m_cmdManager->add(std::make_unique<AcceptJobCommand>(id));
		}
		break;
		case 's':   // shop
		{
			// a command for shop option
			m_cmdManager->add(std::make_shared<ShopCommand>());
		}
		break;
		case 'b':   // buy tool
		{
			auto id = 0;
			if (command.length() > 1)
			{
				id = std::stoi(command.substr(1, command.length()));
			}

			// a command for buy tool option
			m_cmdManager->add(std::make_shared<BuyToolCommand>(id));
		}
		break;
		case 'x':   // quit game
		{
			gameIsRunning = false;
			std::cout << "\n\n=== Memory Mangement Messages ===\n\n";
		}
		break;
		default:
			std::cout << "Wrong Input! press 'h' for more information.\n";
			break;
		}
	}
}
