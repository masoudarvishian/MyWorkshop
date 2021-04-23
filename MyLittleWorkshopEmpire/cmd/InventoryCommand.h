#ifndef INVENTORY_COMMAND_H
#define INVENTORY_COMMAND_H

#include <functional>
#include "Command.h"
#include "../Player.h"

class InventoryCommand : public Command
{
public:
	InventoryCommand(Player* player);
	virtual void execute(std::function<void()> callback) override;

private:
	Player* m_player;
};
#endif