#include "DisplayJobsCommand.h"

void DisplayJobsCommand::execute(std::function<void()> callback)
{
	auto displayJobsViewModel = std::make_unique<DisplayJobsViewModel>();

	auto list = displayJobsViewModel->GetJobs();

	std::cout << "\n";
	for (auto iter {list.begin()}; iter != list.end(); ++iter)
	{
		std::cout << *iter << '\n';
		std::cout << "-------------------------------\n";
	}

	callback();
}
