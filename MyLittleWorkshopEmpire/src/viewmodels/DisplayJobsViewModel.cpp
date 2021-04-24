#include "DisplayJobsViewModel.h"

const std::vector<std::string> DisplayJobsViewModel::getJobs() const noexcept
{
	auto jsss = JobManager::GetInstance()->getJobs();

	auto vehicles = Storage::GetInstance()->getVehicles();
	std::vector<std::string> jobDescriptionList;

	auto vehicleCounter{ 0 };
	for (auto iter{ vehicles.begin() }; iter != vehicles.end(); ++iter)
	{
	    auto vehicleType = iter->get()->GetType();
		auto malfunctions = iter->get()->GetListOfMalfunction();

		auto mulfunctionCounter{ 0 };
		for (auto malfIter{ malfunctions.begin() }; malfIter != malfunctions.end(); ++malfIter)
		{
			auto currentMalfunction = malfIter->get();
			auto malfunctionName = currentMalfunction->GetName();
			auto malfunctionNeededTools = currentMalfunction->GetNeededTools();
			auto rewardAmount = currentMalfunction->GetRewardAmount();

			std::string jobStr = "job id: " + std::to_string(vehicleCounter) + '-' + std::to_string(mulfunctionCounter) +
								 ", Vehicle: " + vehicleType + ", Mulfunction: " + malfunctionName +
								 ", Reward: " + std::to_string(rewardAmount) + "$\n   Required Tools: ";

			auto toolCounter{ 1 };
			for (auto tool : malfunctionNeededTools)
			{
				auto toolName = tool->GetName();
				auto toolPrice = tool->GetPrice();

				jobStr += " " + (std::to_string(toolCounter) + "." + toolName + " " + std::to_string(toolPrice) +"$");
				++toolCounter;
			}
			
			jobDescriptionList.push_back(jobStr);
			
			++mulfunctionCounter;
		}

		++vehicleCounter;
	}

	return jobDescriptionList;
}
