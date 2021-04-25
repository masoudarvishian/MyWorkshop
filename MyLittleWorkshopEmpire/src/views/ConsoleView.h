#ifndef CONSOLE_VIEW_H
#define CONSOLE_VIEW_H

#include <iostream>
#include <string>
#include "ViewBase.h"
#include "cmd/CommandManager.h"
#include "cmd/console-cmd/TestCommand.h"
#include "cmd/console-cmd/HelpCommand.h"
#include "cmd/console-cmd/InventoryCommand.h"
#include "cmd/console-cmd/ShopCommand.h"
#include "cmd/console-cmd/BuyToolCommand.h"

class ConsoleView : public ViewBase
{
public:
	ConsoleView();
	~ConsoleView();
	virtual void Run() override;
private:
	std::unique_ptr<CommandManager> m_cmdManager;
};
#endif
