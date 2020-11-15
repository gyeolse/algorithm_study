//stl을 사용해서 문제풀이
#include <bits/stdc++.h>
using namespace std;

/**
 * 자연수 N과 M이 주어지고, 한 줄에 하나씩 문제의 조건에 만족하는 수열을 출력
*/
int main(){
    int m,n;
    int arr[10];

    cin>>n>>m; //3,1
    for(int i=0;i<n;i++){
        arr[i]=i+1;
    }
    
    vector<int> temp;
    do {
        vector<int> lptemp;
        for(int i=0;i<m;i++){
            lptemp.push_back(arr[i]);
        }
        if(temp!=lptemp){
            for(int i=0;i<m;i++){
                cout<<lptemp[i]<<" ";
            }
            cout<<"\n";
            temp=lptemp;
        }
    } while(next_permutation(arr,arr+n));
    
    return 0;
}