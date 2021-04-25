#include "WindowView.h"

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
	//ImGui::StyleColorsDark();
	ImGui::StyleColorsClassic();

	bool show_demo_window = true;
	bool show_another_window = false;
	ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

	auto inventoryViewModel = std::make_unique<InventoryViewModel>();
	inventoryViewModel->UpdateInventory();

	auto shopViewModel = std::make_unique<ShopViewModel>();
	auto shopTools = shopViewModel->getTools();

	auto playerViewModel = std::make_unique<PlayerViewModel>();

	auto displayJobsViewModel = std::make_unique<DisplayJobsViewModel>();
	auto jobs = displayJobsViewModel->GetJobs();

	auto acceptJobViewModel = std::make_unique<AcceptJobViewModel>();

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Poll for and process events */
		glfwPollEvents();

		ImGui_ImplGlfwGL3_NewFrame();

		ImGuiWindowFlags window_flags = 0;
		window_flags |= ImGuiWindowFlags_NoMove;
		window_flags |= ImGuiWindowFlags_NoResize;
		window_flags |= ImGuiWindowFlags_NoCollapse;

		// inventory window
		{
			ImGui::SetNextWindowSize(ImVec2(300, 180));
			ImGui::Begin("Inventory", NULL, window_flags);
			ImGui::SetWindowPos(ImVec2(10, 10)/*, ImGuiCond_FirstUseEver*/);

			// show money
			ImGui::Text("Money: $%d", inventoryViewModel->GetMoney());

			ImGui::NewLine();

			// show tools
			for (auto t : inventoryViewModel->GetTools())
			{
				std::string toolStr = "Tool: " + t.first + ", Usage: x" + std::to_string(t.second);
				ImGui::Text(toolStr.c_str());
			}

			ImGui::End();
		}

		// store window
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
					playerViewModel->buyTool(shopTools[i]->GetId());
					inventoryViewModel->UpdateInventory();
					break;
				}
				ImGui::SameLine();
				std::string toolStr = "Tool: " + shopTools[i]->GetName() + ", Price: " + std::to_string(shopTools[i]->GetPrice()) + '$';
				ImGui::Text(toolStr.c_str());
			}

			ImGui::End();
		}

		// jobs window
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
					acceptJobViewModel->AcceptJob(jobs[i]->GetId());

					inventoryViewModel->UpdateInventory();
					jobs = displayJobsViewModel->GetJobs();
					break;
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

			ImGui::End();
		}

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
