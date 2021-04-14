#include <bits/stdc++.h>
#define MAX 1000001

using namespace std;

int n;
int dp[MAX];

int main() {
    cin >> n;

    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3;i <= n;i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
    }

    cout << dp[n] % 15746 << "\n";
    return 0;
}