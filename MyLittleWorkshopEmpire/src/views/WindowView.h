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
	WindowView();
	~WindowView();
	virtual void Run() override;
private:
	void ErrorPopup(const std::string& errMsg) noexcept;
	void DisplayInventory(const ImGuiWindowFlags &window_flags) const noexcept;
	void DisplayStore(const ImGuiWindowFlags &window_flags, const std::vector<std::shared_ptr<Tool>> &shopTools) const noexcept;
	void DisplayJobs(const ImGuiWindowFlags& window_flags, std::vector<std::shared_ptr<Job>> &jobs) noexcept;

	std::unique_ptr<ShopViewModel> m_shopViewModel;
	std::unique_ptr<PlayerViewModel> m_playerViewModel;
	std::unique_ptr<AcceptJobViewModel> m_acceptJobViewModel;
	std::unique_ptr<DisplayJobsViewModel> m_displayJobsViewModel;
	std::unique_ptr<InventoryViewModel> m_inventoryViewModel;

	bool m_displayErrorPopup{ false };
	std::string m_errorMsg;
};

#endif // !WINDOW_VIEW_H