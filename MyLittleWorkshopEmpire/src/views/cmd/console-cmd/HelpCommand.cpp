#include "HelpCommand.h"

namespace UbiWorkshop
{
	namespace Views
	{
		namespace ConsoleCommands
		{
			void HelpCommand::execute(std::function<void()> callback)
			{
				auto helpViewModel = std::make_unique<HelpViewModel>();

				std::cout << helpViewModel->getHelp();

				callback();
			}
		}
	}
}
