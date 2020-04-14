//11053. LIS

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void){
    int n;
    cin>>n;
    
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    vector<int> dp(n);
    //조건 d[i] = max(d[j]+1)
    //조건1. 
    //조건2. 

    for(int i=0;i<n;i++){
        dp[i] = 1;
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i] && dp[i]<dp[j]+1){
                dp[i] =dp[j]+1;
            }
        }
    }

    cout<<*max_element(dp.begin(),dp.end())<<"\n";

    return 0;
}