#include "Job.h"

Job::Job(int vehicleIndex, int malfunctionIndex) : m_vehicleId{ vehicleIndex }, m_malfunctionId{ malfunctionIndex }
{
	static int id{ 0 };
	m_id = ++id;
}

Job::~Job()
{
	std::cout << "job #" << m_id << " is destroyed!\n";
}

const int Job::getId() const noexcept
{
	return m_id;
}

const int Job::getVehicleId() const noexcept
{
	return m_vehicleId;
}

const int Job::getMalfunctionId() const noexcept
{
	return m_malfunctionId;
}
