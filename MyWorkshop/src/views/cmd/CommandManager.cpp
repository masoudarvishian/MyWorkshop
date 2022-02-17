#include "CommandManager.h"

CommandManager::~CommandManager()
{
	std::cout << "CommandManager is destroyed!\n";
}

void CommandManager::add(std::unique_ptr<Command> cmd) noexcept
{
	m_queue.push(std::move(cmd));

	if (!m_isPending)
	{
		doNext();
	}
}

void CommandManager::doNext() noexcept
{
	if (m_queue.empty())
	{
		return;
	}

	auto cmd = std::move(m_queue.back());
	m_queue.pop();
	m_isPending = true;
	cmd->execute([this]() { 
		this->cleanUp();
	});
}

void CommandManager::cleanUp() noexcept
{
	m_isPending = false;
	doNext();
}
