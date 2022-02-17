#ifndef DISPLAY_JOBS_VIEWMODEL_H
#define DISPLAY_JOBS_VIEWMODEL_H

#include <vector>
#include <string>
#include "../models/Storage.h"
#include "../models/JobManager.h"

namespace MyWorkshop
{
	namespace ViewModels
	{
		using namespace MyWorkshop::Models;

		struct JobViewModel
		{
			int id;
			int vehicleId;
			int malfunctionId;
			std::string vehicleType;
			std::string malfunctionName;
			int rewardAmount;
			std::map<int, std::string> toolsIdName;
		};

		class DisplayJobsViewModel
		{
		public:
			DisplayJobsViewModel() { printf("DisplayJobsViewModel is created!\n"); }
			~DisplayJobsViewModel() { printf("DisplayJobsViewModel is destroyed!\n"); }
			const std::vector<JobViewModel> GetJobs() const noexcept;
		};
	}
}

#endif // !DISPLAY_JOBS_VIEWMODEL_H

