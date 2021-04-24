#include "Vehicle.h"
#include "map"

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

    ///// ADD A JOB /////
    // here we can fire an event, but because of time-limit/simplicity, I call the function directly
    std::map<int, std::string> toolsIdName;
    auto requiredTools = value->GetNeededTools();
    for (auto tool : requiredTools)
    {
        toolsIdName[tool->GetId()] = tool->GetName();
    }
    auto job = std::make_shared<Job>(m_id, value->GetId(), m_type, value->GetName(), value->GetRewardAmount(), toolsIdName);
    JobManager::GetInstance()->AddJob(job);
}

void Vehicle::RemoveMalfunction(int malfunctionId) noexcept
{
    auto search = std::find_if(m_malfunctions.begin(), m_malfunctions.end(), [&malfunctionId](std::shared_ptr<Malfunction>& m) {
        return malfunctionId == m.get()->GetId();
    });

    if (search != m_malfunctions.end())
    {
        auto index = std::distance(m_malfunctions.begin(), search);
        auto iter = m_malfunctions.begin();
        std::advance(iter, index);
        m_malfunctions.erase(iter);
    }
}

const int Vehicle::GetId() const noexcept
{
    return m_id;
}

const std::string Vehicle::GetType() const noexcept { return m_type; }

const std::list<std::shared_ptr<Malfunction>> Vehicle::GetListOfMalfunction() const noexcept { return m_malfunctions; }
