#include "Tool.h"

Tool::Tool(const char* name, const int price) noexcept 
	: m_name{ name }, m_price{ price }
{
}

std::string Tool::GetName() const noexcept
{
	return m_name.c_str();
}

int Tool::GetPrice() const noexcept
{
	return m_price;
}

int Tool::GetMaxWearCount() const noexcept
{
	return MAX_WEAR_COUNT;
}
