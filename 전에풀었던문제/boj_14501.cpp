//14501. ���
#include <iostream>

using namespace std;

/*
    Ʋ��. ��͹��� ��¥ ���� �����ִ°� �ʹ� ��ģ��...
    �� Ǯ������� �������̴µ�, ���� Ǯ���� �ʹ� ��ƴ�....
    �� ���޴´�....
    
    ���. 0,1,2,3 �������
    0. ������ ��������/����
    1. �Ұ����� ��� : ���̻�X, ���� ����, �Ҽ��ִ¼���X
    2. ������ ���
    3. ���� ���
*/
int n; //n�� ���ķδ� �� �Ҽ��� ����
int T[1000]; //�ð� ����
int P[1000]; //�ݾ�
int answer=0;
//��¥, �ݾ�, day
void go_14501(int day, int sum){
//2 ������ ���
    if(day==n+1){
        if(answer<sum){ //���ݱ����� ���ͺ��� ū ��쿡��
            answer =sum;
            return;
        }
    }
//1 �Ұ�. day�� n���� Ŭ ���
    if(day>n){
        return;
    }

    go_14501(day+T[day],sum+P[day]); //���� 0
    go_14501(day+1,sum); //���� X
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>T[i]>>P[i];
    }
    go_14501(1,0);
    cout<<answer<<"\n";
    return 0;
}