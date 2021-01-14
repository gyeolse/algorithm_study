#include <iostream>
#include <algorithm>

using namespace std;
/*
    1. ��ȭ�� ���̰� i�̰�, �ڿ� �ִ� ���ڰ� j�� ��� ���� ����
    dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1];
    2. ���� -> ū
*/

const long long MOD = 1000000000;
int dp[101][10]; //�迭 idx ���� ���� �����ֱ�

int main(void){
    int n;
    cin>>n;

    //���̰� 1�̰� �ڿ� ���ڰ� i�� �ֵ��� ������ 1�� ��
    for(int i=1;i<=9;i++){
        dp[1][i] = 1;
    }

    //1�� �ֵ� ó���� ���־����� 2���� �����ϰ� �ȴ�
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