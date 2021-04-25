#include "AcceptJobCommand.h"

AcceptJobCommand::AcceptJobCommand(int jobId) : m_jobId{ jobId }
{
}

void AcceptJobCommand::execute(std::function<void()> callback)
{
	auto m_acceptJobViewModel = std::make_unique<AcceptJobViewModel>();
	m_acceptJobViewModel->AcceptJob(m_jobId);

	std::cout << m_acceptJobViewModel->GetStatusMsg();

	callback();
}
