#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include <list>
#include <memory>
#include "Malfunction.h"
#include "JobManager.h"

class Vehicle
{
public:
    Vehicle(const char* type) noexcept;

    ~Vehicle();

    void AddMalfunction(std::shared_ptr<Malfunction> value) noexcept;
    void RemoveMalfunction(int malfunctionId) noexcept;
    const int GetId() const noexcept;
    const std::string GetType() const noexcept;
    const std::list<std::shared_ptr<Malfunction>> GetListOfMalfunction() const noexcept;

private:
    std::string m_type;
    std::list<std::shared_ptr<Malfunction>> m_malfunctions;
    int m_id;
};

#endif

