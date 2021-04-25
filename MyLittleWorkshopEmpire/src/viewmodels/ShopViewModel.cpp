#include "ShopViewModel.h"

namespace UbiWorkshop
{
	namespace ViewModels
	{
		const std::vector<std::shared_ptr<Tool>> ShopViewModel::getTools() const noexcept
		{
			return ToolManager::GetInstance()->getTools();
		}
	}
}