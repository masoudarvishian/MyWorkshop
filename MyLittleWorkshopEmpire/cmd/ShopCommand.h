#ifndef SHOP_COMMAND_H
#define SHOP_COMMAND_H

#include "Command.h"
#include "../ToolManager.h"

class ShopCommand : public Command
{
public:
	virtual void execute(std::function<void()> callback) override;
};
#endif

