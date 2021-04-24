#include "DisplayJobsViewModel.h"

const std::vector<std::string> DisplayJobsViewModel::getJobs() const noexcept
{
	std::vector<std::string> jobDescriptionList;
	auto jobs = JobManager::GetInstance()->getJobs();

	for (auto job : jobs)
	{
		std::string msg = "j #" + std::to_string(job->GetId()) + ". Vehicle: " + job->GetVehicleType() +
			", Malfunction: " + job->GetMulfanctionName() + ", Reward: " + std::to_string(job->GetRewardAmount()) + "$, Tools:";

		auto toolCounter{ 1 };
		for (auto tool : job->GetToolsName())
		{
			msg += (' ' + std::to_string(toolCounter) + "." + tool);
			++toolCounter;
		}
		jobDescriptionList.push_back(msg);
	}

	return jobDescriptionList;
}
