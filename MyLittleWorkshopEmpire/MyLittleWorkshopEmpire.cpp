// MyLittleWorkshopEmpire.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Vehicle.h"
#include "Tool.h"
#include "Player.h"
#include "ToolManager.h"

int main()
{
	Player* player = new Player();

	std::list<Vehicle*> vehicles;

	// init tools
	ToolManager::GetInstance()->AddTool(new Tool("Jack", 50));
	ToolManager::GetInstance()->AddTool(new Tool("Torque brace", 40));

	// issue fixed: jumb cable was $50, but it should be 20$ based on document.
	ToolManager::GetInstance()->AddTool(new Tool("Jumper Cables", 20));
	/////////////////////////////////////////////////////////////////////

	ToolManager::GetInstance()->AddTool(new Tool("Phase tester", 10));
	ToolManager::GetInstance()->AddTool(new Tool("Hammer", 20));
	ToolManager::GetInstance()->AddTool(new Tool("Screwdriver", 10));

	// init players tools
	player->InitTool(ToolManager::GetInstance()->FindToolByName("Jack"));
	player->InitTool(ToolManager::GetInstance()->FindToolByName("Torque brace"));
	player->InitTool(ToolManager::GetInstance()->FindToolByName("Hammer"));

	// init first vehicle
	Vehicle* motorCycle = new Vehicle("Motorcycle");

	std::list<Tool*> requiredTools;
	requiredTools.push_back(ToolManager::GetInstance()->FindToolByName("Jack"));
	requiredTools.push_back(ToolManager::GetInstance()->FindToolByName("Torque brace"));
	motorCycle->AddMalfunction(new Malfunction("Flat tire", requiredTools, 18));

	requiredTools.clear();
	requiredTools.push_back(ToolManager::GetInstance()->FindToolByName("Jumper Cables"));
	requiredTools.push_back(ToolManager::GetInstance()->FindToolByName("Phase tester"));
	motorCycle->AddMalfunction(new Malfunction("Empty battery", requiredTools, 6));

	requiredTools.clear();
	requiredTools.push_back(ToolManager::GetInstance()->FindToolByName("Phase tester"));
	motorCycle->AddMalfunction(new Malfunction("Lights off", requiredTools, 2));

	// init second vehicle
	Vehicle* compactCar = new Vehicle("Compact car");

	requiredTools.clear();
	requiredTools.push_back(ToolManager::GetInstance()->FindToolByName("Hammer"));
	requiredTools.push_back(ToolManager::GetInstance()->FindToolByName("Screwdriver"));
	requiredTools.push_back(ToolManager::GetInstance()->FindToolByName("Torque brace"));
	compactCar->AddMalfunction(new Malfunction("Shock Absorber broken", requiredTools, 14));

	requiredTools.clear();
	requiredTools.push_back(ToolManager::GetInstance()->FindToolByName("Torque brace"));
	requiredTools.push_back(ToolManager::GetInstance()->FindToolByName("Screwdriver"));
	compactCar->AddMalfunction(new Malfunction("Engine failure", requiredTools, 10));

	requiredTools.clear();
	requiredTools.push_back(ToolManager::GetInstance()->FindToolByName("Phase tester"));
	requiredTools.push_back(ToolManager::GetInstance()->FindToolByName("Screwdriver"));
	compactCar->AddMalfunction(new Malfunction("Defect spark plugs", requiredTools, 4));

	requiredTools.clear();
	requiredTools.push_back(ToolManager::GetInstance()->FindToolByName("Jumper Cables"));
	requiredTools.push_back(ToolManager::GetInstance()->FindToolByName("Phase tester"));
	compactCar->AddMalfunction(new Malfunction("Empty Battery", requiredTools, 6));

	// init third vehicle
	Vehicle* racingCar = new Vehicle("Racing car");

	requiredTools.clear();
	requiredTools.push_back(ToolManager::GetInstance()->FindToolByName("Screwdriver"));
	requiredTools.push_back(ToolManager::GetInstance()->FindToolByName("Torque brace"));
	motorCycle->AddMalfunction(new Malfunction("Gas pedal broken", requiredTools, 10));

	requiredTools.clear();
	requiredTools.push_back(ToolManager::GetInstance()->FindToolByName("Torquebrace"));
	requiredTools.push_back(ToolManager::GetInstance()->FindToolByName("Screwdriver"));
	racingCar->AddMalfunction(new Malfunction("Engine failure", requiredTools, 10));

	requiredTools.clear();
	requiredTools.push_back(ToolManager::GetInstance()->FindToolByName("Jack"));
	requiredTools.push_back(ToolManager::GetInstance()->FindToolByName("Torque brace"));
	racingCar->AddMalfunction(new Malfunction("Bald tire", requiredTools, 18));

	requiredTools.clear();
	requiredTools.push_back(ToolManager::GetInstance()->FindToolByName("Hammer"));
	requiredTools.push_back(ToolManager::GetInstance()->FindToolByName("Screwdriver"));
	racingCar->AddMalfunction(new Malfunction("Bumper damaged", requiredTools, 6));

	vehicles.push_back(motorCycle);
	vehicles.push_back(compactCar);
	vehicles.push_back(racingCar);

	bool gameIsRunning = true;
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
			std::cout << "HELP - here are all possible commands you could use:\n";
			std::cout << "  'i'         Inventory: your amount of Money and your available Tools\n";
			std::cout << "  'j'         Jobs: a list of available Jobs\n";
			std::cout << "  'a[index]' Accept a Job: using the index of the Job list. Example: when typing 'a2' you will accept the Job at index 2\n";
			std::cout << "  's'         Shop: a list of all available Tools and the Price\n";
			std::cout << "  'b[index]'  Buy a Tool: using the index of the Shop list. Example: when typing 'b0' you will buy the first Tool available in the Shop\n";
			std::cout << "  'x'         Quit Game\n";
		}
		break;
		case 'i':   // inventory
		{
			player->PrintInventory();
		}
		break;
		case 'j':   // jobs
			break;
		case 'a':   // accept job
			break;
		case 's':   // shop
		{
			ToolManager::GetInstance()->PrintToolInShop();
		}
		break;
		case 'b':   // buy tool
		{
			int index = 0;
			if (command.length() > 1)
			{
				index = std::stoi(command.substr(1, command.length()));
			}
			Tool* toolToBuy = ToolManager::GetInstance()->GetToolByIndex(index);
			player->BuyTool(toolToBuy);
		}
		break;
		case 'x':   // quit game
		{
			gameIsRunning = false;
		}
		break;
		default:
			break;
		}
	}

	delete player;

	return 0;
}
