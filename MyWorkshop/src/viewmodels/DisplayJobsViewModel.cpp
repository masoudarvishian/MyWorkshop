#include "DisplayJobsViewModel.h"

namespace MyWorkshop
{
	namespace ViewModels
	{
		const std::vector<JobViewModel> DisplayJobsViewModel::GetJobs() const noexcept
		{
			auto jobs = JobManager::GetInstance()->GetJobs();

			std::vector<JobViewModel> jobViewModels;

			// map data to viewmodel
			for (auto job : jobs)
			{
				JobViewModel jViewModel;
				jViewModel.id = job->GetId();
				jViewModel.malfunctionId = job->GetMalfunctionId();
				jViewModel.malfunctionName = job->GetMalfanctionName();
				jViewModel.rewardAmount = job->GetRewardAmount();
				jViewModel.vehicleId = job->GetVehicleId();
				jViewModel.vehicleType = job->GetVehicleType();

				for (auto item : job->GetToolsIdName())
				{
					jViewModel.toolsIdName[item.first] = item.second;
				}

				jobViewModels.push_back(jViewModel);
			}

			return jobViewModels;
		}
	}
}
