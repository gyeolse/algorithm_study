#include <bits/stdc++.h>
using namespace std;

long long n,m;
vector<long long> arr; 

//가져갈 수 있는 높이의 최댓값 => 파라메트릭 서치 
// 높이  -> long long
// 길이 M -> long long 

int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);
    cin>>n>>m; //나무의 수, 가져가려는 나무의 길이 
    for (long long i=0;i<n;i++) {
        long long x; cin>>x; arr.push_back(x);
    }

    long long start = 0;
    long long end = *max_element(arr.begin(),arr.end());

    long long res = 0;

    while(start<=end) {
        
        long long mid = (start+end) / 2;
        long long curCount = 0;

        for(int i=0;i<n;i++) {
            if(arr[i] > mid) {
                curCount += (arr[i] - mid);
            }
        }

        //1. 나무의 길이가 짧은 경우 -> 왼쪽으로 이동
        if(curCount < m) {
            end = mid - 1;
        }
        //2. 나무의 길이가 길거나 같은 경우 -> 오른족으로 이동 (Save)
        else {
            res = mid;
            start = mid + 1;
        }
    }

    cout<<res<<"\n";
    return 0;
}