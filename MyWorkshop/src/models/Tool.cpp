#include "Tool.h"

namespace MyWorkshop
{
	namespace Models
	{
		Tool::Tool(const char* name, const int price) noexcept
			: m_name{ name }, m_price{ price }
		{
			static int id{ 0 };
			m_id = ++id;
		}

		Tool::~Tool()
		{
			std::cout << "tool #" << m_id << " is destroyed" << std::endl;
		}

		const int Tool::GetId() const noexcept
		{
			return m_id;
		}

		const std::string Tool::GetName() const noexcept { return m_name; }

		const int Tool::GetPrice() const noexcept { return m_price; }

		const int Tool::GetMaxWearCount() const noexcept { return MAX_WEAR_COUNT; }
	}
}