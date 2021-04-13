#include <bits/stdc++.h>
using namespace std;
int n, k;
int arr[101];
int dp[100001];

int main() {
    cin >> n >> k;
    for (int i = 0;i < n;i++) {
        cin >> arr[i];
    }

    //1. k 범위 내에 모든 인덱스 10001로 초기화
    for (int i = 1;i <= k;i++) {
        dp[i] = 10001;
    }

    //2. 1, 5, 12에 해당하는 부분은 1로 설정 
    for (int i = 0;i < n;i++) {
        dp[arr[i]] = 1;
    }

    //3. i번째 동전에 도달할 수 있는 최소값... n번째일때 최소값
    for (int i = 1;i <= k;i++) {
        for (int j = 0;j < n;j++) {
            dp[i + arr[j]] = min(dp[i] + 1, dp[i + arr[j]]);
        }
    }
    if(dp[k] == 10001) {
        cout<<-1<<"\n";
    }
    else {
        cout<<dp[k]<<"\n";
    }

    return 0;
}