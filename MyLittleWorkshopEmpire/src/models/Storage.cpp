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

			auto tempTool = std::make_unique<Tool>("Jack", 50);
			ToolManager::GetInstance()->AddTool(std::move(tempTool));

			tempTool = std::make_unique<Tool>("Torque brace", 40);
			ToolManager::GetInstance()->AddTool(std::move(tempTool));

			tempTool = std::make_unique<Tool>("Jumper Cables", 20);
			ToolManager::GetInstance()->AddTool(std::move(tempTool));

			tempTool = std::make_unique<Tool>("Phase tester", 10);
			ToolManager::GetInstance()->AddTool(std::move(tempTool));

			tempTool = std::make_unique<Tool>("Hammer", 20);
			ToolManager::GetInstance()->AddTool(std::move(tempTool));

			tempTool = std::make_unique<Tool>("Screwdriver", 10);
			ToolManager::GetInstance()->AddTool(std::move(tempTool));

			// init players tools
			m_player->InitTool(ToolManager::GetInstance()->FindToolByName("Jack"));
			m_player->InitTool(ToolManager::GetInstance()->FindToolByName("Torque brace"));
			m_player->InitTool(ToolManager::GetInstance()->FindToolByName("Hammer"));

			// init first vehicle
			auto motorCycle = std::make_shared<Vehicle>("Motorcycle");

			std::list<Tool*> requiredTools;
			requiredTools.push_back(ToolManager::GetInstance()->FindToolByName("Jack"));
			requiredTools.push_back(ToolManager::GetInstance()->FindToolByName("Torque brace"));

			auto tempMalfunction = std::make_unique<Malfunction>("Flat tire", requiredTools, 18);
			motorCycle->AddMalfunction(std::move(tempMalfunction));

			requiredTools.clear();
			requiredTools.push_back(ToolManager::GetInstance()->FindToolByName("Jumper Cables"));
			requiredTools.push_back(ToolManager::GetInstance()->FindToolByName("Phase tester"));

			tempMalfunction = std::make_unique<Malfunction>("Empty battery", requiredTools, 6);
			motorCycle->AddMalfunction(std::move(tempMalfunction));

			requiredTools.clear();
			requiredTools.push_back(ToolManager::GetInstance()->FindToolByName("Phase tester"));
			
			tempMalfunction = std::make_unique<Malfunction>("Lights off", requiredTools, 2);
			motorCycle->AddMalfunction(std::move(tempMalfunction));

			// init second vehicle
			auto compactCar = std::make_shared<Vehicle>("Compact car");

			requiredTools.clear();
			requiredTools.push_back(ToolManager::GetInstance()->FindToolByName("Hammer"));
			requiredTools.push_back(ToolManager::GetInstance()->FindToolByName("Screwdriver"));
			requiredTools.push_back(ToolManager::GetInstance()->FindToolByName("Torque brace"));

			tempMalfunction = std::make_unique<Malfunction>("Shock Absorber broken", requiredTools, 14);
			compactCar->AddMalfunction(std::move(tempMalfunction));

			requiredTools.clear();
			requiredTools.push_back(ToolManager::GetInstance()->FindToolByName("Torque brace"));
			requiredTools.push_back(ToolManager::GetInstance()->FindToolByName("Screwdriver"));

			tempMalfunction = std::make_unique<Malfunction>("Engine failure", requiredTools, 10);
			compactCar->AddMalfunction(std::move(tempMalfunction));

			requiredTools.clear();
			requiredTools.push_back(ToolManager::GetInstance()->FindToolByName("Phase tester"));
			requiredTools.push_back(ToolManager::GetInstance()->FindToolByName("Screwdriver"));

			tempMalfunction = std::make_unique<Malfunction>("Defect spark plugs", requiredTools, 4);
			compactCar->AddMalfunction(std::move(tempMalfunction));

			requiredTools.clear();
			requiredTools.push_back(ToolManager::GetInstance()->FindToolByName("Jumper Cables"));
			requiredTools.push_back(ToolManager::GetInstance()->FindToolByName("Phase tester"));

			tempMalfunction = std::make_unique<Malfunction>("Empty Battery", requiredTools, 6);
			compactCar->AddMalfunction(std::move(tempMalfunction));

			// init third vehicle
			auto racingCar = std::make_shared<Vehicle>("Racing car");

			requiredTools.clear();
			requiredTools.push_back(ToolManager::GetInstance()->FindToolByName("Screwdriver"));
			requiredTools.push_back(ToolManager::GetInstance()->FindToolByName("Torque brace"));

			tempMalfunction = std::make_unique<Malfunction>("Gas pedal broken", requiredTools, 10);
			motorCycle->AddMalfunction(std::move(tempMalfunction));

			requiredTools.clear();
			requiredTools.push_back(ToolManager::GetInstance()->FindToolByName("Torque brace"));
			requiredTools.push_back(ToolManager::GetInstance()->FindToolByName("Screwdriver"));

			tempMalfunction = std::make_unique<Malfunction>("Engine failure", requiredTools, 10);
			racingCar->AddMalfunction(std::move(tempMalfunction));

			requiredTools.clear();
			requiredTools.push_back(ToolManager::GetInstance()->FindToolByName("Jack"));
			requiredTools.push_back(ToolManager::GetInstance()->FindToolByName("Torque brace"));

			tempMalfunction = std::make_unique<Malfunction>("Bald tire", requiredTools, 18);
			racingCar->AddMalfunction(std::move(tempMalfunction));

			requiredTools.clear();
			requiredTools.push_back(ToolManager::GetInstance()->FindToolByName("Hammer"));
			requiredTools.push_back(ToolManager::GetInstance()->FindToolByName("Screwdriver"));

			tempMalfunction = std::make_unique<Malfunction>("Bumper damaged", requiredTools, 6);
			racingCar->AddMalfunction(std::move(tempMalfunction));

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
