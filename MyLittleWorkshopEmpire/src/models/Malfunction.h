#ifndef MALFUNCTION_H
#define MALFUNCTION_H

#include <string>
#include <list>
#include "Tool.h"

class Malfunction
{
public:
    Malfunction(const char* name, const std::list<Tool*> tools, const int rewardAmount) noexcept;

    ~Malfunction();

    std::string GetName() const noexcept;
    int GetFixCosts() const noexcept;
    std::list<Tool*> GetNeededTools() const noexcept;

private:
    std::string m_name;
    std::list<Tool*> m_tools;
    int m_rewardAmount;
};

#endif 
