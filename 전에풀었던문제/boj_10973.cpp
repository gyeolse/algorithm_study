//10973��. ���� ����

/*
    10972�� ���ٹ��� ����. ��ȣ�� �ݴ�� �ϸ� ��.
    vecotr�� algorithm�� �̿��ؼ� ��. ��~~~�� ����.
    �Ǽ�1. vector�� ũ�� ������ �������ߴµ� ���� ����. �������� �Ǽ����� �� ��.
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int test_case;

int main(void){

    cin>>test_case;
    vector<int> vec(test_case); //�Ǽ�1. vector�� ũ�⸦ �̸� �������־�� ��..... ������.

    for(int i=0;i<test_case;i++){
        cin>>vec[i];
    }

    if(prev_permutation(vec.begin(),vec.end())==1){
        for(int i=0;i<test_case;i++){
            cout<<vec[i]<<" ";
        }
    }
    else{
        cout<<-1<<'\n';
    }

    return 0;
}