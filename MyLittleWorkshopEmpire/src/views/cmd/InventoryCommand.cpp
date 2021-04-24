#include "InventoryCommand.h"

void InventoryCommand::execute(std::function<void()> callback)
{
	auto playerViewModel = std::make_unique<PlayerViewModel>();
	playerViewModel->printInventory();
	
	callback();
}
