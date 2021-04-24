#include "HelpViewModel.h"

std::string HelpViewModel::getHelp() const noexcept
{
	auto helpModel = std::make_unique<HelpModel>();
	return helpModel->getHelp();
}
