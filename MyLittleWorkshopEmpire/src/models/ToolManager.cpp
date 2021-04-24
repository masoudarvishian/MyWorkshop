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
	m_tools.push_back(tool);
}

Tool* ToolManager::FindToolByName(std::string name) const
{
	Tool* found{ nullptr };

	auto search = std::find_if(m_tools.begin(), m_tools.end(), [&name](std::shared_ptr<Tool> t) {
		return name == t.get()->GetName();
	});

	if (search != m_tools.end())
	{
		int index = std::distance(m_tools.begin(), search);
		found = m_tools.at(index).get();
	}

	return found;
}

Tool* ToolManager::GetToolById(int toolId)
{
	Tool* found{ nullptr };

	auto search = std::find_if(m_tools.begin(), m_tools.end(), [&toolId](std::shared_ptr<Tool> t) {
		return toolId == t.get()->GetId();
	});

	if (search != m_tools.end())
	{
		int index = std::distance(m_tools.begin(), search);
	    found = m_tools.at(index).get();
	}

	return found;
}

const std::vector<std::shared_ptr<Tool>> ToolManager::getTools() const noexcept
{
	return m_tools;
}
