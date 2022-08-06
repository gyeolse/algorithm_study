#include <bits/stdc++.h>
using namespace std;

int dp[10001];

int main() {
    int n, k; cin >> n >> k;
    vector<int> v(n + 1);

    for (int i = 1;i <= n;i++) cin >> v[i];

    dp[0] = 1;

    // 동전의 종류마다 k 번까지 최대 경우의 수 갱신
    for (int i = 1;i <= n;i++) {
        for (int j = v[i];j <= k;j++) {
            dp[j] += dp[j - v[i]];
        }
    }

    cout << dp[k];
    return 0;
}