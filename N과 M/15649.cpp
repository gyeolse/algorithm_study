#include <bits/stdc++.h>
using namespace std;

/**
 * 재귀를 이용한 직접 구현 
 */

int m,n;
int arr[10];
bool isUsed[10];

void func_15649(int idx){
    if(idx==m){
        for(int i=0;i<m;i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
        return;
    }    
    for(int i=1;i<=n;i++){
        if(!isUsed[i]){ //isUsed[i]의 값이 false경우에만 진행
            arr[idx] = i; //출력할 수 저장 
            isUsed[i] = true; //사용
            func_15649(idx+1); //재귀
            isUsed[i] = false; //Reset
        }
    }
}

int main(){
    cin>>n>>m; //3,1
    func_15649(0); //0으로 시작
    return 0;
}