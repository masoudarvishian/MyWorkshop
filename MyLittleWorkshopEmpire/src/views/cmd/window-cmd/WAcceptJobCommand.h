#ifndef W_ACCEPT_JOB_COMMAND_H
#define W_ACCEPT_JOB_COMMAND_H

#include <functional>
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
				WAcceptJobCommand(int jobId, std::vector<JobViewModel>& jobs, std::string* errorMsg, 
					bool* displayErrPopup, std::function<void()> onSuccess);

				virtual void execute(std::function<void()> callback) override;
			private:
				int m_jobId;
				std::vector<JobViewModel>& m_jobs;
				std::string* m_errorMsg;
				bool* m_displayErrPopup;
				std::function<void()> m_onSuccess;
			};
		}
	}
}

#endif // !W_ACCEPT_JOB_COMMAND_H