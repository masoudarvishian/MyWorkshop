#include "DisplayJobsCommand.h"

void DisplayJobsCommand::execute(std::function<void()> callback)
{
	auto displayJobsViewModel = std::make_unique<DisplayJobsViewModel>();

	auto jobs = displayJobsViewModel->GetJobs();

	for (auto job : jobs)
	{
		std::string msg = "#" + std::to_string(job->GetId()) + ". Vehicle: " + job->GetVehicleType() +
			", Malfunction: " + job->GetMulfanctionName() + ", Reward: " + std::to_string(job->GetRewardAmount()) + "$, Tools:";

		for (auto tool : job->GetToolsIdName())
		{
			msg += (" #" + std::to_string(tool.first) + " " + tool.second + " /");
		}
		
		std::cout << msg << std::endl;
		std::cout << "----------------------------------------------------------" << std::endl;
	}

	callback();
}
