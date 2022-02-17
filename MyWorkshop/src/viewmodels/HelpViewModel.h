#ifndef HELP_VIEWMODEL_H
#define HELP_VIEWMODEL_H

#include <string>
#include <memory>
#include "../models/HelpModel.h"

namespace MyWorkshop
{
	namespace ViewModels
	{
		using namespace MyWorkshop::Models;

		class HelpViewModel
		{
		public:
			std::string getHelp() const noexcept;
		};
	}
}

#endif

