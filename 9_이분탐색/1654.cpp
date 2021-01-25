#include <bits/stdc++.h>
using namespace std;

long long k;
long long n;
vector<long long> arr;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin>>k>>n;
    for(int i=0;i<k;i++){
        long long x; cin>>x; arr.push_back(x);
    }

    // OK
    long long end = *max_element(arr.begin(),arr.end());
    long long start = 1;
    long long res = 0;

    //이분 탐색
    while(start <= end) {
        long long mid = (start + end ) / 2 ; 
        long long curLength =  0;

        for (int i=0;i<k;i++) {
            curLength  += (arr[i]/mid);
        }

        //1. N개 보다 적게 만든 경우, 왼쪽으로 이동 
        if(curLength < n ) {
            end = mid-1;
        }
        //2. N개 보다 많이 만든 경우 -> N개에 포함된다. 오른족으로 이동.
        else {
            if(res < mid ) res = mid; //modify 
            start = mid + 1;
        }
    }


    cout<<res<<"\n";
    return 0;
}