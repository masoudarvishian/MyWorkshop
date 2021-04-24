#include "Tool.h"

Tool::Tool(const char* name, const int price) noexcept 
	: m_name{ name }, m_price{ price }
{
	static int id{ 0 };
	m_id = ++id;
}

const std::string Tool::GetName() const noexcept { return m_name; }

const int Tool::GetPrice() const noexcept { return m_price; }

const int Tool::GetMaxWearCount() const noexcept { return MAX_WEAR_COUNT; }
