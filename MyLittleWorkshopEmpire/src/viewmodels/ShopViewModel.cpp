#include "ShopViewModel.h"

const std::map<int, std::shared_ptr<Tool>> ShopViewModel::getTools() const noexcept
{
	return ToolManager::GetInstance()->getTools();
}
