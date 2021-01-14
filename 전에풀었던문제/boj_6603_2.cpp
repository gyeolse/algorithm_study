#include <iostream>
#include <algorithm>
using namespace std;
int num;
int input[50]; //input 들어가는 거
int arr[50];

void func(int n, int idx){
    if(idx==6){
        for(int i=0;i<6;i++){
            cout<<arr[i]<<" ";
        }
        cout<<'\n';
    }

    for(int i=n;i<num;i++){
        arr[idx] = input[i];
        func(i+1,idx+1);
    }
}
int main(void){
    while(1){
        cin>>num;
        if(num==0) break;
        for(int i=0;i<num;i++){
            cin>>input[i];
        }
        func(0,0);
        cout<<"\n";
    }
    return 0;
}