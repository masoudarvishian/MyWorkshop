#ifndef SHOP_VIEWMODEL_H
#define SHOP_VIEWMODEL_H

#include <map>
#include <memory>
#include "../models/Tool.h"
#include "../models/ToolManager.h"

namespace UbiWorkshop
{
	namespace ViewModels
	{
		using namespace UbiWorkshop::Models;

		class ShopViewModel
		{
		public:
			ShopViewModel() { printf("ShopViewModel is created!\n"); }
			~ShopViewModel() { printf("ShopViewModel is destroyed!\n"); }
			const std::vector<std::shared_ptr<Tool>> getTools() const noexcept;
		};
	}
}

#endif // !SHOP_VIEWMODEL_H

