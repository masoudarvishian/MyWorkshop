#ifndef TOOL_H
#define TOOL_H

#include <string>
#include <iostream>

constexpr int MAX_WEAR_COUNT = 5;
class ToolManager;

class Tool
{
public:

	Tool(const char* name, const int price) noexcept;

	~Tool()
	{
		std::cout << "tool: " << m_name << " has destroyed" << std::endl;
	}

	std::string GetName() const noexcept;
	int GetPrice() const noexcept;
	int GetMaxWearCount() const noexcept;

private:
	std::string m_name;
	int m_price{ 0 };
};

#endif 