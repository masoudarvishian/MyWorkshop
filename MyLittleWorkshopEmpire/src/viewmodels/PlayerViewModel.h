#ifndef PLAYER_VIEWMODEL_H
#define PLAYER_VIEWMODEL_H

#include <sstream>
#include "../Storage.h"

class PlayerViewModel
{
public:
	const bool buyTool(int toolIndex) noexcept;
	const std::string GetBuyStatusMsg() const noexcept;
private:
	std::string m_buyMessage;
};

#endif // !PLAYER_VIEWMODEL_H

