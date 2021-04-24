#ifndef ACCEPT_JOB_COMMAND_H
#define ACCEPT_JOB_COMMAND_H

#include <memory>
#include "Command.h"
#include "../../viewmodels/AcceptJobViewModel.h"

class AcceptJobCommand : public Command
{
public:
	AcceptJobCommand(int jobId);
	virtual void execute(std::function<void()> callback) override;

private:
	int m_jobId;
};

#endif // !ACCEPT_JOB_COMMAND_H

