#include "ShopCommand.h"

void ShopCommand::execute(std::function<void()> callback)
{
	ToolManager::GetInstance()->PrintToolInShop();
	
	callback();
}
