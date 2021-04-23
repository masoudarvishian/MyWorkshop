#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include <list>
#include <memory>
#include "Malfunction.h"

class Vehicle
{
public:
    Vehicle(const char* type) noexcept;

    ~Vehicle();

    void AddMalfunction(std::shared_ptr<Malfunction> value) noexcept;
    std::string GetType() const noexcept;
    std::list<std::shared_ptr<Malfunction>> GetListOfMalfunction() const noexcept;

private:
    std::string m_type;
    std::list<std::shared_ptr<Malfunction>> m_malfunctions;
};

#endif

