#include <bits/stdc++.h>
using namespace std;

int n;
int arr[1001];
int dp[1001];

int main() {
    cin >> n;
    for (int i = 0;i < n;i++) {
        cin >> arr[i];
    }

    fill_n(dp, n, 1);

    for (int i = 0;i < n;i++) {
        for (int j = 0;j < i;j++) {
            if (arr[i] < arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    cout << *max_element(dp, dp + n) << "\n";
    return 0;

}