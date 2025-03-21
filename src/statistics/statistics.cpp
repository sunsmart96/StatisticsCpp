import statistics;  // 导入模块  


#include <fmt/core.h>
#include <xlnt/xlnt.hpp>
#include <xlnt/xlnt.hpp>  
#include <iostream> 

#include <GLFW/glfw3.h>  
#include "imgui.h"  
#include "imgui_impl_glfw.h"  
#include "imgui_impl_opengl3.h"  

void hello() {

    // ANSI 转义序列  
    constexpr const char* RED = "\033[31m";
    constexpr const char* GREEN = "\033[32m";
    constexpr const char* YELLOW = "\033[33m";
    constexpr const char* BLUE = "\033[34m";
    constexpr const char* RESET = "\033[0m";  // 重置颜色  

    fmt::print("{}Hello, {}!\n", RED, "World");
    fmt::print("{}This is a green message.\n", GREEN);
    fmt::print("{}This is a yellow message.\n", YELLOW);
    fmt::print("{}This is a blue message.\n", BLUE);
    fmt::print("{}This is a message with no color.\n", RESET);
}

void read_excel_demo()
{
    // 创建一个工作簿对象  
    xlnt::workbook wb;

    // 加载 Excel 文件  
    wb.load("../data/08 - Vision.xlsx");

    // 获取第一个工作表  
    auto ws = wb.active_sheet();

    // 遍历工作表中的所有单元格  
    for (auto row : ws.rows()) {
        for (auto cell : row) {
            std::cout << cell.to_string() << "\t"; // 输出单元格内容  
        }
        std::cout << std::endl; // 换行  
    }

}


void show_imgui()
{
    // 初始化 GLFW  
    if (!glfwInit()) return ;

    // 创建窗口  
    GLFWwindow* window = glfwCreateWindow(1280, 720, "ImGui + GLFW Example", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return ;
    }
    glfwMakeContextCurrent(window);

    // 设置 ImGui  
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 130");

    // 主循环  
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        // 开始 ImGui 帧  
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // ImGui 界面  
        ImGui::Begin("Hello, ImGui!");
        ImGui::Text("This is an example.");
        ImGui::End();

        // 渲染  
        ImGui::Render();
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        glfwSwapBuffers(window);
    }

    // 清理  
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwDestroyWindow(window);
    glfwTerminate();
}