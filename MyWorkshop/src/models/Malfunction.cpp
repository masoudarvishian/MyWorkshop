#include "Malfunction.h"

namespace MyWorkshop
{
	namespace Models
	{
		Malfunction::Malfunction(const char* name, const std::list<Tool*> tools, const int rewardAmount) noexcept
			: m_name{ name }, m_tools{ tools }, m_rewardAmount{ rewardAmount }
		{
			static int id{ 0 };
			m_id = ++id;
		}

		Malfunction::~Malfunction()
		{
			std::cout << "Malfunction #" << m_id << " is destroyed!\n";
		}

		const int Malfunction::GetId() const noexcept
		{
			return m_id;
		}

		const std::string Malfunction::GetName() const noexcept { return m_name; }

		const int Malfunction::GetRewardAmount() const noexcept { return m_rewardAmount; }

		std::list<Tool*> Malfunction::GetNeededTools() const noexcept { return m_tools; }
	}
}