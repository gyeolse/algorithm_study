#include <bits/stdc++.h>
using namespace std;
int n;
int dp[20];

int main() {
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for (int i = 4;i <= 15;i++) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    cin >> n;
    for (int i = 0;i < n;i++) {
        int a; cin >> a;
        cout << dp[a] << "\n";
    }

    return 0;
}