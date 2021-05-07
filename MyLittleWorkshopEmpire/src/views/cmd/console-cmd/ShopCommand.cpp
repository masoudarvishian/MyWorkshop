#include "ShopCommand.h"

namespace UbiWorkshop
{
	namespace Views
	{
		namespace ConsoleCommands
		{
			void ShopCommand::execute(std::function<void()> callback)
			{
				auto m_shopViewModel = std::make_unique<ShopViewModel>();
				auto tools = m_shopViewModel->getTools();

				printf("  Shop content:\n");
				for (auto& tool : tools)
				{
					printf("  - #%d %s (%d$)\n", tool.id, tool.name.c_str(), tool.price);
				}

				callback();
			}
		}
	}
}