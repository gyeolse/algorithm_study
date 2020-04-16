#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[1001]; //input array
int vec[1001]; //그 전의 idx가 어딘지 저장하는 배열
int dp[1001]; //귀납법 : i번째 가장 긴 증가 부분수열의 길이를 보관

int n;

void go_14002(int num){
    if(vec[num]==-1){
        cout<<arr[num]<<" ";
        return;
    }

    int next = vec[num];
    go_14002(next);
    cout<<arr[num]<<" ";

}

int main(void){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    for(int i=0;i<n;i++){
        dp[i] = 1; //
        vec[i] = -1; //방문X
        for(int j=0;j<i;j++){
            if(dp[i]<dp[j]+1 && arr[j]<arr[i]){
                dp[i] = dp[j] + 1;
                vec[i] = j;
            }
        }
    }

    //제일 길었을때 dp 배열의 idx
    int answer=0;
    int idx;
    for(int i=0;i<n;i++){
        if(answer<dp[i]){
            answer=dp[i];
            idx = i;
        }
    }

    cout<<answer<<'\n';

    //재귀로 보내기
    go_14002(idx);

    return 0;
}