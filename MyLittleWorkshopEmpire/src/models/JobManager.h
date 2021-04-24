#ifndef JOB_MANAGER_H
#define JOB_MANAGER_H

#include <vector>
#include <memory>
#include <iostream>
#include <algorithm>
#include "Job.h"
#include "../Storage.h"

class JobManager
{
public:
	// it's singleton, and cannot have copy constructor and operator=
	JobManager(JobManager& other) = delete;
	void operator=(const JobManager&) = delete;

	// default constructor
	JobManager() {}

	// destructor
	~JobManager();

	// singleton pattern
	static JobManager* GetInstance() noexcept;

	void AddJob(std::shared_ptr<Job> job) noexcept;
	void RemoveJob(int jobId) noexcept;
	std::vector<std::shared_ptr<Job>> GetJobs() const noexcept;
	bool AcceptJob(int jobId) noexcept;

private:

	Job* FindJob(int jobId) const noexcept;

	std::vector<std::shared_ptr<Job>> m_jobs;

	// singleton
	static std::shared_ptr<JobManager> _instance;
};

#endif // !JOB_MANAGER_H

