#ifndef STORAGE_H
#define STORAGE_H

#include <memory>
#include "models/Vehicle.h"
#include "models/Tool.h"
#include "models/Player.h"
#include "models/ToolManager.h"

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

private:
	std::shared_ptr<Player> m_player;
	std::list<std::shared_ptr<Vehicle>> m_vehicles;

	// singleton
	static std::shared_ptr<Storage> _instance;
};
#endif // !STORAGE_H

