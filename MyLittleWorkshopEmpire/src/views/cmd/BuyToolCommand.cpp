#include "BuyToolCommand.h"

BuyToolCommand::BuyToolCommand(int toolIndex) : m_toolIndex{ toolIndex }
{}

void BuyToolCommand::execute(std::function<void()> callback)
{
	auto playerViewModel = std::make_unique<PlayerViewModel>();
	playerViewModel->buyTool(m_toolIndex);
	
	callback();
}
