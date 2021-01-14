#include <iostream>

using namespace std;

int n;
int arr[1001];
int dp[1001];

int main(void){
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    for(int i=0;i<n;i++){
        dp[i] = arr[i];
        for(int j=0;j<i;j++){
             if(dp[i]<arr[i]+dp[j] && arr[j]<arr[i]){
                 dp[i] = arr[i] + dp[j];
             }
        }
    }

    int answer=0;

    for(int i=0;i<n;i++){
        if(answer<dp[i]) answer=dp[i];
    }
    cout<<answer<<"\n";
    return 0;
}