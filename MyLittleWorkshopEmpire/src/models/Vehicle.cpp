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

    // ADD JOB //
    // 
    // here we can fire an event, but because of time-limit/simplicity, I call the function directly
    std::vector<std::string> toolsName;
    auto requiredTools = value->GetNeededTools();
    for (auto tool : requiredTools)
    {
        toolsName.push_back(tool->GetName());
    }
    auto job = std::make_shared<Job>(m_id, value->GetId(), m_type, value->GetName(), value->GetRewardAmount(), toolsName);
    JobManager::GetInstance()->addJob(job);
}

const int Vehicle::GetId() const noexcept
{
    return m_id;
}

const std::string Vehicle::GetType() const noexcept { return m_type; }

const std::list<std::shared_ptr<Malfunction>> Vehicle::GetListOfMalfunction() const noexcept { return m_malfunctions; }
