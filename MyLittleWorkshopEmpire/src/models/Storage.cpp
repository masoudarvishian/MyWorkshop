#include "Storage.h"

namespace UbiWorkshop
{
	namespace Models
	{
		std::shared_ptr<Storage> Storage::_instance{ nullptr };

		Storage::~Storage()
		{
			std::cout << "Storage is destroyed!\n";
		}

		void Storage::init()
		{
			m_player = std::make_shared<Player>();

			// init tools
			ToolManager::GetInstance()->AddTool(std::make_shared<Tool>("Jack", 50));
			ToolManager::GetInstance()->AddTool(std::make_shared<Tool>("Torque brace", 40));
			ToolManager::GetInstance()->AddTool(std::make_shared<Tool>("Jumper Cables", 20));
			ToolManager::GetInstance()->AddTool(std::make_shared<Tool>("Phase tester", 10));
			ToolManager::GetInstance()->AddTool(std::make_shared<Tool>("Hammer", 20));
			ToolManager::GetInstance()->AddTool(std::make_shared<Tool>("Screwdriver", 10));

			// init players tools
			m_player->InitTool(ToolManager::GetInstance()->FindToolByName("Jack"));
			m_player->InitTool(ToolManager::GetInstance()->FindToolByName("Torque brace"));
			m_player->InitTool(ToolManager::GetInstance()->FindToolByName("Hammer"));

			// init first vehicle
			auto motorCycle = std::make_shared<Vehicle>("Motorcycle");

			std::list<Tool*> requiredTools;
			requiredTools.push_back(ToolManager::GetInstance()->FindToolByName("Jack"));
			requiredTools.push_back(ToolManager::GetInstance()->FindToolByName("Torque brace"));
			motorCycle->AddMalfunction(std::make_shared<Malfunction>("Flat tire", requiredTools, 18));

			requiredTools.clear();
			requiredTools.push_back(ToolManager::GetInstance()->FindToolByName("Jumper Cables"));
			requiredTools.push_back(ToolManager::GetInstance()->FindToolByName("Phase tester"));
			motorCycle->AddMalfunction(std::make_shared<Malfunction>("Empty battery", requiredTools, 6));

			requiredTools.clear();
			requiredTools.push_back(ToolManager::GetInstance()->FindToolByName("Phase tester"));
			motorCycle->AddMalfunction(std::make_shared<Malfunction>("Lights off", requiredTools, 2));

			// init second vehicle
			auto compactCar = std::make_shared<Vehicle>("Compact car");

			requiredTools.clear();
			requiredTools.push_back(ToolManager::GetInstance()->FindToolByName("Hammer"));
			requiredTools.push_back(ToolManager::GetInstance()->FindToolByName("Screwdriver"));
			requiredTools.push_back(ToolManager::GetInstance()->FindToolByName("Torque brace"));
			compactCar->AddMalfunction(std::make_shared<Malfunction>("Shock Absorber broken", requiredTools, 14));

			requiredTools.clear();
			requiredTools.push_back(ToolManager::GetInstance()->FindToolByName("Torque brace"));
			requiredTools.push_back(ToolManager::GetInstance()->FindToolByName("Screwdriver"));
			compactCar->AddMalfunction(std::make_shared<Malfunction>("Engine failure", requiredTools, 10));

			requiredTools.clear();
			requiredTools.push_back(ToolManager::GetInstance()->FindToolByName("Phase tester"));
			requiredTools.push_back(ToolManager::GetInstance()->FindToolByName("Screwdriver"));
			compactCar->AddMalfunction(std::make_shared<Malfunction>("Defect spark plugs", requiredTools, 4));

			requiredTools.clear();
			requiredTools.push_back(ToolManager::GetInstance()->FindToolByName("Jumper Cables"));
			requiredTools.push_back(ToolManager::GetInstance()->FindToolByName("Phase tester"));
			compactCar->AddMalfunction(std::make_shared<Malfunction>("Empty Battery", requiredTools, 6));

			// init third vehicle
			auto racingCar = std::make_shared<Vehicle>("Racing car");

			requiredTools.clear();
			requiredTools.push_back(ToolManager::GetInstance()->FindToolByName("Screwdriver"));
			requiredTools.push_back(ToolManager::GetInstance()->FindToolByName("Torque brace"));
			motorCycle->AddMalfunction(std::make_shared<Malfunction>("Gas pedal broken", requiredTools, 10));

			requiredTools.clear();
			requiredTools.push_back(ToolManager::GetInstance()->FindToolByName("Torque brace"));
			requiredTools.push_back(ToolManager::GetInstance()->FindToolByName("Screwdriver"));
			racingCar->AddMalfunction(std::make_shared<Malfunction>("Engine failure", requiredTools, 10));

			requiredTools.clear();
			requiredTools.push_back(ToolManager::GetInstance()->FindToolByName("Jack"));
			requiredTools.push_back(ToolManager::GetInstance()->FindToolByName("Torque brace"));
			racingCar->AddMalfunction(std::make_shared<Malfunction>("Bald tire", requiredTools, 18));

			requiredTools.clear();
			requiredTools.push_back(ToolManager::GetInstance()->FindToolByName("Hammer"));
			requiredTools.push_back(ToolManager::GetInstance()->FindToolByName("Screwdriver"));
			racingCar->AddMalfunction(std::make_shared<Malfunction>("Bumper damaged", requiredTools, 6));

			m_vehicles.push_back(motorCycle);
			m_vehicles.push_back(compactCar);
			m_vehicles.push_back(racingCar);
		}

		Player* Storage::getPlayer() const noexcept
		{
			return m_player.get();
		}

		Storage* Storage::GetInstance() noexcept
		{
			if (_instance == nullptr)
			{
				_instance = std::make_shared<Storage>();
			}
			return _instance.get();
		}

		const std::list<std::shared_ptr<Vehicle>> Storage::getVehicles() const noexcept
		{
			return m_vehicles;
		}
	}
}
