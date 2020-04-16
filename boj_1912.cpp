#include <iostream>
using namespace std;
int n;
int arr[100001];
int dp[100001];

//연속합 : i번째 수로 끝나는 가장 큰 연속합

int main(void){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    for(int i=0;i<n;i++){
    //dp[i] < dp[i-1] + arr[i]
    //dp[i] > dp[i-1] + arr[i] 면 새로 시작
    
    dp[i] = arr[i];
    if(dp[i] < dp[i-1]+ arr[i]){
        dp[i] = dp[i-1] + arr[i];
        }
    }
    int answer = dp[0];
    //제일 처음으로 세팅 해주어야함

    for(int i=0;i<n;i++){
        if(answer<dp[i]) answer = dp[i];    
    }
    cout<<answer<<"\n";
    return 0;

}