#ifndef JOB_H
#define JOB_H

#include <iostream>
#include "string"
#include "vector"

class Job
{
public:
	Job(int vehicleIndex, int malfunctionIndex, std::string vehicleType, 
		std::string malfunctionName, int rewardAmount, std::vector<std::string> toolsName);
	~Job();
    
	const int GetId() const noexcept;
	const int GetVehicleId() const noexcept;
	const int GetMalfunctionId() const noexcept;
	const std::string GetVehicleType() const noexcept;
	const std::string GetMulfanctionName() const noexcept;
	const int GetRewardAmount() const noexcept;
	const std::vector<std::string> GetToolsName() const noexcept;
private:
	int m_id;
	int m_vehicleId;
	int m_malfunctionId;
	std::string m_vehicleType;
	std::string m_malfunctionName;
	int m_rewardAmount;
	std::vector<std::string> m_toolsName;
};

#endif // !JOB_H

