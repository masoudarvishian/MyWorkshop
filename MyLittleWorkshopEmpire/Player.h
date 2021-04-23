#pragma once

#include "Tool.h"
#include <string>

constexpr int START_MONEY = 200;


class Player
{
public:

    Player()
    {
        m_money = START_MONEY;
    }

    ~Player()
    {
    }

    void BuyTool(Tool* tool);

    void InitTool(Tool* tool);

    void PrintInventory();

private:
    int m_money;
    std::map<Tool*, int> m_usableTools;
};

