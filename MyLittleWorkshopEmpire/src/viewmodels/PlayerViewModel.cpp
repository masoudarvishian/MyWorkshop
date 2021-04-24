#include "PlayerViewModel.h"

void PlayerViewModel::printInventory()
{
	Storage::GetInstance()->getPlayer()->PrintInventory();
}

void PlayerViewModel::buyTool(int toolIndex)
{
	auto toolToBuy = ToolManager::GetInstance()->GetToolByIndex(toolIndex);
	Storage::GetInstance()->getPlayer()->BuyTool(toolToBuy);
}
