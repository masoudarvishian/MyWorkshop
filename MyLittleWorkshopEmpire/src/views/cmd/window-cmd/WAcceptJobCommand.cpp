#include "WAcceptJobCommand.h"

namespace UbiWorkshop
{
	namespace Views
	{
		namespace WindowCommands
		{
			WAcceptJobCommand::WAcceptJobCommand(int jobId, std::vector<JobViewModel>& jobs, std::string* errorMsg, 
				bool* displayErrPopup, std::function<void()> onSuccess)
				: m_jobId{ jobId }, m_jobs{ jobs }, m_errorMsg{ errorMsg }, m_displayErrPopup{ displayErrPopup }, m_onSuccess { onSuccess }
			{
				printf("WAcceptJobCommand is created!\n");
			}

			void WAcceptJobCommand::execute(std::function<void()> callback)
			{
				auto acceptJobViewModel = std::make_unique<AcceptJobViewModel>();

				if (acceptJobViewModel->AcceptJob(m_jobId))
				{
					m_onSuccess();
				}
				else
				{
					*m_errorMsg = acceptJobViewModel->GetStatusMsg();
					*m_displayErrPopup = true;
				}

				callback();
			}
		}
	}
}
