#ifndef STORAGE_H
#define STORAGE_H

#include <memory>
#include "Vehicle.h"
#include "Tool.h"
#include "Player.h"
#include "ToolManager.h"

namespace UbiWorkshop
{
	namespace Models 
	{
		class Vehicle;

		class Storage
		{
		public:
			// it's singleton, and cannot have copy constructor and operator=
			Storage(Storage& other) = delete;
			void operator=(const Storage&) = delete;

			Storage() {};
			~Storage();

			void init();
			Player* getPlayer() const noexcept;

			// singleton pattern
			static Storage* GetInstance() noexcept;

			const std::list<Vehicle*> GetVehicles() const noexcept;

		private:
			std::unique_ptr<Player> m_player;
			std::list<std::unique_ptr<Vehicle>> m_vehicles;

			// singleton
			static std::unique_ptr<Storage> _instance;
		};
	}
}
#endif // !STORAGE_H

