#ifndef TOOL_H
#define TOOL_H

#include <string>
#include <iostream>

namespace UbiWorkshop
{
	namespace Models
	{
		constexpr int MAX_WEAR_COUNT = 5;
		class ToolManager;

		class Tool
		{
		public:

			Tool(const char* name, const int price) noexcept;

			~Tool();

			const int GetId() const noexcept;
			const std::string GetName() const noexcept;
			const int GetPrice() const noexcept;
			const int GetMaxWearCount() const noexcept;

		private:
			std::string m_name;
			int m_price;
			int m_id;
		};
	}
}

#endif 