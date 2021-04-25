#include "InventoryViewModel.h"

void InventoryViewModel::UpdateInventory() noexcept
{
	auto player = Storage::GetInstance()->getPlayer();

	m_money = player->getMoney();

	auto usableTools = player->getUsableTools();

	for (auto iter(usableTools.begin()); iter != usableTools.end(); iter++)
	{
		auto tool{ iter->first };
		auto usageCounter{ iter->second };

		m_tools[tool->GetName()] = usageCounter;
	}
}

const int InventoryViewModel::GetMoney() const noexcept
{
	return m_money;
}

const std::map<std::string, int> InventoryViewModel::GetTools() const noexcept
{
	return m_tools;
}
