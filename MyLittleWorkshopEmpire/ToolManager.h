#ifndef TOOL_MANAGER_H
#define TOOL_MANAGER_H

#include "Tool.h"
#include <map>
#include <string>

class ToolManager
{
public:
    
    // it's singleton, and cannot have copy constructor and operator=
    ToolManager(ToolManager& other) = delete;
    void operator=(const ToolManager&) = delete;

    // default constructor
    ToolManager() {}

    // destructor
    ~ToolManager() {}

    // singleton pattern
    static ToolManager* GetInstance() noexcept;

    void AddTool(Tool* tool);

    Tool* FindToolByName(std::string name) const;

    Tool* GetToolByIndex(int toolIndex);

    void PrintToolInShop() const noexcept;

private:
    std::map<int, Tool*> m_tools;

    // singleton
    static ToolManager* _instance;
};


#endif 

