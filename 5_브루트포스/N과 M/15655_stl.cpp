#include <bits/stdc++.h>
using namespace std;

//global variable
int n,m;
int arr[10];
vector<int> chk;
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    //고르는 것은 0, 안고르는 것은 1
    for(int i=0;i<m;i++){
        chk.push_back(0);
    }
    for(int i=0;i<(n-m);i++){
        chk.push_back(1);
    }
    sort(arr,arr+n);
    sort(chk.begin(),chk.end());
    do {
        for(int i=0;i<n;i++){
            if(chk[i]==0){
                cout<<arr[i]<<" ";
            }
        }
        cout<<"\n";
    } while(next_permutation(chk.begin(),chk.end()));
    return 0;
}