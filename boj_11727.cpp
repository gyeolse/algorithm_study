//11726번 2*N 타일링

/* DP 문제 풀이 방법
    #1. 점화식 세우기
    #2. 문제 -> 작은 문제
*/

#include <iostream>
using namespace std;

int n;
int dp[1000];

int main(void){
    dp[0] = 1;
    dp[1] = 1;

    cin>>n;
    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1]+dp[i-2]+dp[i-2];
        dp[i] %= 10007;
    }
      cout<<dp[n]<<"\n";
      return 0;
}