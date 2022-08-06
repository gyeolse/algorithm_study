/**
 * 1. 돈을 인출하는데 필요한 시간의 합의 **최솟값**  => 그리디
 * 1 2 3 4 5 => 1 + 3 + 6 + 10 + 15 = 35
 * 5 4 3 2 1 => 5 + 9 + 12 + 14 + 15 
 * 
 * 2. 구현 : 오름차순 정렬 후, 차례대로 걸리는 시간을 구해줌
*/

#include <bits/stdc++.h>
using namespace std;
int n;
int arr[1001]; //각 사람이 인출하는데 걸리는 시간

int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);

    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int waitTime = 0;
    int totalTime = 0;

    for(int i=0;i<n;i++) {
        int curTime = waitTime + arr[i];
        totalTime = totalTime + curTime;
        waitTime += arr[i];
    }

    cout<<totalTime<<"\n";
    return 0;
}