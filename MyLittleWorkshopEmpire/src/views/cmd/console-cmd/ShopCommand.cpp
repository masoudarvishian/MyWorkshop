#include "ShopCommand.h"

void ShopCommand::execute(std::function<void()> callback)
{
	auto m_shopViewModel = std::make_unique<ShopViewModel>();
	auto tools = m_shopViewModel->getTools();

	printf("  Shop content:\n");
	for (auto iter(tools.begin()); iter != tools.end(); iter++)
	{
		auto tool{ iter->get() };

		printf("  - #%d %s (%d$)\n", tool->GetId(), tool->GetName().c_str(), tool->GetPrice());
	}
	
	callback();
}
