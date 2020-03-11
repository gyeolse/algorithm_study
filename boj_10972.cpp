//10972 ���� ����

/*
    1. ���� �������� �˾Ƴ��� ��� : 
        - N�� ���� 1~10 ���� ����
    2. algorithm ���� next_permuation �̿�����
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int test_case;
int arr[10000];

//func 
bool next_perm(int* arr, int n){
    int i = n-1; //�ڿ��� ���� ���ư��鼭

    while(i>0 && arr[i-1]>=arr[i]){
        i-=1;       //�ش��ϴ� i Ž�� ����
    }
    
    if(i<=0){
        return false; //���������� �������� ���� �����̹Ƿ�
    }

    int j = n-1; //j�� n-1�̶�� �ϴ� ����

    while(arr[j]<=arr[i-1]){ //-1�� �ϸ鼭 (i-1) ~ j idx ���� arr[i-1] ���� ū �ְ� ������ break
       j-=1; 
    }  

    swap(arr[i-1],arr[j]); //swap
    j=n-1; //�ٽ� �ڷ� ���� ��� ��������
    while(i<j){ 
        swap(arr[i],arr[j]);
        i +=1;j -=1;
    }  
    return true;
}

int main(void){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>test_case;

   int temp;
   for(int i=0;i<test_case;i++){
       cin>>arr[i];
    }

    if(next_perm(arr,test_case)==0){
        cout<<-1<<'\n';
    }
    else{
        for(int i=0;i<test_case;i++){
            cout<<arr[i]<<" ";
        }
    }

    return 0;

}