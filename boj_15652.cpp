//N과 M (4)
//N까지의 자연수. M개를 선택
//비내림차순. (내림차순X)

#include <iostream>
using namespace std;
int n,m;
int arr[10];
int isUsed[10];
void func(int idx){
    int k;
    if(idx==m){
        for(k=0;k<m-1;k++){
            if(arr[k]>arr[k+1]) break; 
        }
        if(k==m-1){
            for(int i=0;i<m;i++){
                cout<<arr[i]<<" ";
            }
            cout<<'\n';
        }
        return;
    }

    for(int i=1;i<=n;i++){
        arr[idx]=i;
        func(idx+1);
    }
}

int main(void){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>n>>m;
    func(0);
    return 0;
}