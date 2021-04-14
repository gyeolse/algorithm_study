#include <bits/stdc++.h>
using namespace std;

int n;
int board[110][110];
long long dp[110][110];
int res = 0;

int main() {
    cin >> n;

    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            cin >> board[i][j];
        }
    }

    dp[0][0] = 1;

    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            // 예외 경우
            if ((i == n - 1 && j == n - 1) || dp[i][j] == 0) continue;

            //nextX, nextY, value 
            int value = board[i][j];
            int nextX = i + value;
            int nextY = j + value;

            if (nextX < n) dp[nextX][j] += dp[i][j];
            if (nextY < n) dp[i][nextY] += dp[i][j];

        }
    }

    cout << dp[n - 1][n - 1] << "\n";
    return 0;
}