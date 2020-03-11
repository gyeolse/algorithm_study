//10972 다음 순열

/*
    1. 순열 문제임을 알아내는 방법 : 
        - N의 값이 1~10 내의 숫자
    2. algorithm 내의 next_permuation 이용하자
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int test_case;
int arr[10000];

//func 
bool next_perm(int* arr, int n){
    int i = n-1; //뒤에서 부터 돌아가면서

    while(i>0 && arr[i-1]>=arr[i]){
        i-=1;       //해당하는 i 탐색 과정
    }
    
    if(i<=0){
        return false; //사전순으로 마지막에 오는 순열이므로
    }

    int j = n-1; //j는 n-1이라고 일단 선언

    while(arr[j]<=arr[i-1]){ //-1씩 하면서 (i-1) ~ j idx 까지 arr[i-1] 보다 큰 애가 있으면 break
       j-=1; 
    }  

    swap(arr[i-1],arr[j]); //swap
    j=n-1; //다시 뒤로 가서 모두 뒤집어줌
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