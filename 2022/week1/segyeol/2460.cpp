#include <bits/stdc++.h>
using namespace std;
vector<int> res;
int lastValue = 0;
int main() {
    for (int i = 0;i < 10;i++) {
        int a, b; cin >> a >> b;
        lastValue = (lastValue - a + b);
        res.push_back(lastValue);
    }
    sort(res.begin(), res.end());
    cout << res[res.size() - 1] << "\n";
    return 0;
}