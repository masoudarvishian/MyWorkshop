#include "WAcceptJobCommand.h"

namespace UbiWorkshop
{
	namespace Views
	{
		namespace WindowCommands
		{
			WAcceptJobCommand::WAcceptJobCommand(int jobId, InventoryViewModel* inventoryViewModel,
				std::vector<JobViewModel>& jobs, std::string* errorMsg, bool* displayErrPopup)

				: m_jobId{ jobId }, m_inventoryViewModel{ inventoryViewModel },
				m_jobs{ jobs }, m_errorMsg{ errorMsg }, m_displayErrPopup{ displayErrPopup }
			{
			}

			void WAcceptJobCommand::execute(std::function<void()> callback)
			{
				auto acceptJobViewModel = std::make_unique<AcceptJobViewModel>();

				if (acceptJobViewModel->AcceptJob(m_jobId))
				{
					auto displayJobsViewModel = std::make_unique<DisplayJobsViewModel>();

					m_inventoryViewModel->UpdateInventory();
					m_jobs = displayJobsViewModel->GetJobs();
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
