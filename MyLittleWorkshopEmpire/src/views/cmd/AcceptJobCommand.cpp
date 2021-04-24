#include "AcceptJobCommand.h"

AcceptJobCommand::AcceptJobCommand(int jobId) : m_jobId{ jobId }
{
}

void AcceptJobCommand::execute(std::function<void()> callback)
{
	auto acceptJobViewModel = std::make_unique<AcceptJobViewModel>();
	acceptJobViewModel->AcceptJob(m_jobId);

	std::cout << acceptJobViewModel->GetStatusMsg();

	callback();
}
