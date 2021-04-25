#ifndef ACCEPT_JOB_VIEWMODEL_H
#define ACCEPT_JOB_VIEWMODEL_H

#include <string>
#include "../models/JobManager.h"

namespace UbiWorkshop 
{
	namespace ViewModels
	{
		using namespace UbiWorkshop::Models;

		class AcceptJobViewModel
		{
		public:
			bool AcceptJob(int jobId) noexcept;
			const std::string GetStatusMsg() const noexcept;
		private:
			std::string m_finalMsg;
		};
	}
}

#endif // !ACCEPT_JOB_VIEWMODEL_H

