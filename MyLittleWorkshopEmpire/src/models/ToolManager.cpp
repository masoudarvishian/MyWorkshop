#include "ToolManager.h"

namespace UbiWorkshop
{
	namespace Models
	{
		std::unique_ptr<ToolManager> ToolManager::_instance{ nullptr };

		ToolManager::~ToolManager()
		{
			std::cout << "ToolManager is destroyed!\n";
		}

		ToolManager* ToolManager::GetInstance() noexcept
		{
			if (_instance == nullptr)
			{
				_instance = std::make_unique<ToolManager>();
			}
			return _instance.get();
		}

		void ToolManager::AddTool(std::unique_ptr<Tool> tool)
		{
			m_tools.push_back(std::move(tool));
		}

		Tool* ToolManager::FindToolByName(std::string name)
		{
			Tool* found{ nullptr };

			auto search = std::find_if(m_tools.begin(), m_tools.end(), [&name](std::unique_ptr<Tool>& t)
			{
				return t->GetName() == name;
			});

			if (search != m_tools.end())
			{
				auto index = std::distance(m_tools.begin(), search);
				found = m_tools.at(index).get();
			}

			return found;
		}

		Tool* ToolManager::GetToolById(int toolId)
		{
			Tool* found{ nullptr };

			auto search = std::find_if(m_tools.begin(), m_tools.end(), [&toolId](std::unique_ptr<Tool>& t) 
			{
				return toolId == t->GetId();
			});

			if (search != m_tools.end())
			{
				auto index = std::distance(m_tools.begin(), search);
				found = m_tools.at(index).get();
			}

			return found;
		}

		const std::vector<Tool*> ToolManager::getTools() const noexcept
		{
			std::vector<Tool*> tools;
			for (auto& t : m_tools) {
				tools.push_back(t.get());
			}
			return tools;
		}
	}
}
