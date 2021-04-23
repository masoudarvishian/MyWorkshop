#pragma once

#include <map>
#include <string>
#include <stdio.h>


constexpr int MAX_WEAR_COUNT = 5;
class ToolManager;

class Tool
{
public:

    Tool(const char* name, const int price)
    {
        m_name = name;
        m_price = price;
    }

    ~Tool()
    {
    }

    std::string GetName() { return m_name.c_str(); }
    int GetPrice() { return m_price;  }
    int GetMaxWearCount() { return MAX_WEAR_COUNT; }

private:
    std::string m_name;
    int m_price;
};

static ToolManager* g_ToolManager;

class ToolManager
{
public:
    ToolManager()
    {
        g_ToolManager = this;
    }

    ~ToolManager()
    {
        g_ToolManager = nullptr;
    }

    void AddTool(Tool* tool)
    {
        const int nextIndex = m_tools.size();
        m_tools[nextIndex] = tool;
    }

    Tool* FindToolByName(std::string name)
    {
        Tool* found = 0;

        for (auto iter(m_tools.begin()); iter != m_tools.end(); iter++)
        {
            Tool* tool = iter->second;
            if (tool->GetName() == name)
            {
                found = tool;
                break;
            }
        }

        return found;
    }

    Tool* GetToolByIndex(int toolIndex)
    {
        return m_tools[toolIndex];
    }

    void PrintToolInShop()
    {
        printf("  Shop content:\n");
        for (auto iter(m_tools.begin()); iter != m_tools.end(); iter++)
        {
            int index = iter->first;;
            Tool* tool = iter->second;
            printf("  - %d: %s (%d$)\n", index, tool->GetName().c_str(), tool->GetPrice());
        }
    }

private:
    std::map<int, Tool*> m_tools;
};
