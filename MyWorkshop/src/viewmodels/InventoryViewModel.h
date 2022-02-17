#ifndef INVENTORY_VIEWMODEL_H
#define INVENTORY_VIEWMODEL_H

#include <map>
#include <string>
#include "../models/Storage.h"

namespace MyWorkshop
{
	namespace ViewModels
	{
		using namespace MyWorkshop::Models;

		class InventoryViewModel
		{
		public:
			InventoryViewModel() { printf("InventoryViewModel is created\n"); }
			~InventoryViewModel() { printf("InventoryViewModel is destroyed\n"); }

			void UpdateInventory() noexcept;
			const int GetMoney() const noexcept;
			const std::map<std::string, int> GetTools() const noexcept;
		private:
			int m_money{ 0 };
			std::map<std::string, int> m_tools;
		};
	}
}

#endif // !INVENTORY_VIEWMODEL_H