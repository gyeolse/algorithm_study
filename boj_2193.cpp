#include <iostream>

using namespace std;

long long dp[91][2]; //n, [0,1]

//�ڷ��������� Ʋ�� int �� �ָ��� �� long long 
//�׻� �ִ� �����϶� ������ ������.
//1. �ͳ���.
//2. �ʱ�ȭ ����. ó���� 0�̸� �ȵȴ�. 1�� 1 
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