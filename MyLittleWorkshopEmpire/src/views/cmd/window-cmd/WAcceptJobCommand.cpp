#include "WAcceptJobCommand.h"

WAcceptJobCommand::WAcceptJobCommand(int jobId, AcceptJobViewModel* acceptJobViewModel, InventoryViewModel* inventoryViewModel,
	DisplayJobsViewModel* displayJobsViewModel, std::vector<JobViewModel>& jobs, std::string* errorMsg, bool* displayErrPopup)
	
	: m_jobId{ jobId }, m_acceptJobViewModel{ acceptJobViewModel }, m_inventoryViewModel{ inventoryViewModel }, 
	m_displayJobsViewModel{ displayJobsViewModel }, m_jobs{ jobs }, m_errorMsg{ errorMsg }, m_displayErrPopup{ displayErrPopup }
{
}

void WAcceptJobCommand::execute(std::function<void()> callback)
{
	if (m_acceptJobViewModel->AcceptJob(m_jobId))
	{
		m_inventoryViewModel->UpdateInventory();
		m_jobs = m_displayJobsViewModel->GetJobs();
	}
	else
	{
		*m_errorMsg = m_acceptJobViewModel->GetStatusMsg();
		*m_displayErrPopup = true;
	}

	callback();
}
