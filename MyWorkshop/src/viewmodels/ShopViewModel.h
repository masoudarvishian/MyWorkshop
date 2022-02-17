#ifndef SHOP_VIEWMODEL_H
#define SHOP_VIEWMODEL_H

#include <map>
#include <memory>
#include "../models/Tool.h"
#include "../models/ToolManager.h"

namespace MyWorkshop
{
	namespace ViewModels
	{
		using namespace MyWorkshop::Models;

		class ShopViewModel
		{
		public:

			struct ToolViewModel {
				std::string name;
				int price;
				int id;
			};

			ShopViewModel() { printf("ShopViewModel is created!\n"); }
			~ShopViewModel() { printf("ShopViewModel is destroyed!\n"); }
			const std::vector<ToolViewModel> getTools() const noexcept;
		};
	}
}

#endif // !SHOP_VIEWMODEL_H

