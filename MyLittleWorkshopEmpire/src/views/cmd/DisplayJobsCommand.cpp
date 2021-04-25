#include "DisplayJobsCommand.h"

void DisplayJobsCommand::execute(std::function<void()> callback)
{
	auto m_displayJobsViewModel = std::make_unique<DisplayJobsViewModel>();

	auto jobs = m_displayJobsViewModel->GetJobs();

	for (auto job : jobs)
	{
		std::string msg = "#" + std::to_string(job.id) + ". Vehicle: " + job.vehicleType +
			", Malfunction: " + job.malfunctionName + ", Reward: " + std::to_string(job.rewardAmount) + "$, Tools:";

		for (auto tool : job.toolsIdName)
		{
			msg += (" #" + std::to_string(tool.first) + " " + tool.second + " /");
		}
		
		std::cout << msg << std::endl;
		std::cout << "----------------------------------------------------------" << std::endl;
	}

	callback();
}
