#ifndef JOB_MANAGER_H
#define JOB_MANAGER_H

#include <vector>
#include <memory>
#include <iostream>
#include "Job.h"

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

	void addJob(std::shared_ptr<Job> job) noexcept;
	void removeJob(std::shared_ptr<Job> job) noexcept;
	std::vector<std::shared_ptr<Job>> getJobs() const noexcept;

private:
	std::vector<std::shared_ptr<Job>> m_jobs;

	// singleton
	static std::shared_ptr<JobManager> _instance;
};

#endif // !JOB_MANAGER_H

