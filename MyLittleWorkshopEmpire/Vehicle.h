#pragma once
#include <string>
#include <list>
#include "Tool.h"

class Malfunction
{
public:
    /* issue fixed: the "fixCosts" property name is not right, it should be "reward", so the programmer 
       will consider this as final reward not a cost that reduce from player! */
    Malfunction(const char* name, const std::list<Tool*> tools, const int reward)
    {
        m_name = name;
        m_tools = tools;
        m_fixCosts = reward;
    }

    ~Malfunction()
    {
    }

    std::string GetName() { return m_name.c_str(); }
    int GetFixCosts() { return m_fixCosts;  }
    std::list<Tool*> GetNeededTools() { return m_tools; }

private:
    std::string m_name;
    std::list<Tool*> m_tools;
    int m_fixCosts;
};

class Vehicle
{
public:
    Vehicle(const char* type)
    {
        m_type = type;
    }

    ~Vehicle()
    {
    }

    void AddMalfunction(Malfunction* value)
    {
        m_malfunctions.push_back(value);
    }

    std::string GetType() { return m_type.c_str(); }
    std::list<Malfunction*> GetListOfMalfunction() { return m_malfunctions; }

private:
    std::string m_type;
    std::list<Malfunction*> m_malfunctions;
};

