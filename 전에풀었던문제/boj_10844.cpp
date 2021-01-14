#include <iostream>
#include <algorithm>

using namespace std;
/*
    1. 점화식 길이가 i이고, 뒤에 있는 숫자가 j인 계단 수의 개수
    dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1];
    2. 작은 -> 큰
*/

const long long MOD = 1000000000;
int dp[101][10]; //배열 idx 범위 지정 잘해주기

int main(void){
    int n;
    cin>>n;

    //길이가 1이고 뒤에 숫자가 i인 애들은 무조건 1이 됨
    for(int i=1;i<=9;i++){
        dp[1][i] = 1;
    }

    //1인 애들 처리를 해주었으니 2부터 시작하게 된다
    for(int i=2;i<=n;i++){
        for(int j=0;j<=9;j++){
            dp[i][j] =0;
            if(j-1>=0) dp[i][j] += dp[i-1][j-1]; 
            if(j+1<=9) dp[i][j] += dp[i-1][j+1];
            dp[i][j] %= MOD;
        }
    }
    
    long long ans=0;
    
    for(int i=0;i<=9;i++) ans +=dp[n][i];
    ans %=MOD;
    cout<<ans<<"\n";

    return 0;
}