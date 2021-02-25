#include <bits/stdc++.h>
using namespace std;

int arr[1001];
int dp[1001];
int pastIdx[1001];

int main() {
    int n;
    cin >> n;
    for (int i = 0;i < n;i++) {
        cin >> arr[i];
    }

    fill_n(dp, n, 1);
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            if (arr[i] > arr[j]) {
                if (dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    pastIdx[i] = j;
                }
            }
        }
    }

    cout << *max_element(dp, dp + n) << "\n";

    return 0;
}