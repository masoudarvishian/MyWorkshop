#ifndef JOB_H
#define JOH_H

#include <iostream>

class Job
{
public:
	Job(int vehicleIndex, int malfunctionIndex);
	~Job();
    
	const int getId() const noexcept;
	const int getVehicleId() const noexcept;
	const int getMalfunctionId() const noexcept;
private:
	int m_id;
	int m_vehicleId;
	int m_malfunctionId;
};
#endif // !JOB_H

