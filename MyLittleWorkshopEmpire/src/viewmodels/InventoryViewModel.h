#ifndef INVENTORY_VIEWMODEL_H
#define INVENTORY_VIEWMODEL_H

#include <map>
#include <string>
#include "../Storage.h"

class InventoryViewModel
{
public:
	void UpdateInventory() noexcept;
	const int GetMoney() const noexcept;
	const std::map<std::string, int> GetTools() const noexcept;
private:
	int m_money;
	std::map<std::string, int> m_tools;
};

#endif // !INVENTORY_VIEWMODEL_H

