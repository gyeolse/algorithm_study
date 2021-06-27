#include <bits/stdc++.h>
using namespace std;
int dp[1001];
char block[1001];
int n;

char findNext(char c) {
    if (c == 'B') {
        return 'O';
    }
    else if (c == 'O') {
        return 'J';
    }
    else {
        return 'B';
    }
}

int main() {
    cin >> n;

    for (int i = 1;i <= n;i++) {
        cin >> block[i];
    }

    for (int i = 1;i <= n;i++) {
        dp[i] = 987654321;
    }

    dp[1] = 0;

    for (int i = 1;i < n;i++) {
        char nextC = findNext(block[i]); //다음으로 올 것

        if (block[i] == 'B') {
            for (int j = i + 1;j <= n;j++) {
                if (block[j] == nextC) {
                    dp[j] = min(dp[j], (j - i) * (j - i) + dp[i]);
                }
            }
        }
        else if (block[i] == 'O') {
            for (int j = i + 1;j <= n;j++) {
                if (block[j] == nextC) {
                    dp[j] = min(dp[j], (j - i) * (j - i) + dp[i]);
                }
            }
        }
        else {
            for (int j = i + 1;j <= n;j++) {
                if (block[j] == nextC) {
                    dp[j] = min(dp[j], (j - i) * (j - i) + dp[i]);
                }
            }
        }
    }

    if (dp[n] == 987654321) {
        cout << -1 << "\n";
    }
    else {
        cout << dp[n] << "\n";
    }

    return 0;
}