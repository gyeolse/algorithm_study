//11726�� 2*N Ÿ�ϸ�

/* DP ���� Ǯ�� ���
    #1. ��ȭ�� �����
    #2. ���� -> ���� ����
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