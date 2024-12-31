import statistics;  // 导入模块  

#include <fmt/core.h>
#include <xlnt/xlnt.hpp>

// ANSI 转义序列  
constexpr const char* RED = "\033[31m";
constexpr const char* GREEN = "\033[32m";
constexpr const char* YELLOW = "\033[33m";
constexpr const char* BLUE = "\033[34m";
constexpr const char* RESET = "\033[0m";  // 重置颜色  

void hello() {
    fmt::print("{}Hello, {}!\n", RED, "World");
    fmt::print("{}This is a green message.\n", GREEN);
    fmt::print("{}This is a yellow message.\n", YELLOW);
    fmt::print("{}This is a blue message.\n", BLUE);
    fmt::print("{}This is a message with no color.\n", RESET);

    xlnt::workbook wb;
    xlnt::worksheet ws = wb.active_sheet();
    ws.cell("A1").value(5);
    ws.cell("B2").value("string data");
    ws.cell("C3").formula("=RAND()");
    ws.merge_cells("C3:C4");
    ws.freeze_panes("B2");
    wb.save("example.xlsx");
}