#include <iostream>
using namespace std;

int main(void){
    int num;
    cin>>num;

    for(int i=0;i<num;i++){
        int m,n,x,y;
        bool isOK=false;
        cin>>m>>n>>x>>y;
        //x=3, y=5��� x=2, y=4�� ��.
        x-=1;
        y-=1;
//�ϴ� for���� m*n��ŭ ����. ������, for�� ������ ���鼭, m��ŭ ������. ������ x���� ���� ������ �ؾ��� 
//�� x���� �����ϳ�, x���� +m ����Ŭ�� �� �����Ѵٴ� �Ŵϱ�.
//*** x�� y�� 1�� ������ �ʰ�, now�� 1�� ���ϰ� ������� �ʾƵ�, 
//�׽�Ʈ���̽��� ���� ���´�. ������, Ʋ�ȴٰ� ���´�. ó���� �̷��� �߾��µ�

        for(int idx=x;idx<(m*n);idx+=m){
            if(idx%n==y){
                cout<<idx+1<<"\n";
                isOK= true;   
                break;    
            }
        }
        if(isOK==false){
            cout<<-1<<"\n";
        }
    }
    return 0;
}