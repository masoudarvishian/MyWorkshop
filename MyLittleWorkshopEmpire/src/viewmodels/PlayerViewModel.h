#ifndef PLAYER_VIEWMODEL_H
#define PLAYER_VIEWMODEL_H

#include <sstream>
#include "../Storage.h"

class PlayerViewModel
{
public:
	void buyTool(int toolIndex);
	std::string buyMessage;
};

#endif // !PLAYER_VIEWMODEL_H

