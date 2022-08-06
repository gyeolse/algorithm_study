#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> res;

int main() {
    cin >> n >> k;

    for (int i = 1;i <= n;i++) {
        if ((n % i) == 0) res.push_back(i);
    }

    if (res.size() < k) {
        cout << 0 << "\n";
    }
    else {
        cout << res[k - 1] << "\n";
    }
    return 0;
}