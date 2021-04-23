#include "ToolManager.h"

ToolManager* ToolManager::_instance{ nullptr };

ToolManager* ToolManager::GetInstance() noexcept
{
	if (_instance == nullptr)
	{
		_instance = new ToolManager;
	}
	return _instance;
}

void ToolManager::AddTool(Tool* tool)
{
	const int nextIndex = m_tools.size();
	m_tools[nextIndex] = tool;
}

Tool* ToolManager::FindToolByName(std::string name) const
{
	Tool* found{ 0 };

	for (auto iter(m_tools.begin()); iter != m_tools.end(); iter++)
	{
		Tool* tool{ iter->second };
		if (tool->GetName() == name)
		{
			found = tool;
			break;
		}
	}

	return found;
}

Tool* ToolManager::GetToolByIndex(int toolIndex)
{
	return m_tools[toolIndex];
}

void ToolManager::PrintToolInShop() const noexcept
{
	printf("  Shop content:\n");
	for (auto iter(m_tools.begin()); iter != m_tools.end(); iter++)
	{
		int index{ iter->first };
		Tool* tool{ iter->second };
		printf("  - %d: %s (%d$)\n", index, tool->GetName().c_str(), tool->GetPrice());
	}
}
