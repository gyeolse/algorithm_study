#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n; //수열의 길이

// ****** 앞에서 LIS 뒤에서부터 LIS 해서 더한 후 -1 (중복된 것) 해주어야 함.
// 앞에서 LIS, 뒤에서 LIS임
// 그러므로, 각각 반대편에서 LIS를 해주므로, 해당 idx에서의 바이토닉 수열 구하기가 가능함.
// 이때 앞에서 LIS는 해당 idx까지고, 뒤에서 LIS는 그때서부터임 그러므로,
// 해당 idx의 중복이 한 번 있으므로 무조건 -1을 해주는 것. 하다보니 이해감

int main(void){
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    vector<int> dp1(n);
    vector<int> dp2(n);

    //증가수열
    for(int i=0;i<n;i++){
        dp1[i] = 1;
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i] && dp1[i]<dp1[j]+1){
                dp1[i]=dp1[j] + 1;
            }
        }
    }
    
    //반대에서 돌리니까 이것도 조건문이 같아
    //인덱스 다루는 것 조심해주고, 나중에 또 보게 되면 왜 이렇게 되는지 생각해내는게 포인트
    for(int i=n-1;i>=0;i--){
        dp2[i] = 1;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[i] && dp2[i]<dp2[j]+1){
                dp2[i] = dp2[j] + 1;
            }
        }
    }

    int answer = 0;
    for(int i=0;i<n;i++){
        if(answer<dp1[i]+dp2[i]-1){
            answer=dp1[i]+dp2[i]-1;
        }
    }

    cout<<answer<<'\n';

    return 0;
}