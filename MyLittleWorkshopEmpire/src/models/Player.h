#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <map>
#include <iostream>
#include "Tool.h"

namespace UbiWorkshop
{
	namespace Models
	{
		constexpr int START_MONEY = 200;

		class Player
		{
		public:

			Player();
			~Player();

			bool BuyTool(Tool* tool) noexcept;
			void DamageTool(Tool* tool) noexcept;
			void InitTool(Tool* tool) noexcept;

			const int getMoney() const noexcept;
			void AddMoney(int amout) noexcept;

			std::map<Tool*, int> getUsableTools() const noexcept;

		private:
			int m_money;
			std::map<Tool*, int> m_usableTools; // <Tool,UsageCount>
			int m_id;
		};
	}
}

#endif
