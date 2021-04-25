#ifndef DISPLAY_JOBS_VIEWMODEL_H
#define DISPLAY_JOBS_VIEWMODEL_H

#include <vector>
#include <string>
#include "../Storage.h"
#include "../models/JobManager.h"

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
	const std::vector<JobViewModel> GetJobs() const noexcept;
};

#endif // !DISPLAY_JOBS_VIEWMODEL_H

