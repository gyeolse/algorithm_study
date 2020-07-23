#include <iostream>
#include <algorithm>
using namespace std;
int n,m;
int arr[10];
int input[10];
bool isUsed[10];
//중복은 되지만, 앞보다 작은건 안됨!
void func(int idx){
    if(idx==m){
        int k;
        for(k=0;k<m-1;k++){
            if(arr[k]>arr[k+1]) break;
        }

        if(k==m-1){
            for(int i=0;i<m;i++){
                cout<<arr[i]<<" ";
            }
            cout<<"\n";
        }
        return;
    }

    for(int i=0;i<n;i++){
        arr[idx] = input[i];
        func(idx+1);
    }
}

int main(void){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>input[i];
    }
    sort(input,input+n);
    func(0);
    return 0;
}