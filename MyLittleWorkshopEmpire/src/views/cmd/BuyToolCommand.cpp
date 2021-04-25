#include "BuyToolCommand.h"

BuyToolCommand::BuyToolCommand(int toolId) : m_toolId{ toolId }
{}

void BuyToolCommand::execute(std::function<void()> callback)
{
	auto m_playerViewModel = std::make_unique<PlayerViewModel>();
	
	m_playerViewModel->buyTool(m_toolId);

	std::cout << m_playerViewModel->buyMessage;
	
	callback();
}
