//runner.cpp

#include "main.hpp"

int main() {
    vector<string> lines;
    string line;
    cout << "请输入整数数据（每行可多个，空格分隔）\n";
    cout << "输入完成后，请单独输入一个空行（直接按回车）:\n";
    cout << "----------------------------------------\n";
    while (getline(cin, line)) {
        // 检查是否为空行（去除前后空格后为空）
        string trimmed = line;
        // 去除前导空格
        size_t start = trimmed.find_first_not_of(" \t");
        if (start == string::npos) {
            // 整行为空或只有空白 → 输入结束
            break;
        }
        // 去除尾随空格（可选，不影响整数读取）
        size_t end = trimmed.find_last_not_of(" \t");
        trimmed = trimmed.substr(start, end - start + 1);
        lines.push_back(trimmed);
    }
    if (lines.empty()) {
        cerr << "错误：未输入任何有效数据。\n";
        return 1;
    }
    // 写入 ./assets/input.in
    ofstream infile("./assets/input.in");
    if (!infile.is_open()) {
        cerr << "错误：无法写入 ./assets/input.in\n";
        return 1;
    }
    for (const auto& l : lines) {
        infile << l << '\n';
    }
    infile.close();

    // 调用 histogram 程序
    cout << "\n🔄 正在生成直方图...\n";
    miyabi();
    ifstream outfile("./assets/output.out");
    if (!outfile.is_open()) {
        cerr << "错误：无法读取 ./assets/output.out\n";
        return 1;
    }
    cout << "\n📊 直方图结果：\n";
    cout << "========================================\n";
    string out_line;
    while (getline(outfile, out_line)) {
        cout << out_line << '\n';
    }
    cout << "========================================\n";

    return 0;
}
