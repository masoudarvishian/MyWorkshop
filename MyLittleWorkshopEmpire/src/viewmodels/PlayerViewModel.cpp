#include "PlayerViewModel.h"

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
