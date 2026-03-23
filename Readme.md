Frequency Histogram Clac 📊  
频数直方图生成器

This is only a practice at first , but I hard work and let it become a full workflow

A cross-platform C++ tool that generates ASCII histograms from integer data. Input your numbers, specify a bin width, and get a visual frequency distribution — all in the terminal!  
一个跨平台的 C++ 工具，可从整数数据生成 ASCII 直方图。输入你的数据，指定分组宽度，即可在终端中获得直观的频次分布图！

✨ Features / 功能特点

Interactive input: Type or paste your data directly  
  交互式输入：直接键入或粘贴你的数据
Automatic binning: Group numbers into intervals of specified width  
  自动分组：将数字按指定宽度分组
ASCII visualization: See your data as a text-based histogram  
  ASCII 可视化：以文本形式展示数据直方图
Cross-platform: Works on Linux, macOS, and Windows  
  跨平台支持：兼容 Linux、macOS 和 Windows
One-command build: No dependencies beyond a standard C++ compiler  
  一键编译：仅需标准 C++ 编译器，无额外依赖

🚀 Quick Start / 快速开始

编译程序
g++ -std=c++17 -O2 -o histogram runner.cpp

运行程序
./histogram

输入数据
输入整数（可用空格或换行分隔）
最后一个数字是分组宽度（bin width）
输入完成后，单独按一次回车（空行） 表示结束

示例输入：
55 66 44 56 23 79 21 46 89 43
11 56 32 45 87 96 24 78 42 67
32 45 6 7 12 34 45 43 53
10
<-- 在此处按回车（空行）

查看直方图输出

0123456789

每个 * 代表该区间内的一个数据点。  
底部数字为分组编号（对 10 取模，避免错位）。

📁 Project Structure / 项目结构

histogram/
├── runner.cpp        # 主程序入口（处理输入输出）
├── main.hpp          # 核心逻辑（miyabi() 函数）
├── .github/
│   └── workflows/
│       └── main.yml  # 自动发布工作流
└── README.md

程序内部通过 ./assets/input.in 和 ./assets/output.out 处理数据。

🛠️ How It Works / 工作原理

读取输入：持续读取整数，直到遇到空行  
提取参数：最后一个数作为分组宽度（groupDiffLength）  
分组统计：
   计算数据最小值和最大值
   按指定宽度划分区间（bins）
   统计每个区间的频次
渲染输出：用 * 字符绘制垂直直方图

分组公式：  
对于数值 x，其所在分组索引 = (x - min) / groupDiffLength

📦 Pre-built Binaries / 预编译版本

官方为所有平台提供预编译二进制文件：
平台   文件名
Linux      histogram-ubuntu-latest.tar.gz

macOS      histogram-macos-latest.tar.gz

Windows    histogram-windows.zip

👉 下载最新版本  (请将 your-username 替换为实际仓库所有者)

🔧 Building from Source / 从源码构建

环境要求
支持 C++17 的编译器（如 g++、clang++ 或 MinGW）
标准库（无需第三方依赖）

编译命令
Linux / macOS
g++ -std=c++17 -O2 -o histogram runner.cpp

Windows (MinGW)
g++ -std=c++17 -O2 -o histogram.exe runner.cpp

运行
Linux / macOS
./histogram

Windows
histogram.exe

🤝 Contributing / 贡献代码

Fork 本仓库  
创建特性分支（git checkout -b feature/AmazingFeature）  
提交更改（git commit -m 'Add some amazing feature'）  
推送分支（git push origin feature/AmazingFeature）  
发起 Pull Request

📜 License / 开源许可

本项目基于 MIT 许可证发布。详情请参阅 LICENSE 文件。

💡 Tips & Tricks / 使用技巧

较小的分组宽度 → 直方图更精细（但可能出现空组）  
较大的分组宽度 → 趋势更平滑（但可能掩盖细节）  
数据顺序不影响结果，仅数值和分组宽度决定输出  

示例：数据 [1,2,3,10,11,12]，分组宽度 5：  
分组 [1–5] → 3 个点，[6–10] → 1 个点，[11–15] → 2 个点

###### Made by OpenLight Studio with ♥️
