#include <bits/stdc++.h>
using namespace std;
#define MAX 120000 
int arr[MAX];
int n, k;

int main() {
    cin >> n >> k;

    queue<int> que;

    memset(arr, -1, sizeof(arr));
    //현재 수빈 위치에서 시작 
    que.push(n);
    arr[n] = 0;

    while (!que.empty()) {
        int cur = que.front(); que.pop();

        if(cur == k) break;
        // 먼저 도착했다 -> 더 시간이 짧다.
        // cout << cur << " ";
        //cur-1
        if (arr[cur - 1] == -1) {
            if (cur - 1 >= 0 && cur -1 < MAX) {
                arr[cur - 1] = arr[cur] + 1;
                que.push(cur - 1);
            }
        }

        //cur+1
        if (arr[cur + 1] == -1) {
            if (cur+1 >= 0 && cur + 1 <= MAX) {
                arr[cur + 1] = arr[cur] + 1;
                que.push(cur + 1);
            }
        }

        //cur*2
        if (arr[cur * 2] == -1) {
            if (cur*2 >= 0 && cur * 2 <= MAX) {
                arr[cur * 2] = arr[cur] + 1;
                que.push(cur * 2);
            }
        }
    }


    // for(int i =0;i<20;i++) {
    //     cout<<arr[i]<<" ";        
    // }

    cout<<arr[k]<<endl;

    return 0;
}