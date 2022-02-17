#include "BuyToolCommand.h"

namespace MyWorkshop
{
	namespace Views
	{
		namespace ConsoleCommands
		{
			BuyToolCommand::BuyToolCommand(int toolId) : m_toolId{ toolId }
			{}

			void BuyToolCommand::execute(std::function<void()> callback)
			{
				auto m_playerViewModel = std::make_unique<PlayerViewModel>();

				m_playerViewModel->buyTool(m_toolId);

				std::cout << m_playerViewModel->GetBuyStatusMsg() << std::endl;

				callback();
			}
		}
	}
}