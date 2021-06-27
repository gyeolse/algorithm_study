#include <bits/stdc++.h>
using namespace std;

//중복되는 수열 삽입 후, 출력
int n,m;
int arr[10];
set<vector<int>> res;

int main(){
    cin>>n>>m; //4 2
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n); //정렬

    do {
        vector<int> temp;
        for(int i=0;i<m;i++){
            temp.push_back(arr[i]);
        }
        res.insert(temp);
    } while(next_permutation(arr,arr+n));

//iterator 코드
    for( auto it : res ){
        for(int i=0;i<it.size();i++){
            cout<<it[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}