#include <bits/stdc++.h>
using namespace std;
int w[21];
int k[21];
int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);
    for (int i = 0;i < 10;i++) {
        cin >> w[i];
    }
    for (int i = 0;i < 10;i++) {
        cin >> k[i];
    }
    sort(w, w + 10, greater<>());
    sort(k, k + 10, greater<>());
    int w_res = 0, k_res = 0;
    for (int i = 0;i < 3;i++) {
        w_res += w[i];
        k_res += k[i];
    }
    cout << w_res << " " << k_res << "\n";
    return 0;
}