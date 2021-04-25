#ifndef PLAYER_VIEWMODEL_H
#define PLAYER_VIEWMODEL_H

#include <sstream>
#include "../models/Storage.h"

namespace UbiWorkshop
{
	namespace ViewModels
	{
		using namespace UbiWorkshop::Models;

		class PlayerViewModel
		{
		public:
			const bool buyTool(int toolIndex) noexcept;
			const std::string GetBuyStatusMsg() const noexcept;
		private:
			std::string m_buyMessage;
		};
	}
}

#endif // !PLAYER_VIEWMODEL_H

