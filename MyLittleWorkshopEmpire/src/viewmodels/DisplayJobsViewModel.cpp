#include "DisplayJobsViewModel.h"

const std::vector<std::string> DisplayJobsViewModel::getJobs() const noexcept
{
	std::vector<std::string> jobDescriptionList;
	auto jobs = JobManager::GetInstance()->getJobs();

	for (auto job : jobs)
	{
		std::string msg = "j #" + std::to_string(job->GetId()) + ". Vehicle: " + job->GetVehicleType() +
			", Malfunction: " + job->GetMulfanctionName() + ", Reward: " + std::to_string(job->GetRewardAmount()) + "$, Tools:";

		for (auto tool : job->GetToolsIdName())
		{
			msg += (" #" + std::to_string(tool.first) + " " + tool.second + " /");
		}
		jobDescriptionList.push_back(msg);
	}

	return jobDescriptionList;
}
