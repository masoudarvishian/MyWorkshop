#ifndef INVENTORY_COMMAND_H
#define INVENTORY_COMMAND_H

#include <functional>
#include "../Command.h"
#include "../../../viewmodels/InventoryViewModel.h"

namespace UbiWorkshop
{
	namespace Views
	{
		namespace ConsoleCommands
		{
			using namespace UbiWorkshop::ViewModels;

			class InventoryCommand : public Command
			{
			public:
				virtual void execute(std::function<void()> callback) override;
			};
		}
	}
}

#endif