#include "PlayerViewModel.h"

std::string PlayerViewModel::getPrintInventoryMsg()
{
	auto player = Storage::GetInstance()->getPlayer();

	std::stringstream inventoryMsgStream;

	inventoryMsgStream << "  Money " << player->getMoney() << "$\n" << "  Tools:\n";

	auto usableTools = player->getUsableTools();

	for (auto iter(usableTools.begin()); iter != usableTools.end(); iter++)
	{
		auto tool{ iter->first };
		auto usageCounter{ iter->second };

		inventoryMsgStream << "  - #" << tool->GetId() << " " << tool->GetName() << " x" << usageCounter << '\n';
	}

	return inventoryMsgStream.str();
}

void PlayerViewModel::buyTool(int toolId)
{
	auto toolToBuy = ToolManager::GetInstance()->GetToolById(toolId);
	if (!toolToBuy)
	{
		buyMessage = "tool not found!";
		return;
	}

	auto player = Storage::GetInstance()->getPlayer();

	if (player->BuyTool(toolToBuy))
	{
		std::stringstream buyMessageStream;

		auto usableTools = player->getUsableTools();
		buyMessageStream << "  You now have: " << toolToBuy->GetName() << " x" << usableTools[toolToBuy] << "\n"
			"  and Money $" << player->getMoney() << "$\n";

		buyMessage = buyMessageStream.str();
	}
	else
	{
		buyMessage = "Failed to buy!";
	}
}
