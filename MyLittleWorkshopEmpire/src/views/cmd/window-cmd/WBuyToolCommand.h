#ifndef W_BUY_TOOL_COMMAND_H
#define W_BUY_TOOL_COMMAND_H

#include <functional>
#include "../Command.h"
#include "../../../viewmodels/PlayerViewModel.h"
#include "../../../viewmodels/InventoryViewModel.h"

namespace UbiWorkshop
{
	namespace Views
	{
		namespace WindowCommands
		{
			using namespace UbiWorkshop::ViewModels;

			class WBuyToolCommand : public Command
			{
			public:
				//constructor
				WBuyToolCommand(int toolId, std::function<void()> onSuccess);

				virtual void execute(std::function<void()> callback) override;
			private:
				int m_toolId;
				std::string* m_errorMsg;
				bool* m_displayErrPopup;
				std::function<void()> m_onSuccess;
			};
		}
	}
}

#endif // !W_BUY_TOOL_COMMAND_H
