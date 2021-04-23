#include "InventoryCommand.h"

InventoryCommand::InventoryCommand(Player* player) : m_player{ player }
{}

void InventoryCommand::execute(std::function<void()> callback)
{
	m_player->PrintInventory();
	
	callback();
}
