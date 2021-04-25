#ifndef W_BUY_TOOL_COMMAND_H
#define W_BUY_TOOL_COMMAND_H

#include "../Command.h"
#include "../../../viewmodels/PlayerViewModel.h"
#include "../../../viewmodels/InventoryViewModel.h"

class WBuyToolCommand : public Command
{
public:
	//constructor
	WBuyToolCommand(int toolId, PlayerViewModel* playerViewModel, InventoryViewModel* inventoryViewModel,
		std::string* errorMsg, bool* displayErrPopup);

	virtual void execute(std::function<void()> callback) override;
private:
	int m_toolId;
	PlayerViewModel* m_playerViewModel;
	InventoryViewModel* m_inventoryViewModel;
	std::string* m_errorMsg;
	bool* m_displayErrPopup;
};

#endif // !W_BUY_TOOL_COMMAND_H
