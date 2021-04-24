#include "DisplayJobsCommand.h"

void DisplayJobsCommand::execute(std::function<void()> callback)
{
	auto displayJobsViewModel = std::make_unique<DisplayJobsViewModel>();

	auto list = displayJobsViewModel->GetJobs();

	std::cout << "\n";
	for (int i = 0; i < list.size(); ++i)
	{
		std::cout << list[i] << '\n';
		std::cout << "-------------------------------\n";
	}

	callback();
}
