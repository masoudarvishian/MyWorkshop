#ifndef BUY_TOOL_COMMAND_H
#define BUY_TOOL_COMMAND_H

#include "../Command.h"
#include "../../../viewmodels/PlayerViewModel.h"

namespace UbiWorkshop
{
	namespace Views
	{
		namespace ConsoleCommands
		{
			using namespace UbiWorkshop::ViewModels;

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