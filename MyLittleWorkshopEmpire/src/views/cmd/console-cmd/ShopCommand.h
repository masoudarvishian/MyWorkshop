#ifndef SHOP_COMMAND_H
#define SHOP_COMMAND_H

#include "../Command.h"
#include "../../../viewmodels/ShopViewModel.h"

namespace UbiWorkshop
{
	namespace Views
	{
		namespace ConsoleCommands
		{
			using namespace UbiWorkshop::ViewModels;

			class ShopCommand : public Command
			{
			public:
				virtual void execute(std::function<void()> callback) override;
			};
		}
	}
}
#endif

