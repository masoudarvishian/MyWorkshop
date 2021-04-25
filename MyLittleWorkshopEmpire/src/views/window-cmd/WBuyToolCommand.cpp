#include "WBuyToolCommand.h"

WBuyToolCommand::WBuyToolCommand(int toolId, PlayerViewModel* playerViewModel, InventoryViewModel* inventoryViewModel,
	std::string *errorMsg, bool * displayErrPopup) 
	: m_toolId{ toolId }, m_playerViewModel{ playerViewModel }, m_inventoryViewModel{ inventoryViewModel }, 
	m_errorMsg{ errorMsg }, m_displayErrPopup{ displayErrPopup }
{}

void WBuyToolCommand::execute(std::function<void()> callback)
{
	if (m_playerViewModel->buyTool(m_toolId))
	{
		m_inventoryViewModel->UpdateInventory();
	}
	else
	{
		*m_errorMsg = m_playerViewModel->GetBuyStatusMsg();
		*m_displayErrPopup = true;
	}

	callback();
}
