#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include <list>
#include "Malfunction.h"

class Vehicle
{
public:
    Vehicle(const char* type) noexcept;

    ~Vehicle()
    {
    }

    void AddMalfunction(Malfunction* value) noexcept;
    std::string GetType() const noexcept;
    std::list<Malfunction*> GetListOfMalfunction() const noexcept;

private:
    std::string m_type;
    std::list<Malfunction*> m_malfunctions;
};

#endif

