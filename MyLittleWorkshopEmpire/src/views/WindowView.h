#ifndef WINDOW_VIEW_H
#define WINDOW_VIEW_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "../vendor/imgui/imgui.h"
#include "../vendor/imgui/imgui_impl_glfw_gl3.h"

#include "ViewBase.h"
#include <iostream>

/* include viewmodels */
#include "../viewmodels/InventoryViewModel.h"
#include "../viewmodels/ShopViewModel.h"
#include "../viewmodels/PlayerViewModel.h"
#include "../viewmodels/DisplayJobsViewModel.h"
#include "../viewmodels/AcceptJobViewModel.h"
#include "cmd/CommandManager.h"
#include "cmd/Command.h"
#include "cmd/window-cmd/WBuyToolCommand.h"
#include "cmd/window-cmd/WAcceptJobCommand.h"

namespace UbiWorkshop
{
	namespace Views
	{
		using namespace UbiWorkshop::Views::WindowCommands;

		class WindowView : public ViewBase
		{
		public:
			WindowView();
			~WindowView();
			virtual void Run() override;
		private:
			void ErrorPopup(const std::string& errMsg) noexcept;
			void DisplayInventory(const ImGuiWindowFlags& window_flags) const noexcept;
			void DisplayStore(const ImGuiWindowFlags& window_flags, const std::vector<std::shared_ptr<Tool>>& shopTools) noexcept;
			void DisplayJobs(const ImGuiWindowFlags& window_flags, std::vector<JobViewModel>& jobs) noexcept;

			std::unique_ptr<ShopViewModel> m_shopViewModel;
			std::shared_ptr<DisplayJobsViewModel> m_displayJobsViewModel;
			std::shared_ptr<InventoryViewModel> m_inventoryViewModel;

			bool m_displayErrorPopup{ false };
			std::string m_errorMsg;
			std::unique_ptr<CommandManager> m_cmdManager;
		};
	}
}

#endif // !WINDOW_VIEW_H