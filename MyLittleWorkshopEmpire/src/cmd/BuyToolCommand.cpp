#include "BuyToolCommand.h"

BuyToolCommand::BuyToolCommand(Player* player, int toolIndex) : m_player{ player }, m_toolIndex{ toolIndex }
{}

void BuyToolCommand::execute(std::function<void()> callback)
{
	auto toolToBuy = ToolManager::GetInstance()->GetToolByIndex(m_toolIndex);
	m_player->BuyTool(toolToBuy);
	
	callback();
}
