#include <bits/stdc++.h>
using namespace std;

//global variable
int n,m;
int arr[10]; 

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);

    vector<int> prevArr;
    do {
        vector <int> tempArr;
        for(int i=0;i<m;i++){
            tempArr.push_back(arr[i]);
        }
        if(tempArr != prevArr) {
            for(int i=0;i<m;i++){
                cout<<tempArr[i]<<" ";
            }
            prevArr = tempArr;
            cout<<"\n";
        }
    } while(next_permutation(arr,arr+n));
    return 0;
}