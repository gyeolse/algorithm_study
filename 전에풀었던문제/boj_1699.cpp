#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int dp[100001];

//��ü ũ�� N���� �� ���� �� �� �ִ� ���� ū ������ a�� ����
//�� �� ���� dp[N] = dp[N-a] + 1
//�������� ��� ���Ұ��ΰ�

int main(void){
    cin>>n;
    for(int i=1;i<=n;i++){
        dp[i] = i; 
        for(int j=1;j*j<=i;j++){ //���ʴ�� �������� ã�ư��� ����
            if(dp[i]>dp[i-j*j]+1){
                dp[i] = dp[i-j*j]+1;
            }
        }
    }

    cout<<dp[n]<<"\n";
    return 0;
}