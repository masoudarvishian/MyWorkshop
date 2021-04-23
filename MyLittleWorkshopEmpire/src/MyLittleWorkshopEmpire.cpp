// MyLittleWorkshopEmpire.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Vehicle.h"
#include "Tool.h"
#include "Player.h"
#include "ToolManager.h"
#include <vector>
#include "cmd/CommandManager.h"
#include "cmd/TestCommand.h"
#include "cmd/HelpCommand.h"
#include "cmd/InventoryCommand.h"
#include "cmd/ShopCommand.h"
#include "cmd/BuyToolCommand.h"

int main()
{
	// create command manager
	auto cmdManager = std::make_unique<CommandManager>();

	auto player = std::make_unique<Player>();

	std::list<std::shared_ptr<Vehicle>> vehicles;

	// init tools
	ToolManager::GetInstance()->AddTool(std::make_shared<Tool>("Jack", 50));
	ToolManager::GetInstance()->AddTool(std::make_shared<Tool>("Torque brace", 40));

	// issue fixed: jumb cable was $50, but it should be 20$ based on document.
	ToolManager::GetInstance()->AddTool(std::make_shared<Tool>("Jumper Cables", 20));

	ToolManager::GetInstance()->AddTool(std::make_shared<Tool>("Phase tester", 10));
	ToolManager::GetInstance()->AddTool(std::make_shared<Tool>("Hammer", 20));
	ToolManager::GetInstance()->AddTool(std::make_shared<Tool>("Screwdriver", 10));

	// init players tools
	player->InitTool(ToolManager::GetInstance()->FindToolByName("Jack"));
	player->InitTool(ToolManager::GetInstance()->FindToolByName("Torque brace"));
	player->InitTool(ToolManager::GetInstance()->FindToolByName("Hammer"));

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
	requiredTools.push_back(ToolManager::GetInstance()->FindToolByName("Torquebrace"));
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

	vehicles.push_back(motorCycle);
	vehicles.push_back(compactCar);
	vehicles.push_back(racingCar);

	auto gameIsRunning{ true };
	std::string command;

	std::cout << "Hello Player!\nYou are about to lead your own Workshop.\n";
	std::cout << "In order to be successful you should : \n - keep an eye on your money\n - always have a set of Tools in your inventory\n - finish Jobs to earn Money which you can spent in the Hardware shop\n";

	while (gameIsRunning)
	{
		std::cout << "\nWhat do you want to do now? ";
		std::getline(std::cin, command);

		switch (command.at(0))
		{
		case 'h':   // help, listing all commands
		{
			cmdManager->add(std::make_shared<HelpCommand>());
		}
		break;
		case 'i':   // inventory
		{
			cmdManager->add(std::make_shared<InventoryCommand>(player.get()));
		}
		break;
		case 'j':   // jobs
			break;
		case 'a':   // accept job
			break;
		case 's':   // shop
		{
			cmdManager->add(std::make_shared<ShopCommand>());
		}
		break;
		case 'b':   // buy tool
		{
			auto index = 0;
			if (command.length() > 1)
			{
				index = std::stoi(command.substr(1, command.length()));
			}

			cmdManager->add(std::make_shared<BuyToolCommand>(player.get(), index));
		}
		break;
		case 'x':   // quit game
		{
			gameIsRunning = false;
			std::cout << "\n\n=== Memory Mangement Messages ===\n\n";
		}
		break;
		default:
			break;
		}
	}

	// release toolmanager's memory
	delete ToolManager::GetInstance();

	return 0;
}
