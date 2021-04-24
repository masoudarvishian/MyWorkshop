#include "BuyToolCommand.h"

BuyToolCommand::BuyToolCommand(int toolId) : m_toolId{ toolId }
{}

void BuyToolCommand::execute(std::function<void()> callback)
{
	auto playerViewModel = std::make_unique<PlayerViewModel>();
	
	playerViewModel->buyTool(m_toolId);

	std::cout << playerViewModel->buyMessage;
	
	callback();
}
