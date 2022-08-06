#include <bits/stdc++.h>
using namespace std;
int a, b;
vector<int> vec;

int main() {
    cin >> a >> b;

    for (int i = 1;i <= 1000; i++) {
        int cnt = i;
        for (int j = cnt; j > 0; j--) {
            vec.push_back(i);
        }
    }

    int ans = 0;

    for (int i = a - 1; i < b; i++) {
        ans += vec[i];
        // cout << vec[i] << " ";
    }
    cout << ans << "\n";
    return 0;
}