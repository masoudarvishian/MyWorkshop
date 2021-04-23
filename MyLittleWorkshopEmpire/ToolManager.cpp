#include "ToolManager.h"

ToolManager* ToolManager::_instance{ nullptr };

ToolManager::~ToolManager()
{
	_instance = nullptr;
	std::cout << "ToolManager is destroyed!\n";
}

ToolManager* ToolManager::GetInstance() noexcept
{
	if (_instance == nullptr)
	{
		_instance = new ToolManager;
	}
	return _instance;
}

void ToolManager::AddTool(std::shared_ptr<Tool> tool)
{
	const int nextIndex = m_tools.size();
	m_tools[nextIndex] = tool;
}

Tool* ToolManager::FindToolByName(std::string name) const
{
	Tool* found{ 0 };

	for (auto iter(m_tools.begin()); iter != m_tools.end(); iter++)
	{
		auto tool{ iter->second };
		if (tool->GetName() == name)
		{
			found = tool.get();
			break;
		}
	}

	return found;
}

Tool* ToolManager::GetToolByIndex(int toolIndex)
{
	return m_tools[toolIndex].get();
}

void ToolManager::PrintToolInShop() const noexcept
{
	printf("  Shop content:\n");
	for (auto iter(m_tools.begin()); iter != m_tools.end(); iter++)
	{
		int index{ iter->first };
		Tool* tool{ iter->second.get() };
		printf("  - %d: %s (%d$)\n", index, tool->GetName().c_str(), tool->GetPrice());
	}
}
