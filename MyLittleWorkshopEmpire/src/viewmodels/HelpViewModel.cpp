#include "HelpViewModel.h"

namespace UbiWorkshop
{
	namespace ViewModels
	{
		std::string HelpViewModel::getHelp() const noexcept
		{
			auto helpModel = std::make_unique<HelpModel>();
			return helpModel->getHelp();
		}
	}
}
