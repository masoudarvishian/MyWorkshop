#ifndef DISPLAY_JOBS_COMMAND_H
#define DISPLAY_JOBS_COMMAND_H

#include <iostream>
#include "../Command.h"
#include "../../../viewmodels/DisplayJobsViewModel.h"

namespace UbiWorkshop
{
	namespace Views
	{
		namespace ConsoleCommands
		{
			using namespace UbiWorkshop::ViewModels;

			class DisplayJobsCommand : public Command
			{
			public:
				virtual void execute(std::function<void()> callback) override;
			};
		}
	}
}

#endif // !DISPLAY_JOBS_COMMAND_H

