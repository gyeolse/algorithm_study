//N과 M (5)
// N 입력으로 주어지는 수는 10000보다 작거나 같은 자연수
#include <iostream>
#include <algorithm>
using namespace std;

int arr[10];
bool isUsed[10];
int input[10];
int n,m;

//사전 순으로 증가하는 순서로 출력
void func(int idx){
    int k;
    if(idx==m){
        for(k=0;k<m-1;k++){
            if(arr[k]>arr[k+1]) break;
        }
        if(k==m-1) {
            for(int i=0;i<m;i++){
                cout<<arr[i]<<" ";
            }
            cout<<"\n";
        }
        return;
    }

    for(int i=0;i<n;i++){
        if(!isUsed[i]){
            arr[idx] = input[i];
            isUsed[i] = true;
            func(idx+1);
            isUsed[i]= false;
        }
    }

    //aifa
    //arr true
    //isUsed
    //func
    //arr false
}

int main(void){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>input[i];
    }
    sort(input,input+n);
    func(0);
    return 0;
}