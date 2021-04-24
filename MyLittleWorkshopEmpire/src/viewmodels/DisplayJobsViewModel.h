#ifndef DISPLAY_JOBS_VIEWMODEL_H
#define DISPLAY_JOBS_VIEWMODEL_H

#include <vector>
#include <string>
#include "../Storage.h"
#include "../models/JobManager.h"

class DisplayJobsViewModel
{
public:
	const std::vector<std::string> getJobs() const noexcept;
};

#endif // !DISPLAY_JOBS_VIEWMODEL_H

