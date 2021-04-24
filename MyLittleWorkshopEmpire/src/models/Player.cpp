#include "Player.h"

Player::Player() : m_money{ START_MONEY }
{}

Player::~Player()
{
	std::cout << "player is destroyed!\n";
}

bool Player::BuyTool(Tool* tool)
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

void Player::InitTool(Tool* tool)
{
	auto wearCount{ tool->GetMaxWearCount() };
	m_usableTools[tool] = wearCount;
}

const int Player::getMoney() const noexcept
{
	return m_money;
}

const std::map<Tool*, int> Player::getUsableTools() const noexcept
{
	return m_usableTools;
}
