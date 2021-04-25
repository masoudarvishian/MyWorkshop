#ifndef MALFUNCTION_H
#define MALFUNCTION_H

#include <string>
#include <list>
#include "Tool.h"

namespace UbiWorkshop
{
    namespace Models
    {
        class Malfunction
        {
        public:
            Malfunction(const char* name, const std::list<Tool*> tools, const int rewardAmount) noexcept;

            ~Malfunction();

            const int GetId() const noexcept;
            const std::string GetName() const noexcept;
            const int GetRewardAmount() const noexcept;
            std::list<Tool*> GetNeededTools() const noexcept;

        private:
            std::string m_name;
            std::list<Tool*> m_tools;
            int m_rewardAmount;
            int m_id;
        };
    }
}

#endif 
