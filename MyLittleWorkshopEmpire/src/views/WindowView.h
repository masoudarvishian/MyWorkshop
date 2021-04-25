#ifndef WINDOW_VIEW_H
#define WINDOW_VIEW_H

#include <GLFW/glfw3.h>
#include "ViewBase.h"
#include <iostream>

class WindowView : public ViewBase
{
public:
	~WindowView();
	virtual void Run() override;
};

#endif // !WINDOW_VIEW_H

