#include "InventoryCommand.h"

namespace MyWorkshop
{
	namespace Views
	{
		namespace ConsoleCommands
		{
			void InventoryCommand::execute(std::function<void()> callback)
			{
				auto m_inventoryViewModel = std::make_unique<InventoryViewModel>();
				m_inventoryViewModel->UpdateInventory();

				printf("Money: $%d\n", m_inventoryViewModel->GetMoney());

				std::cout << '\n';

				// show tools
				for (auto t : m_inventoryViewModel->GetTools())
				{
					std::string toolStr = "Tool: " + t.first + ", Usage: x" + std::to_string(t.second);
					std::cout << toolStr << std::endl;
				}

				callback();
			}
		}
	}
}
