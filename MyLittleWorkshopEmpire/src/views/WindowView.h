#ifndef WINDOW_VIEW_H
#define WINDOW_VIEW_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "../vendor/imgui/imgui.h"
#include "../vendor/imgui/imgui_impl_glfw_gl3.h"

#include "ViewBase.h"
#include <iostream>

// include viewmodels
#include "../viewmodels/InventoryViewModel.h"
#include "../viewmodels/ShopViewModel.h"
#include "../viewmodels/PlayerViewModel.h"
#include "../viewmodels/DisplayJobsViewModel.h"
#include "../viewmodels/AcceptJobViewModel.h"

class WindowView : public ViewBase
{
public:
	~WindowView();
	virtual void Run() override;
};

#endif // !WINDOW_VIEW_H

