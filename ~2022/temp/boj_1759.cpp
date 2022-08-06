//1759��. ��ȣ �����

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

/*
    1. ��� ����. check �Լ��� ������ �� �־��µ�, go �Լ� �������� ���� ������
        ������ �� ������.
    2. �� �������� �� �� �Լ��� ��������
    �����ϴ� ���/ �������� �ʴ� ���.
    abcd�� �Ǿ����� ��
    a - (0) (x)
        go_1759(n,alpha,password+alpha[i],i+1); //idx�� �ϳ� ������.
        go_1759(n,alpha,password,idx+1); //�������� ���� �͵� idx�� �����־����.
        
    b - (0) (x)
    c - (0) (x)
    d - (0) (x)
*/
//��͹��� 3���� �������
// (1) �Ұ����� ���
// (2) ������ ���
// (3) ���� ������ ã�� ���

using namespace std;

vector <char> alpha;
string password;

//���� ������ �ϴ��� ���� �ʴ���
bool check(string password){
    //password ��ü����, ������ ������ 2�� �̻����� Ȯ��. ������ ���� 1�� �̻����� Ȯ��
    int ja = 0;
    int mo = 0;
    for(char x: password){ //char x������ ������. for�� �̰� �ͼ���������. 
        if(x=='a'||x=='e'||x=='i'||x=='o'||x=='u'){
            mo++;
        }
        else{
            ja++;
        }
    }
    if(ja>=2 && mo >=1){
        return true;
    }
    else {
        return false;
    }
}

//n : ������ �ϴ� ����, alpha : �־��� ���ĺ�, password : ���� ��ȣ, i : ���� idx
void go_1759(int n,vector <char> &alpha, string password, int idx){
    //������ ���
    if(password.length() == n){
        if(check(password)){
            cout<<password<<'\n';
        }
        return; //�Ƥ�....
    }
    //�Ұ����� ��� 1. �������ϴ� ���̺��� idx�� �� Ŭ ��
    if(idx>=alpha.size()) return;

    //���� ���. �ణ ���ذ� �Ȱ�.
    //���ĺ��� ����ϴ� ���/ ���� �ʴ� ����̹Ƿ� �� ���� �����
    go_1759(n,alpha,password+alpha[idx],idx+1); //����� ���
    go_1759(n,alpha,password,idx+1); //������� ���� �͵� ������ ��.

}

int main(void)
{
    int l,c; //l�� ����� ����, c�� �־����� ����
    cin>>l>>c;
    vector<char> alpha_(c);

    for(int i=0;i<c;i++){
        cin>>alpha_[i];
    }
    
    sort(alpha_.begin(),alpha_.end()); //sort�ϴ� ����

    go_1759(l,alpha_,"",0);
    return 0;
}
