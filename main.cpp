#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<int> a;
    int x;
    while (cin >> x)
        a.push_back(x);
    if (a.empty()) return 0;
    int groupDiffLength;
    cin >> groupDiffLength;
    int minn = *min_element(a.begin(), a.end());
    int maxn = *max_element(a.begin(), a.end());
    int range = maxn - minn;
    int groupCnt = (range + groupDiffLength - 1) / groupDiffLength;
    if (groupCnt == 0) groupCnt = 1;
    vector<int> freq(groupCnt, 0);
    for (int x : a) {
        int idx = (x - minn) / groupDiffLength;
        if (idx >= groupCnt) idx = groupCnt - 1;
        freq[idx]++;
    }
    int maxHeight = *max_element(freq.begin(), freq.end());
    for (int h = maxHeight; h >= 1; h--) {
        for (int i = 0; i < groupCnt; i++) {
            if (freq[i] >= h)
                cout << '*';
            else
                cout << ' ';
        }
        cout << '\n';
    }
    for (int i = 0; i < groupCnt; i++) cout << '-';
    cout << '\n';
    for (int i = 0; i < groupCnt; i++)
        cout << (i % 10);
    cout << endl;
    return 0;
}
