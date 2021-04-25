#include "AcceptJobViewModel.h"

namespace UbiWorkshop
{
	namespace ViewModels
	{
		bool AcceptJobViewModel::AcceptJob(int jobId) noexcept
		{
			if (JobManager::GetInstance()->AcceptJob(jobId))
			{
				m_finalMsg = "Completing job #" + std::to_string(jobId) + " is succeeded";
				return true;
			}
			else
			{
				m_finalMsg = "Competing job #" + std::to_string(jobId) + " is failed!";
				return false;
			}
		}

		const std::string AcceptJobViewModel::GetStatusMsg() const noexcept
		{
			return m_finalMsg;
		}
	}
}