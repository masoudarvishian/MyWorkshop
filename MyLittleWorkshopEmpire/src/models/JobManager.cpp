#include "JobManager.h"

std::shared_ptr<JobManager> JobManager::_instance{ nullptr };

JobManager::~JobManager()
{
	std::cout << "JobManager is destroyed!\n";
}

JobManager* JobManager::GetInstance() noexcept
{
	if (_instance == nullptr)
	{
		_instance = std::make_shared<JobManager>();
	}
	return _instance.get();
}

void JobManager::addJob(std::shared_ptr<Job> job) noexcept
{
	m_jobs.push_back(job);
}

void JobManager::removeJob(std::shared_ptr<Job> job) noexcept
{
	auto search = std::find_if(m_jobs.begin(), m_jobs.end(), [&job](std::shared_ptr<Job> j) {
		return job.get()->getId() == job.get()->getId();
	});

	if (search != m_jobs.end())
	{
		int index = std::distance(m_jobs.begin(), search);
		m_jobs.erase(m_jobs.begin() + index);
	}
}

std::vector<std::shared_ptr<Job>> JobManager::getJobs() const noexcept
{
	return m_jobs;
}
