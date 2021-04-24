#include "Malfunction.h"

Malfunction::Malfunction(const char* name, const std::list<Tool*> tools, const int rewardAmount) noexcept
	: m_name{ name }, m_tools{ tools }, m_rewardAmount{ rewardAmount }
{}

Malfunction::~Malfunction()
{
	std::cout << "Malfunction: " << m_name << " is destroyed!\n";
}

std::string Malfunction::GetName() const noexcept { return m_name.c_str(); }

int Malfunction::GetFixCosts() const noexcept { return m_rewardAmount; }

std::list<Tool*> Malfunction::GetNeededTools() const noexcept { return m_tools; }