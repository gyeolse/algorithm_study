//15656.cpp
//N개의 자연수. M개를 고른 수열
#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int input[10];
int arr[10];
bool isUsed[10];

void func(int idx){
    if(idx==m){
        for(int i=0;i<m;i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
        return;
    }

    for(int i=0;i<n;i++){
                    //arr
            arr[idx]=input[i];
            //재귀
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