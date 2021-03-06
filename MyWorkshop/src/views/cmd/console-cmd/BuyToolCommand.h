#ifndef BUY_TOOL_COMMAND_H
#define BUY_TOOL_COMMAND_H

#include "../Command.h"
#include "../../../viewmodels/PlayerViewModel.h"

namespace MyWorkshop
{
	namespace Views
	{
		namespace ConsoleCommands
		{
			using namespace MyWorkshop::ViewModels;

			class BuyToolCommand : public Command
			{
			public:
				BuyToolCommand(int toolId);
				virtual void execute(std::function<void()> callback) override;

			private:
				int m_toolId;
			};
		}
	}
}

#endif