#include "HelpCommand.h"

void HelpCommand::execute(std::function<void()> callback)
{
	std::cout << "HELP - here are all possible commands you could use:\n";
	std::cout << "  'i'         Inventory: your amount of Money and your available Tools\n";
	std::cout << "  'j'         Jobs: a list of available Jobs\n";
	std::cout << "  'a[index]' Accept a Job: using the index of the Job list. Example: when typing 'a2' you will accept the Job at index 2\n";
	std::cout << "  's'         Shop: a list of all available Tools and the Price\n";
	std::cout << "  'b[index]'  Buy a Tool: using the index of the Shop list. Example: when typing 'b0' you will buy the first Tool available in the Shop\n";
	std::cout << "  'x'         Quit Game\n";

	callback();
}
