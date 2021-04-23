#ifndef BUY_TOOL_COMMAND_H
#define BUY_TOOL_COMMAND_H

#include "Command.h"
#include "../Player.h"
#include "../ToolManager.h"

class BuyToolCommand : public Command
{
public:
	BuyToolCommand(Player* player, int toolIndex);
	virtual void execute(std::function<void()> callback) override;

private:
	Player* m_player;
	int m_toolIndex;
};

#endif