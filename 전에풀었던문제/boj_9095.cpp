//9095��. 1,2,3 ���ϱ�.
/*
    ����Լ� Ǯ��
    ��ͷ� Ǯ �� 3���� ã�Ƽ� ������ ��. (���� ��ȣ ǥ���ϱ�!) ��.��.����
    (1) �Ұ����� ���
    (2) ������ ã�� ���
    (3) ���� ������ ȣ���ϴ� ���

*/
#include <iostream>
#include <algorithm>

using namespace std;
int T; //test case
int sum;    

int go (int sum,int goal){
//1 ��
    if(sum>goal) return 0;
//2 ��
    if(sum==goal) return 1;
//3 ����
    int now = 0;
    
    //���� �ܰ�� �� �� �ִ� �� ���� ��� (1,2,3)
    for(int i=1;i<=3;i++){
        now+=go(i+sum,goal);
        //�ſ� ������. n=4�� ���� ���÷� �����ϸ鼭 �׷����� ���ϰ� ������ �� ���� ��.
        
    }
    return now;
}

int main(void){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>T;

    for(int i=0;i<T;i++){
        int n;
        cin>>n;
        cout<<go(0,n)<<"\n";
    }

    return 0;
}