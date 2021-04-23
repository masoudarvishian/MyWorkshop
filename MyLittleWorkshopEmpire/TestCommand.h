#ifndef TEST_COMMAND_H
#define TEST_COMMAND_H

#include "Command.h"
#include <iostream>

class TestCommand : public Command
{
public:
	virtual ~TestCommand()
	{
		std::cout << "Test Command is destroyed!\n";
	}

	virtual void execute(std::function<void()> callback)
	{
		std::cout << "Test command excecuted!\n";

		callback();
	}
};

#endif