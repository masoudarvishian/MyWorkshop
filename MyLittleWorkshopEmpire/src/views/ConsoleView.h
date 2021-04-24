#ifndef CONSOLE_VIEW_H
#define CONSOLE_VIEW_H

#include <iostream>
#include <string>
#include "cmd/CommandManager.h"
#include "cmd/TestCommand.h"
#include "cmd/HelpCommand.h"
#include "cmd/InventoryCommand.h"
#include "cmd/ShopCommand.h"
#include "cmd/BuyToolCommand.h"

class ConsoleView
{
public:
	ConsoleView();
	~ConsoleView();
	void display();
private:
	std::unique_ptr<CommandManager> m_cmdManager;
};
#endif
