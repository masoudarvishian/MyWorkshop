#include "Job.h"

Job::Job(int vehicleId, int malfunctionId, std::string vehicleType,
	std::string malfunctionName, int rewardAmount, std::vector<std::string> toolsName)
	: m_vehicleId{ vehicleId }, m_malfunctionId{ malfunctionId }, m_vehicleType{ vehicleType }, m_malfunctionName{ malfunctionName },
	m_rewardAmount{ rewardAmount }, m_toolsName{ toolsName }
{
	static int id{ 0 };
	m_id = ++id;
}

Job::~Job()
{
	std::cout << "job #" << m_id << " is destroyed!\n";
}

const int Job::GetId() const noexcept
{
	return m_id;
}

const int Job::GetVehicleId() const noexcept
{
	return m_vehicleId;
}

const int Job::GetMalfunctionId() const noexcept
{
	return m_malfunctionId;
}

const std::string Job::GetVehicleType() const noexcept
{
	return m_vehicleType;
}

const std::string Job::GetMulfanctionName() const noexcept
{
	return m_malfunctionName;
}

const int Job::GetRewardAmount() const noexcept
{
	return m_rewardAmount;
}

const std::vector<std::string> Job::GetToolsName() const noexcept
{
	return m_toolsName;
}

