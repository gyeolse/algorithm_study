#include <iostream>

using namespace std;
int n,m; //1������ ~ n������ �� ���̰� m�� ����
int arr[10]; //����� ���ڵ��� �����س��� �迭
bool isUsed[10];  // ����߳� ���߳�

//func�� �ǹ� k��°������ ������ Ȯ����Ű�� �Լ��� ���Ѵ�.
void func(int idx){
    int k;
    if(idx==m){
        for(k=0;k<m-1;k++){
//            cout<<"K�� �� : "<<k<<" "<<endl; ���������� �ͷ��Ҷ��
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

    for(int i=1;i<=n;i++){ //n����ŭ �����ؾ� ��. 
        if(!isUsed[i]){ //��� ���������� ������
            //����ߴ�
            isUsed[i]= true;
            //�迭�� �־��
            arr[idx] = i;
            //�������� �̵��ض�
            func(idx+1);
            isUsed[i]=false; //�ٽ� ����� �ʱ�ȭ ��Ŵ.
        }
    }
}
int main(void){
    cin>>n>>m;

    func(0);
    return 0;
}