#ifndef PLAYER_VIEWMODEL_H
#define PLAYER_VIEWMODEL_H

#include <sstream>
#include "../models/Storage.h"

namespace MyWorkshop
{
	namespace ViewModels
	{
		using namespace MyWorkshop::Models;

		class PlayerViewModel
		{
		public:
			PlayerViewModel() { printf("PlayerViewModel is created!\n"); }
			~PlayerViewModel() { printf("PlayerViewModel is destroyed!\n"); }
			const bool buyTool(int toolIndex) noexcept;
			const std::string GetBuyStatusMsg() const noexcept;
		private:
			std::string m_buyMessage;
		};
	}
}

#endif // !PLAYER_VIEWMODEL_H

