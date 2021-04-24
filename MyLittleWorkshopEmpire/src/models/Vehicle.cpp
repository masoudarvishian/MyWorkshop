#include "Vehicle.h"

Vehicle::Vehicle(const char* type) noexcept : m_type{ type }
{}

Vehicle::~Vehicle()
{
    std::cout << "Vehicle: " << m_type << " is destroyed!\n";
}

void Vehicle::AddMalfunction(std::shared_ptr<Malfunction> value) noexcept
{
    m_malfunctions.push_back(value);
}

std::string Vehicle::GetType() const noexcept { return m_type.c_str(); }

std::list<std::shared_ptr<Malfunction>> Vehicle::GetListOfMalfunction() const noexcept { return m_malfunctions; }
