#include <bits/stdc++.h>
using namespace std;
int cnt;
vector<int> arr;
int n;
int m;

// ForwardIt lower_bound(ForwardIt first, ForwardIt last, const T& value);
// upper bound, lower bound 활용

// lower_bound : 이진탐색 기반 탐색. 찾으려는 key 값보다 같거나 큰 숫자가, 배열 몇 번째에서 등장하는지.
// upper_bound : 이진탐색 기반 탐색. key 값을 초과하는 가장 첫 번쨰 원소의 위치 
// 1. 특정 범위에 속하는 숫자가 몇 개인지 알고 싶을 때
// 2. 특정한 숫자가 몇 번 나오는지 알고 싶을 때

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++){
        int x; cin>>x; arr.push_back(x);
    }    
    sort(arr.begin(),arr.end());

    cin>>m;
    for(int i=0;i<m;i++) {
        int x; cin>>x;
        //iterator가 반환됨
        vector<int>::iterator l_ = lower_bound(arr.begin(),arr.end(),x);
        vector<int>::iterator u_ = upper_bound(arr.begin(),arr.end(),x);
        int res = l_ - u_;
        cout<<abs(res)<<" ";
    }

    return 0;
}