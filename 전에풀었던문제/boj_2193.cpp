#include <iostream>

using namespace std;

long long dp[91][2]; //n, [0,1]

//자료형때문에 틀림 int 가 애매할 때 long long 
//항상 최대 범위일때 생각을 해주자.
//1. 귀납법.
//2. 초기화 조건. 처음에 0이면 안된다. 1은 1 
int main(void){
    int n;
    cin>>n;

    dp[1][0] = 0;
    dp[1][1] = 1;

    for(int i=2;i<=n;i++){
        dp[i][0] += dp[i-1][0] + dp[i-1][1];
        dp[i][1] += dp[i-1][0];
    }

    cout<<dp[n][0]+dp[n][1]<<'\n';    
    return 0;
}