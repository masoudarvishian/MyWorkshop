#ifndef TOOL_MANAGER_H
#define TOOL_MANAGER_H

#include "Tool.h"
#include <vector>
#include <string>

namespace UbiWorkshop
{
	namespace Models
	{
		class ToolManager
		{
		public:

			// it's singleton, and cannot have copy constructor and operator=
			ToolManager(ToolManager& other) = delete;
			void operator=(const ToolManager&) = delete;

			// default constructor
			ToolManager() {}

			// destructor
			~ToolManager();

			// singleton pattern
			static ToolManager* GetInstance() noexcept;

			void AddTool(std::unique_ptr<Tool> tool);

			Tool* FindToolByName(std::string name);

			Tool* GetToolById(int toolIndex);

			const std::vector<Tool*> getTools() const noexcept;

		private:
			std::vector<std::unique_ptr<Tool>> m_tools;

			// singleton
			static std::unique_ptr<ToolManager> _instance;
		};
	}
}

#endif 

