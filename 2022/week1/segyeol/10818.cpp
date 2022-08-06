#include <bits/stdc++.h>
using namespace std;
vector<int> res;
int n;
int main() {
    cin >> n;
    for (int i = 0;i < n;i++) {
        int tmp; cin >> tmp;
        res.push_back(tmp);
    }
    sort(res.begin(), res.end());
    cout << res[0] << " " << res[res.size() - 1] << "\n";
}