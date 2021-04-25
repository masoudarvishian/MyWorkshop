#include "JobManager.h"
namespace UbiWorkshop
{
	namespace Models
	{
		std::shared_ptr<JobManager> JobManager::_instance{ nullptr };

		JobManager::~JobManager()
		{
			std::cout << "JobManager is destroyed!\n";
		}

		JobManager* JobManager::GetInstance() noexcept
		{
			if (_instance == nullptr)
			{
				_instance = std::make_shared<JobManager>();
			}
			return _instance.get();
		}

		void JobManager::AddJob(std::shared_ptr<Job> job) noexcept
		{
			m_jobs.push_back(job);
		}

		void JobManager::RemoveJob(int jobId) noexcept
		{
			auto search = std::find_if(m_jobs.begin(), m_jobs.end(), [&jobId](std::shared_ptr<Job>& j) {
				return jobId == j.get()->GetId();
				});

			if (search != m_jobs.end())
			{
				auto index = std::distance(m_jobs.begin(), search);
				m_jobs.erase(m_jobs.begin() + index);
			}
		}

		const std::vector<std::shared_ptr<Job>> JobManager::GetJobs() const noexcept
		{
			return m_jobs;
		}

		bool JobManager::AcceptJob(int jobId) noexcept
		{
			auto job{ FindJob(jobId) };

			if (!job)
			{
				return false;
			}

			auto player = Storage::GetInstance()->getPlayer();
			auto playerTools{ player->getUsableTools() }; // map < tool , damage >
			auto requiredTools{ job->GetToolsIdName() };  // map < tool id , tool name >

			auto jobSucceed{ true };

			// check if player tools meet the job required tools or not && check if player's tool is broken or not
			for (auto requiredTool : requiredTools)
			{
				if (!jobSucceed) { break; }

				auto search = std::find_if(playerTools.begin(), playerTools.end(), [&requiredTool](std::pair<Tool*, int> pt) {
					return (requiredTool.first == pt.first->GetId()) && (pt.second > 0);
					});

				if (search == playerTools.end())
				{
					// player doesn't have the requierd tools
					jobSucceed = false;
					break;
				}
			}

			if (!jobSucceed)
			{
				return false;
			}

			// now we can accept the job
			// give reward to user
			player->AddMoney(job->GetRewardAmount());
			// remove the malfuction from vehicle
			Vehicle* vehicle{ nullptr };
			auto vehicles = Storage::GetInstance()->getVehicles();
			auto searchVehicle = std::find_if(vehicles.begin(), vehicles.end(), [&job](std::shared_ptr<Vehicle> v) {
				return v->GetId() == job->GetVehicleId();
				});
			if (searchVehicle != vehicles.end())
			{
				auto index = std::distance(vehicles.begin(), searchVehicle);
				auto iter = vehicles.begin();
				std::advance(iter, index);

				vehicle = (*iter).get();

				vehicle->RemoveMalfunction(job->GetMalfunctionId());
			}
			// give 50% damage to the tools
			for (auto pt : playerTools)
			{
				auto search = std::find_if(requiredTools.begin(), requiredTools.end(), [&pt](std::pair<int, std::string> rq) {
					return pt.first->GetId() == rq.first;
					});

				if (search != requiredTools.end())
				{
					auto tool = pt.first;
					player->DamageTool(tool);
				}
			}
			// remove the job from job list
			RemoveJob(jobId);

			return true;
		}

		Job* JobManager::FindJob(int jobId) const noexcept
		{
			Job* job{ nullptr };

			auto allJobs = GetJobs();
			auto search = std::find_if(allJobs.begin(), allJobs.end(), [&jobId](std::shared_ptr<Job>& j) {
				return j->GetId() == jobId;
				});

			if (search != allJobs.end())
			{
				auto index = std::distance(allJobs.begin(), search);
				job = allJobs.at(index).get();
			}

			return job;
		}
	}
}