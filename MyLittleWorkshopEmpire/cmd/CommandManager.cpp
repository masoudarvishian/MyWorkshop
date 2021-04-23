#include "CommandManager.h"

void CommandManager::add(std::shared_ptr<Command> cmd) noexcept
{
	m_queue.push(cmd);

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

	auto cmd = m_queue.back();
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
