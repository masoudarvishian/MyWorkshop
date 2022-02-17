#include "ShopViewModel.h"

namespace MyWorkshop
{
	namespace ViewModels
	{
		const std::vector<ShopViewModel::ToolViewModel> ShopViewModel::getTools() const noexcept
		{
			std::vector<ShopViewModel::ToolViewModel> output;

			// map data to viewmodel
			auto tools = ToolManager::GetInstance()->getTools();
			for (auto& t : tools) {
				
				if (!t) {
					continue;
				}

				ShopViewModel::ToolViewModel temp;
				temp.id = t->GetId();
				temp.name = t->GetName();
				temp.price = t->GetPrice();

				output.push_back(temp);
			}

			return output;
		}
	}
}