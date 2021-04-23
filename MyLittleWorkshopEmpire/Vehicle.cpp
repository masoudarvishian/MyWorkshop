#include "Vehicle.h"

Vehicle::Vehicle(const char* type) noexcept : m_type{ type }
{}

void Vehicle::AddMalfunction(Malfunction* value) noexcept
{
    m_malfunctions.push_back(value);
}

std::string Vehicle::GetType() const noexcept { return m_type.c_str(); }

std::list<Malfunction*> Vehicle::GetListOfMalfunction() const noexcept { return m_malfunctions; }
