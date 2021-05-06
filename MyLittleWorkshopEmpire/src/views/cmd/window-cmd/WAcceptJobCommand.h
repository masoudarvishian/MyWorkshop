#ifndef W_ACCEPT_JOB_COMMAND_H
#define W_ACCEPT_JOB_COMMAND_H

#include "../Command.h"
#include "../../../viewmodels/AcceptJobViewModel.h"
#include "../../../viewmodels/InventoryViewModel.h"
#include "../../../viewmodels/DisplayJobsViewModel.h"

namespace UbiWorkshop
{
	namespace Views
	{
		namespace WindowCommands
		{
			using namespace UbiWorkshop::ViewModels;

			class WAcceptJobCommand : public Command
			{
			public:
				// constructor
				WAcceptJobCommand(int jobId, InventoryViewModel* inventoryViewModel,
					std::vector<JobViewModel>& jobs, std::string* errorMsg, bool* displayErrPopup);

				virtual void execute(std::function<void()> callback) override;
			private:
				int m_jobId;
				InventoryViewModel* m_inventoryViewModel;
				std::vector<JobViewModel>& m_jobs;
				std::string* m_errorMsg;
				bool* m_displayErrPopup;
			};
		}
	}
}

#endif // !W_ACCEPT_JOB_COMMAND_H