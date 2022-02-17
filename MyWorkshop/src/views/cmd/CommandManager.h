#ifndef COMMAND_MANAGER_H
#define COMMAND_MANAGER_H

#include <iostream>
#include <queue>
#include "Command.h"
#include <memory>

class CommandManager
{
public:
	CommandManager() {}
	~CommandManager();

	void add(std::unique_ptr<Command> cmd) noexcept;

private:
	void doNext() noexcept;
	void cleanUp() noexcept;

	bool m_isPending{ false };
	std::queue<std::unique_ptr<Command>> m_queue;
};

#endif