#include "WBuyToolCommand.h"

namespace UbiWorkshop
{
	namespace Views
	{
		namespace WindowCommands
		{
			WBuyToolCommand::WBuyToolCommand(int toolId, std::function<void()> onSuccess)
				: m_toolId{ toolId }, m_onSuccess{onSuccess}
			{}

			void WBuyToolCommand::execute(std::function<void()> callback)
			{
				auto playerViewModel = std::make_unique<PlayerViewModel>();

				if (playerViewModel->buyTool(m_toolId))
				{
					m_onSuccess();
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
