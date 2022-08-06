#include <bits/stdc++.h>
using namespace std;

int n,c; //n개의 집, c개의 공유기 
vector<int> arr;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin>>n>>c;
    for(int i=0;i<n;i++) {
        int x; cin>>x; arr.push_back(x);
    }
    sort(arr.begin(),arr.end());

    int start = 0;
    int end = arr[n-1] - arr[0];
    
    //첫 번쨰 공유기 무조건 설치한다고 생각한다.
    int res = 0;
    while(start<=end) {
        // 1. 중간 gap
        int mid = (start + end) / 2;
        int value = arr[0]; //설치한 공유기 
        int cnt = 1; //1개 설치 가정 
        
        // 2. 비교 
        for(int i=1;i<n;+i++) { //차례로 공유기를 설치해주는 과정
            if(arr[i] >= value + mid) {
                value = arr[i];
                cnt++;
            }
        }

        // 3. 공유기2의 갯수가 큰 경우 -> 거리 증가, 결과 저장
        if(cnt>=c) { //최대한 gap을 키워야하는 것이 목적이므로
            start = mid + 1; 
            res = mid;
        }
        // 4. 공유기의 갯수가 작은 경우 
        else { // 거리 감소
            end = mid - 1;
        }
    }
    cout<<res<<"\n";
    return 0;
}