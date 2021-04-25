#include "DisplayJobsViewModel.h"

const std::vector<std::shared_ptr<Job>> DisplayJobsViewModel::GetJobs() const noexcept
{
	std::vector<std::string> jobDescriptionList;
	return JobManager::GetInstance()->GetJobs();
}
