#ifndef HELP_COMMAND_H
#define HELP_COMMAND_H

#include <iostream>
#include "../Command.h"
#include "../../../viewmodels/HelpViewModel.h"

namespace MyWorkshop
{
	namespace Views
	{
		namespace ConsoleCommands
		{
			using namespace MyWorkshop::ViewModels;

			class HelpCommand : public Command
			{
			public:
				virtual void execute(std::function<void()> callback) override;
			};
		}
	}
}

#endif