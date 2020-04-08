#include <iostream>

using namespace std;

const long long MOD = 10007;
long long dp[1001][10];

int main(void){
    int n;
    cin>>n;

//점화식 : dp[i][j] = dp[i-1][k] ( 0<= j)
    //길이가 1이고 뒤에 숫자가 i인 애들은 무조건 1이 됨. 0부터 시작므로 0
    for(int i=0;i<=9;i++){
        dp[1][i] = 1;
    }

    //1인 애들 처리를 해주었으니 2부터 시작하게 된다
    for(int i=2;i<=n;i++){
        for(int j=0;j<=9;j++){
            for(int k=0;k<=j;k++){
                dp[i][j] += dp[i-1][k]; //제에에에발 더해줘야지.....
                dp[i][j] %=MOD;
            }
        }
    }
    long long ans=0;
    
    for(int i=0;i<10;i++) ans +=dp[n][i];
    ans %=MOD;
    cout<<ans<<"\n";

    return 0;
}