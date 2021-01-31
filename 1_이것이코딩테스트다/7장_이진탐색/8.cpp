#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> arr;

int main (void) {
    cin>>n>>m; //n 떡볶이 갯수, m 최댓값
    for(int i=0;i<n;i++){
        int x; cin>>x; arr.push_back(x);
    }

    //1. 정렬
    sort(arr.begin(),arr.end());
    int end = *max_element(arr.begin(),arr.end());
    int start = 0;

    int res=0;
    //2. 
    while(start <= end){
        int curLength = 0;
        int mid = (end+start)/2;

        for(int i=0;i<n;i++){
            if(mid < arr[i]) {
                curLength += (arr[i]-mid);
            }
        }

        //떡이 더 필요한 경우 -> 왼쪽
        if(curLength < m) {
            end = mid-1;
        }
        //떡이 충분하경우 덜 자르가 -> 오른쪽
        else {
            res = mid;
            start = mid+1;
        }
    }

    cout<<res<<"\n";
    return 0;
}