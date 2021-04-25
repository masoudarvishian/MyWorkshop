#ifndef INVENTORY_VIEWMODEL_H
#define INVENTORY_VIEWMODEL_H

#include <map>
#include <string>
#include "../models/Storage.h"

namespace UbiWorkshop
{
	namespace ViewModels
	{
		using namespace UbiWorkshop::Models;

		class InventoryViewModel
		{
		public:
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