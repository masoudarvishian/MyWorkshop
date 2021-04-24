#include "HelpModel.h"

HelpModel::HelpModel() noexcept
{
	m_helpStr = "HELP - here are all possible commands you could use:\n"
				"  'i'         Inventory: your amount of Money and your available Tools\n"
				"  'j'         Jobs: a list of available Jobs\n"
				"  'a[id]'	   Accept a Job: using the index of the Job list. Example: when typing 'a2' you will accept the Job at index 2\n"
				"  's'         Shop: a list of all available Tools and the Price\n"
				"  'b[id]'	   Buy a Tool: using the index of the Shop list. Example: when typing 'b0' you will buy the first Tool available in the Shop\n";
				"  'x'         Quit Game\n";
}

std::string HelpModel::getHelp() const noexcept { return m_helpStr; }
