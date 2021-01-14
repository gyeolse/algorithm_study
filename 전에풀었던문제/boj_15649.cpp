//15649. N과 M (1)

#include <iostream>
using namespace std;

int n, m;
int arr[10];
bool isused[10];

void func(int k){
    if(k==m){
        for(int i=0;i<m;i++){
            cout<<arr[i]<<" ";            
        }
        cout<<"\n";
        return;
    }

    for(int i=1;i<=n;i++){
        if(isused[i]==0){
            arr[k]=i;
            isused[i]=1;
            cout<<"K의 값 : "<<k<<" i의 값 : "<<i<<endl;
            func(k+1);
            isused[i]=0; //모든 경우를 다 확인하였으니, 다시 i를 이제 사용하지 않는다고 표시함.
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;

    func(0);
}