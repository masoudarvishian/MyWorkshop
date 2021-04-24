#include "ShopViewModel.h"

const std::vector<std::shared_ptr<Tool>> ShopViewModel::getTools() const noexcept
{
	return ToolManager::GetInstance()->getTools();
}
