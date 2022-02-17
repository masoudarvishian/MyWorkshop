#include "ConsoleView.h"
#include "cmd/console-cmd/DisplayJobsCommand.h"
#include "cmd/console-cmd/AcceptJobCommand.h"

namespace MyWorkshop
{
	namespace Views
	{
		ConsoleView::ConsoleView()
		{
			m_cmdManager = std::make_unique<CommandManager>();
		}

		ConsoleView::~ConsoleView()
		{
			std::cout << "ConsoleView is destroyed!\n";
		}

		void ConsoleView::Run()
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
					auto cmd = std::make_unique<HelpCommand>();
					m_cmdManager->add(std::move(cmd));
				}
				break;
				case 'i':   // inventory
				{
					// a command for inventory option
					auto cmd = std::make_unique<InventoryCommand>();
					m_cmdManager->add(std::move(cmd));
				}
				break;
				case 'j':   // jobs
				{
					// command for displaying jobs
					auto cmd = std::make_unique<DisplayJobsCommand>();
					m_cmdManager->add(std::move(cmd));
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
					auto cmd = std::make_unique<AcceptJobCommand>(id);
					m_cmdManager->add(std::move(cmd));
				}
				break;
				case 's':   // shop
				{
					// a command for shop option
					auto cmd = std::make_unique<ShopCommand>();
					m_cmdManager->add(std::move(cmd));
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
					auto cmd = std::make_unique<BuyToolCommand>(id);
					m_cmdManager->add(std::move(cmd));
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
	}
}
