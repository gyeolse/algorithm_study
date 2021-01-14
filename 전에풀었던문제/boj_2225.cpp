#include <iostream>
using namespace std;

const int MOD = 1000000000;
int n,k; //1~200
int dp[201][201];

int main(void){
    cin>>n>>k;

    dp[0][0] = 1LL;

    for(int i=1;i<=k;i++){
        for(int j=0;j<=n;j++){
            for(int l=0;l<=j;l++){
                dp[i][j] += dp[i-1][j-l];
                dp[i][j] %=MOD;
            }
        }
    }

    cout<<dp[k][n]%MOD<<"\n";

    return 0;
}