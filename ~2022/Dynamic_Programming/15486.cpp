#include <bits/stdc++.h>
#define MAX 1500001
using namespace std;

int T[MAX]; //걸리는 기각
int P[MAX]; //받는 금액 
int dp[MAX];
int N;

int main() {
    cin >> N;
    for (int i = 1;i <= N;i++) {
        cin >> T[i] >> P[i];
    }

    //해당 날짜까지 얻을 수 있는 최대 이익. 일을 한 후, 돈받는다

    for(int i=1;i<=N;i++) {
        
        dp[i + T[i]] = max(dp[i+T[i]], dp[i] + P[i]);
        dp[i+1] = max(dp[i+1], dp[i]);
    }

    cout<<dp[N+1]<<"\n";
    return 0;
}