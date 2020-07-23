#include <iostream>
using namespace std;

int n,m; //n은 ~자연수 몇까지 m은 배열 길이.
bool isUsed[10];
int arr[10];

//같은 수 여러번 골라도 OK

void func(int idx){
    if(idx==m){
        for(int i=0;i<m;i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
        return;
    }

    for(int i=1;i<=n;i++){
        arr[idx] = i;
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