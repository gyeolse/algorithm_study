#include <iostream>

using namespace std;

const long long MOD = 10007;
long long dp[1001][10];

int main(void){
    int n;
    cin>>n;

//��ȭ�� : dp[i][j] = dp[i-1][k] ( 0<= j)
    //���̰� 1�̰� �ڿ� ���ڰ� i�� �ֵ��� ������ 1�� ��. 0���� ���۹Ƿ� 0
    for(int i=0;i<=9;i++){
        dp[1][i] = 1;
    }

    //1�� �ֵ� ó���� ���־����� 2���� �����ϰ� �ȴ�
    for(int i=2;i<=n;i++){
        for(int j=0;j<=9;j++){
            for(int k=0;k<=j;k++){
                dp[i][j] += dp[i-1][k]; //���������� ���������.....
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