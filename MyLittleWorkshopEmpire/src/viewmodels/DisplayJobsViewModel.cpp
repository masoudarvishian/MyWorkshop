#include "DisplayJobsViewModel.h"

const std::vector<std::string> DisplayJobsViewModel::GetJobs() const noexcept
{
	std::vector<std::string> jobDescriptionList;
	auto jobs = JobManager::GetInstance()->GetJobs();

	for (auto job : jobs)
	{
		std::string msg = "#" + std::to_string(job->GetId()) + ". Vehicle: " + job->GetVehicleType() +
			", Malfunction: " + job->GetMulfanctionName() + ", Reward: " + std::to_string(job->GetRewardAmount()) + "$, Tools:";

		for (auto tool : job->GetToolsIdName())
		{
			msg += (" #" + std::to_string(tool.first) + " " + tool.second + " /");
		}
		jobDescriptionList.push_back(msg);
	}

	return jobDescriptionList;
}
