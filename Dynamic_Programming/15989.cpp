#include <bits/stdc++.h>
using namespace std;
int n;
int dp[10001][3];

int main() {

    dp[0][0] = 1;

    for (int i = 1;i <= 10001;i++) {

        dp[i][0] = dp[i - 1][0];
        if (i > 1) {
            dp[i][1] = dp[i - 2][1] + dp[i - 2][0];
        }
        if (i > 2) {
            dp[i][2] = dp[i - 3][0] + dp[i - 3][1] + dp[i - 3][2];
        }

    }

    cin >> n;
    for (int i = 0;i < n;i++) {
        int a; cin >> a;
        cout << (dp[a][0] + dp[a][1] + dp[a][2]) << "\n";
    }

    return 0;
}