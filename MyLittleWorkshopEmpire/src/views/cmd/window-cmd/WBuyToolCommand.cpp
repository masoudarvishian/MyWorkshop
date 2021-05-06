#include "WBuyToolCommand.h"

namespace UbiWorkshop
{
	namespace Views
	{
		namespace WindowCommands
		{
			WBuyToolCommand::WBuyToolCommand(int toolId, InventoryViewModel* inventoryViewModel,
				std::string* errorMsg, bool* displayErrPopup)
				: m_toolId{ toolId }, m_inventoryViewModel{ inventoryViewModel },
				m_errorMsg{ errorMsg }, m_displayErrPopup{ displayErrPopup }
			{}

			void WBuyToolCommand::execute(std::function<void()> callback)
			{
				auto playerViewModel = std::make_unique<PlayerViewModel>();

				if (playerViewModel->buyTool(m_toolId))
				{
					m_inventoryViewModel->UpdateInventory();
				}
				else
				{
					*m_errorMsg = playerViewModel->GetBuyStatusMsg();
					*m_displayErrPopup = true;
				}

				callback();
			}
		}
	}
}
