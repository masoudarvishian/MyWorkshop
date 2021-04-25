#include "InventoryCommand.h"

void InventoryCommand::execute(std::function<void()> callback)
{
	auto inventoryViewModel = std::make_unique<InventoryViewModel>();
	inventoryViewModel->UpdateInventory();

	printf("Money: $%d\n", inventoryViewModel->GetMoney());

	std::cout << '\n';

	// show tools
	for (auto t : inventoryViewModel->GetTools())
	{
		std::string toolStr = "Tool: " + t.first + ", Usage: x" + std::to_string(t.second);
		std::cout << toolStr << std::endl;
	}
	
	callback();
}
