#include <iostream>
using namespace std;
int n;
int arr[100001];
int dp[100001];

//������ : i��° ���� ������ ���� ū ������

int main(void){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    for(int i=0;i<n;i++){
    //dp[i] < dp[i-1] + arr[i]
    //dp[i] > dp[i-1] + arr[i] �� ���� ����
    
    dp[i] = arr[i];
    if(dp[i] < dp[i-1]+ arr[i]){
        dp[i] = dp[i-1] + arr[i];
        }
    }
    int answer = dp[0];
    //���� ó������ ���� ���־����

    for(int i=0;i<n;i++){
        if(answer<dp[i]) answer = dp[i];    
    }
    cout<<answer<<"\n";
    return 0;

}