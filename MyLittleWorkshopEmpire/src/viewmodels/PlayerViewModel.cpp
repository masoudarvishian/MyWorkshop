#include "PlayerViewModel.h"

const bool PlayerViewModel::buyTool(int toolId) noexcept
{
	auto toolToBuy = ToolManager::GetInstance()->GetToolById(toolId);
	if (!toolToBuy)
	{
		m_buyMessage = "tool not found!";
		return false;
	}

	auto player = Storage::GetInstance()->getPlayer();

	if (player->BuyTool(toolToBuy))
	{
		std::stringstream buyMessageStream;

		auto usableTools = player->getUsableTools();
		buyMessageStream << "  You now have: " << toolToBuy->GetName() << " x" << usableTools[toolToBuy] << "\n"
			"  and Money $" << player->getMoney() << "$\n";

		m_buyMessage = buyMessageStream.str();
		return true;
	}
	
	m_buyMessage = "Failed to buy!";
	return false;
}

const std::string PlayerViewModel::GetBuyStatusMsg() const noexcept
{
	return m_buyMessage;
}
