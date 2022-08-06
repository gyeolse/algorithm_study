//N-Queen. ��Ʈ��ŷ_2��°
#include <iostream>
using namespace std;
int N;
int ans=0;

bool a[15][15];
//�� �迭�� �߰��ؼ� Ǯ��_2
bool check_col[15];
bool check_dig[40];
bool check_dig_2[40];

//�밢�� ����, �밢���� ��ȣ�� �ű�. r+c

//check �Լ� : ���� �� �ִ� �ڸ�����
bool check(int r, int c){
    if(check_col[c]){
        return false;
    }
    if(check_dig[r+c]){ 
        return false;
    }
    if(check_dig_2[r-c+N]){
        return false;
    }
    return true;
}

//calc �Լ� : �� �ڸ� �����ϱ�
int calc(int r){
    if(r==N){
        return 1;
    }
    int cnt = 0;

    for(int c=0;c<N;c++){
        if(check(r,c)){
            //���� �� �ְ� ó��
            check_dig[r+c]=true;
            check_dig_2[r-c+N] =true;
            check_col[c]=true;
            a[r][c]=true;
            cnt+=calc(r+1);
            //�� �����·� ������.
            check_dig[r+c]=false;
            check_dig_2[r-c+N] =false;
            check_col[c]=false;
            a[r][c]=false;
        }
     
    }

    return cnt;
}


int main(void){
    cin>>N;
    cout<<calc(0)<<"\n";
    return 0;
}