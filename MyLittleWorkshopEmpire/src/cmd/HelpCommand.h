#ifndef HELP_COMMAND_H
#define HELP_COMMAND_H

#include <iostream>
#include "Command.h"

class HelpCommand : public Command
{
public:
	virtual void execute(std::function<void()> callback) override;
};

#endif