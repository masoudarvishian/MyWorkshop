#ifndef HELP_MODEL_H
#define HELP_MODEL_H

#include <string>

namespace MyWorkshop
{
	namespace Models
	{
		class HelpModel
		{
		public:
			HelpModel() noexcept;

			std::string getHelp() const noexcept;

		private:
			std::string m_helpStr;
		};
	}
}

#endif // !HELP_MODEL_H

