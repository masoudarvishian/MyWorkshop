#include "ToolManager.h"

std::shared_ptr<ToolManager> ToolManager::_instance{ nullptr };

ToolManager::~ToolManager()
{
	_instance = nullptr;
	std::cout << "ToolManager is destroyed!\n";
}

ToolManager* ToolManager::GetInstance() noexcept
{
	if (_instance == nullptr)
	{
		_instance = std::make_shared<ToolManager>();
	}
	return _instance.get();
}

void ToolManager::AddTool(std::shared_ptr<Tool> tool)
{
	auto nextIndex = m_tools.size();
	m_tools[nextIndex] = tool;
}

Tool* ToolManager::FindToolByName(std::string name) const
{
	Tool* found{ nullptr };

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
	if (toolIndex >= m_tools.size() || toolIndex < 0)
	{
		return nullptr;
	}

	return m_tools[toolIndex].get();
}

const std::map<int, std::shared_ptr<Tool>> ToolManager::getTools() const noexcept
{
	return m_tools;
}
