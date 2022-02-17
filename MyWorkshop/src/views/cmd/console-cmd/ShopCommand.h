#ifndef SHOP_COMMAND_H
#define SHOP_COMMAND_H

#include "../Command.h"
#include "../../../viewmodels/ShopViewModel.h"

namespace MyWorkshop
{
	namespace Views
	{
		namespace ConsoleCommands
		{
			using namespace MyWorkshop::ViewModels;

			class ShopCommand : public Command
			{
			public:
				virtual void execute(std::function<void()> callback) override;
			};
		}
	}
}
#endif

