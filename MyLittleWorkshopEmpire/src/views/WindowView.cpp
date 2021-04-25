#include "WindowView.h"

WindowView::WindowView()
{
	m_shopViewModel = std::make_unique<ShopViewModel>();
	m_playerViewModel = std::make_unique<PlayerViewModel>();
	m_acceptJobViewModel = std::make_unique<AcceptJobViewModel>();
	m_displayJobsViewModel = std::make_unique<DisplayJobsViewModel>();
	m_inventoryViewModel = std::make_unique<InventoryViewModel>();
}

WindowView::~WindowView()
{
	std::cout << "WindowView is destroyed!\n";
}

void WindowView::Run()
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
	{
		std::cout << "Failed to init glfw!\n";
		return;
	}

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(1230, 720, "My Workshop", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		std::cout << "Failed to create the window!\n";
		return;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	/* init glew */
	if (glewInit() != GLEW_OK)
	{
		std::cout << "Failed to init glew!\n";
		return;
	}

	/* init ImGui */
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	ImGui_ImplGlfwGL3_Init(window, true);

	// Setup style
	ImGui::StyleColorsClassic();

	bool show_demo_window = true;
	ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

	m_inventoryViewModel->UpdateInventory();
	auto shopTools = m_shopViewModel->getTools();
	auto jobs = m_displayJobsViewModel->GetJobs();

	ImGuiWindowFlags window_flags = 0;
	window_flags |= ImGuiWindowFlags_NoMove;
	window_flags |= ImGuiWindowFlags_NoResize;
	window_flags |= ImGuiWindowFlags_NoCollapse;

	std::string errorMsg;

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Poll for and process events */
		glfwPollEvents();

		ImGui_ImplGlfwGL3_NewFrame();

		// inventory window
		DisplayInventory(window_flags);

		// store window
		DisplayStore(window_flags, shopTools);

		// jobs window
		DisplayJobs(window_flags, jobs);

		// ShowDemoWindow
		if (show_demo_window)
		{
			ImGui::SetNextWindowPos(ImVec2(650, 20), ImGuiCond_FirstUseEver); // Normally user code doesn't need/want to call this because positions are saved in .ini file anyway. Here we just want to make the demo initial state a bit more friendly!
			ImGui::ShowDemoWindow(&show_demo_window);
		}

		/* Render here */
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		ImGui::Render();
		ImGui_ImplGlfwGL3_RenderDrawData(ImGui::GetDrawData());

		/* Swap front and back buffers */
		glfwSwapBuffers(window);
	}

	// Cleanup
	ImGui_ImplGlfwGL3_Shutdown();
	ImGui::DestroyContext();
	glfwTerminate();
}

void WindowView::ErrorPopup(const std::string& errMsg) noexcept
{
	ImGui::OpenPopup("Error!");
	if (ImGui::BeginPopupModal("Error!"))
	{
		ImGui::NewLine();
		ImGui::Text(errMsg.c_str());
		ImGui::NewLine();
		if (ImGui::Button("Close"))
		{
			ImGui::CloseCurrentPopup();
			m_displayErrorPopup = false;
		}
		ImGui::EndPopup();
	}
}

void WindowView::DisplayInventory(const ImGuiWindowFlags& window_flags) const noexcept
{
	ImGui::SetNextWindowSize(ImVec2(300, 180));
	ImGui::Begin("Inventory", NULL, window_flags);
	ImGui::SetWindowPos(ImVec2(10, 10)/*, ImGuiCond_FirstUseEver*/);

	// show money
	ImGui::Text("Money: $%d", m_inventoryViewModel->GetMoney());

	ImGui::NewLine();
	ImGui::Separator();

	// show tools
	for (auto t : m_inventoryViewModel->GetTools())
	{
		std::string toolStr = "Tool: " + t.first + ", Usage: x" + std::to_string(t.second);
		ImGui::Text(toolStr.c_str());
	}

	ImGui::End();
}

void WindowView::DisplayStore(const ImGuiWindowFlags& window_flags, const std::vector<std::shared_ptr<Tool>>& shopTools) const noexcept
{
	ImGui::SetNextWindowSize(ImVec2(300, 190));
	ImGui::Begin("Store", NULL, window_flags);
	ImGui::SetWindowPos(ImVec2(10, 200)/*, ImGuiCond_FirstUseEver*/);

	ImGui::NewLine();

	// show tools
	for (int i = 0; i < shopTools.size(); ++i)
	{
		auto label = "Buy##" + std::to_string(shopTools[i]->GetId());
		if (ImGui::Button(label.c_str()))
		{
			m_playerViewModel->buyTool(shopTools[i]->GetId());
			m_inventoryViewModel->UpdateInventory();
			break;
		}
		ImGui::SameLine();
		std::string toolStr = "Tool: " + shopTools[i]->GetName() + ", Price: " + std::to_string(shopTools[i]->GetPrice()) + '$';
		ImGui::Text(toolStr.c_str());
	}

	ImGui::End();
}

void WindowView::DisplayJobs(const ImGuiWindowFlags& window_flags, std::vector<std::shared_ptr<Job>> &jobs) noexcept
{
	ImGui::SetNextWindowSize(ImVec2(900, 380));
	ImGui::Begin("Jobs", NULL, window_flags);
	ImGui::SetWindowPos(ImVec2(320, 10)/*, ImGuiCond_FirstUseEver*/);

	ImGui::NewLine();

	// show tools
	for (int i = 0; i < jobs.size(); ++i)
	{
		auto label = "Complete##" + std::to_string(jobs[i]->GetId());
		if (ImGui::Button(label.c_str()))
		{
			if (m_acceptJobViewModel->AcceptJob(jobs[i]->GetId()))
			{
				m_inventoryViewModel->UpdateInventory();
				jobs = m_displayJobsViewModel->GetJobs();
				break;
			}
			else
			{
				m_errorMsg = m_acceptJobViewModel->GetStatusMsg();
				m_displayErrorPopup = true;
				break;
			}
		}
		ImGui::SameLine();

		auto str = "Reward: $" + std::to_string(jobs[i]->GetRewardAmount()) + ", Vehicle: " + jobs[i]->GetVehicleType() +
			", Malfunction: " + jobs[i]->GetMulfanctionName() + ", Tools: ";

		for (auto t : jobs[i]->GetToolsIdName())
		{
			str += t.second + " / ";
		}

		ImGui::Text(str.c_str());
	}

	if (m_displayErrorPopup)
	{
		ErrorPopup(m_errorMsg);
	}

	ImGui::End();
}
