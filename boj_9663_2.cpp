#include <iostream>
#include <algorithm>
using namespace std;
int n;
int cnt; //answer
bool isUsed1[15];
bool isUsed2[30];
bool isUsed3[30];
int arr[15];

void func(int idx){
    if(idx==n){
        cnt++;
        return;
    }

    for(int i=0;i<n;i++){
        if(isUsed1[i]||isUsed2[i+idx]||isUsed3[i-idx+n-1]) continue;
        isUsed1[i]=true;
        isUsed2[i+idx] = true;
        isUsed3[i-idx+n-1] = true;
        func(idx+1);
        isUsed1[i]=false;
        isUsed2[i+idx] = false;
        isUsed3[i-idx+n-1] = false;        
    }
}
int main(void){
    cin>>n;
    func(0);
    cout<<cnt;
    return 0;
}