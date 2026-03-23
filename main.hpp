// main.hpp
#include <bits/stdc++.h>
using namespace std;

void miyabi() {
    // ✅ 不再使用 freopen，直接操作文件
    ifstream infile("./assets/input.in");
    ofstream outfile("./assets/output.out");
    if (!infile.is_open()) {
        outfile << "错误：无法读取 input.in";
        outfile.close();
        return;
    }
    vector<int> a;
    int x;
    while (infile >> x)
        a.push_back(x);
    infile.close();
    if (a.size() < 2) {
        outfile << "数据不够！至少需要 1 个数据 + 1 个分组长度！";
        outfile.close();
        return;
    }
    // 最后一个数是 groupDiffLength
    int groupDiffLength = a.back();
    a.pop_back();
    if (groupDiffLength <= 0) {
        outfile << "步长过小！";
        outfile.close();
        return;
    }
    int minn = *min_element(a.begin(), a.end());
    int maxn = *max_element(a.begin(), a.end());
    int range = maxn - minn;
    int groupCnt = (range + groupDiffLength - 1) / groupDiffLength;
    if (groupCnt == 0) groupCnt = 1;
    vector<int> freq(groupCnt, 0);
    for (int val : a) {
        int idx = (val - minn) / groupDiffLength;
        if (idx >= groupCnt) idx = groupCnt - 1;
        freq[idx]++;
    }
    int maxHeight = *max_element(freq.begin(), freq.end());
    // 输出直方图到 outfile
    for (int h = maxHeight; h >= 1; h--) {
        for (int i = 0; i < groupCnt; i++)
            outfile << (freq[i] >= h ? '*' : ' ');
        outfile << '\n';
    }
    for (int i = 0; i < groupCnt; i++) outfile << '-';
    outfile << '\n';
    for (int i = 0; i < groupCnt; i++) outfile << (i % 10);
    outfile << endl;
    outfile.close();
}
