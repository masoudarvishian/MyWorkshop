#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include <list>
#include <memory>
#include "Malfunction.h"
#include "JobManager.h"

namespace UbiWorkshop
{
    namespace Models
    {
        class Vehicle
        {
        public:
            Vehicle(const char* type) noexcept;

            ~Vehicle();

            void AddMalfunction(std::unique_ptr<Malfunction> value) noexcept;
            void RemoveMalfunction(int malfunctionId) noexcept;
            const int GetId() const noexcept;
            const std::string GetType() const noexcept;
            const std::list<Malfunction*> GetListOfMalfunction() const noexcept;

        private:
            std::string m_type;
            std::list<std::unique_ptr<Malfunction>> m_malfunctions;
            int m_id;
        };
    }
}

#endif

