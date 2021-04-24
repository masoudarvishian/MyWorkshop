#include "AcceptJobViewModel.h"

const void AcceptJobViewModel::AcceptJob(int jobId) noexcept
{
	if (JobManager::GetInstance()->AcceptJob(jobId))
	{
		m_finalMsg = "Job #" + std::to_string(jobId) + " is succeeded";
	}
	else
	{
		m_finalMsg = "Job #" + std::to_string(jobId) + " is failed!";
	}
}

const std::string AcceptJobViewModel::GetStatusMsg() const noexcept
{
	return m_finalMsg;
}
