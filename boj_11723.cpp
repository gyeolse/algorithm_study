//11723��. ����
#include <iostream>
#include <string>
using namespace std;
string s; //string �Է�
int n; //case
int MAX=20; //20���� ����
int input=0; //�ʱ�ȭ
int x;
int main(void){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>n;
//add, remove, check, toggle, all, empty
    for(int i=0;i<n;i++){
        cin>>s;
        //x-- ���ִ� ���� : bitset�� 0~���� �����̶� �ش� �ڸ��� �������� -1 ���־�� ��.
        if(s=="add"){
            cin>>x;
            x--; 
            input = (input|(1<<x));
        }

        else if(s=="remove") {
            cin>>x;
            x--;
            input = (input & ~(1<<x));
        }

        else if(s=="check") {
            cin>>x;
            x--;
            int temp = (input & (1<<x));
            if (temp)
                cout<<1<<'\n';
            else
                cout<<0<<'\n';
        }

        else if(s=="toggle") {
            cin>>x;
            x--;
            input = (input^(1<<x));
        }

        else if(s=="all") {
            //Ʋ�� �κ�
            input=(1<<MAX)-1; //���ǿ��� ���ߴ� �κ�. ��ü�� 1�� ������ ���� -1 ��.
        }

        else if(s=="empty") {
            input = 0;
        }
    }
    return 0;
}

