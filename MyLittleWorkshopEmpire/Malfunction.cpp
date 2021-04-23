#include "Malfunction.h"

Malfunction::Malfunction(const char* name, const std::list<Tool*> tools, const int rewardAmount) noexcept
	: m_name{ name }, m_tools{ tools }, m_rewardAmount{ rewardAmount }
{}

std::string Malfunction::GetName() const noexcept { return m_name.c_str(); }

int Malfunction::GetFixCosts() const noexcept { return m_rewardAmount; }

std::list<Tool*> Malfunction::GetNeededTools() const noexcept { return m_tools; }