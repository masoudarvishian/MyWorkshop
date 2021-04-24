#include "Player.h"

Player::Player() : m_money{ START_MONEY }
{
	static int id{ 0 };
	m_id = ++id;
}

Player::~Player()
{
	std::cout << "player #" << m_id << " is destroyed!\n";
}

bool Player::BuyTool(Tool* tool) noexcept
{
	auto success{ false };

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

		success = true;
	}

	return success;
}

void Player::DamageTool(Tool* tool) noexcept
{
   auto currentUsageCount =	m_usableTools[tool];
   currentUsageCount /= 2; // 50% damage
   if (currentUsageCount < 0)
   {
	   currentUsageCount = 0;
   }

   m_usableTools[tool] = currentUsageCount;
}

void Player::InitTool(Tool* tool) noexcept
{
	auto wearCount{ tool->GetMaxWearCount() };
	m_usableTools[tool] = wearCount;
}

const int Player::getMoney() const noexcept
{
	return m_money;
}

void Player::AddMoney(int amout) noexcept
{
	m_money += amout;
}

std::map<Tool*, int> Player::getUsableTools() const noexcept
{
	return m_usableTools;
}
