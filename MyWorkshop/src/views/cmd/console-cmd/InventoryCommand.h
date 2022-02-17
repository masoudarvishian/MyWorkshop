#ifndef INVENTORY_COMMAND_H
#define INVENTORY_COMMAND_H

#include <functional>
#include "../Command.h"
#include "../../../viewmodels/InventoryViewModel.h"

namespace MyWorkshop
{
	namespace Views
	{
		namespace ConsoleCommands
		{
			using namespace MyWorkshop::ViewModels;

			class InventoryCommand : public Command
			{
			public:
				virtual void execute(std::function<void()> callback) override;
			};
		}
	}
}

#endif