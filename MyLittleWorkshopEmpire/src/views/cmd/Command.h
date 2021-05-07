#ifndef COMMAND_H
#define COMMAND_H

#include <functional>

class Command
{
public:
	virtual ~Command() { printf("Command is destroyed!\n"); }
	virtual void execute(std::function<void()> callback) = 0;
};
#endif

