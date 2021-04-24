#include "Vehicle.h"

Vehicle::Vehicle(const char* type) noexcept : m_type{ type }
{
    static int id{ 0 };
    m_id = ++id;
}

Vehicle::~Vehicle()
{
    std::cout << "Vehicle #" << m_id << " is destroyed!\n";
}

void Vehicle::AddMalfunction(std::shared_ptr<Malfunction> value) noexcept
{
    m_malfunctions.push_back(value);
}

const std::string Vehicle::GetType() const noexcept { return m_type; }

const std::list<std::shared_ptr<Malfunction>> Vehicle::GetListOfMalfunction() const noexcept { return m_malfunctions; }
