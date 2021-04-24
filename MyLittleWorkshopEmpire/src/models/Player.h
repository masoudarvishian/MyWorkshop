#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <map>
#include <iostream>
#include "Tool.h"

constexpr int START_MONEY = 200;

class Player
{
public:

	Player();
	~Player();

	bool BuyTool(Tool* tool);

	void InitTool(Tool* tool);

	const int getMoney() const noexcept;

	const std::map<Tool*, int> getUsableTools() const noexcept;

private:
	int m_money;
	std::map<Tool*, int> m_usableTools;
	int m_id;
};

#endif
