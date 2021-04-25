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
				WAcceptJobCommand(int jobId, AcceptJobViewModel* acceptJobViewModel, InventoryViewModel* inventoryViewModel,
					DisplayJobsViewModel* displayJobsViewModel, std::vector<JobViewModel>& jobs, std::string* errorMsg, bool* displayErrPopup);

				virtual void execute(std::function<void()> callback) override;
			private:
				int m_jobId;
				AcceptJobViewModel* m_acceptJobViewModel;
				InventoryViewModel* m_inventoryViewModel;
				DisplayJobsViewModel* m_displayJobsViewModel;
				std::vector<JobViewModel>& m_jobs;
				std::string* m_errorMsg;
				bool* m_displayErrPopup;
			};
		}
	}
}

#endif // !W_ACCEPT_JOB_COMMAND_H