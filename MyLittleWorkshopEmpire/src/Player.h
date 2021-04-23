#ifndef PLAYER_H
#define PLAYER_H

#include "Tool.h"
#include <string>
#include <map>

constexpr int START_MONEY = 200;

class Player
{
public:

	Player();
	~Player();

	void BuyTool(Tool* tool);

	void InitTool(Tool* tool);

	void PrintInventory();

private:
	int m_money;
	std::map<Tool*, int> m_usableTools;
};

#endif
