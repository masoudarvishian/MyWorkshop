#include "Player.h"

Player::Player() : m_money{ START_MONEY }
{}

Player::~Player()
{
	std::cout << "player is destroyed!\n";
}

void Player::BuyTool(Tool* tool)
{
	auto price{ tool->GetPrice() };
	auto wearCount{ tool->GetMaxWearCount() };

	if (m_money >= price)
	{
		m_money -= price;
		auto found{ m_usableTools.find(tool) };
		if (found != m_usableTools.end())
		{
			m_usableTools[tool] = wearCount;
		}
		else
		{
			m_usableTools[tool] += wearCount;
		}

		printf("  You now have: %s x%d\n", tool->GetName().c_str(), m_usableTools[tool]);
		printf("  and Money %d$\n", m_money);
	}
}

void Player::InitTool(Tool* tool)
{
	auto wearCount{ tool->GetMaxWearCount() };
	m_usableTools[tool] = wearCount;
}

void Player::PrintInventory()
{
	printf("  Money %d$\n", m_money);
	printf("  Tools:\n");
	for (auto iter(m_usableTools.begin()); iter != m_usableTools.end(); iter++)
	{
		// issue fixed: iter->first should be tool* and iter->second should be int
		auto tool{ iter->first };
		auto usageCounter{ iter->second };
		printf("  - %s x%d\n", tool->GetName().c_str(), usageCounter);
	}
}