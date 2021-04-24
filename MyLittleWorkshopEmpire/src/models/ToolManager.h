#ifndef TOOL_MANAGER_H
#define TOOL_MANAGER_H

#include "Tool.h"
#include <vector>
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
	~ToolManager();

	// singleton pattern
	static ToolManager* GetInstance() noexcept;

	void AddTool(std::shared_ptr<Tool> tool);

	Tool* FindToolByName(std::string name) const;

	Tool* GetToolById(int toolIndex);

	const std::vector<std::shared_ptr<Tool>> getTools() const noexcept;

private:
	std::vector<std::shared_ptr<Tool>> m_tools;

	// singleton
	static std::shared_ptr<ToolManager> _instance;
};


#endif 

