#include <bits/stdc++.h>
using namespace std;
int t;
int main() {
    cin >> t;
    for (int i = 0;i < t;i++) {
        int n; cin >> n;

        int div; int rem;
        vector<int> res;
        for (int cur = n; cur >= 1; cur /= 2) {
            res.push_back(cur % 2);
        }
        for (int cur = 0; cur < res.size();cur++) {
            if (res[cur] == 1) cout << cur << " ";
        }

    }
    return 0;
}