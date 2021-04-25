#ifndef JOB_H
#define JOB_H

#include <iostream>
#include "string"
#include "map"

namespace UbiWorkshop
{
	namespace Models
	{
		class Job
		{
		public:
			Job(int vehicleId, int malfunctionId, std::string vehicleType,
				std::string malfunctionName, int rewardAmount, std::map<int, std::string> toolsIdName);
			~Job();

			const int GetId() const noexcept;
			const int GetVehicleId() const noexcept;
			const int GetMalfunctionId() const noexcept;
			const std::string GetVehicleType() const noexcept;
			const std::string GetMalfanctionName() const noexcept;
			const int GetRewardAmount() const noexcept;
			const std::map<int, std::string> GetToolsIdName() const noexcept;
		private:
			int m_id;
			int m_vehicleId;
			int m_malfunctionId;
			std::string m_vehicleType;
			std::string m_malfunctionName;
			int m_rewardAmount;
			std::map<int, std::string> m_toolsIdName;
		};
	}
}

#endif // !JOB_H

