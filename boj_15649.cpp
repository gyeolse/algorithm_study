//15649. N�� M (1)

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
            cout<<"K�� �� : "<<k<<" i�� �� : "<<i<<endl;
            func(k+1);
            isused[i]=0; //��� ��츦 �� Ȯ���Ͽ�����, �ٽ� i�� ���� ������� �ʴ´ٰ� ǥ����.
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;

    func(0);
}