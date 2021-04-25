#ifndef INVENTORY_COMMAND_H
#define INVENTORY_COMMAND_H

#include <functional>
#include "Command.h"
#include "../../viewmodels/InventoryViewModel.h"

class InventoryCommand : public Command
{
public:
	virtual void execute(std::function<void()> callback) override;
};
#endif