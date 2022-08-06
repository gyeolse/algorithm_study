#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int input;
int n, idx;
int arr[10]={0,1,2,3,4,5,6,7,8,9};
bool isBroken[10];

int temparr[10]; //임시로 만들어짐 ( 채널은 최대 50만개 )
int limit;

int idxSize (int n){ //숫자 자릿수
    int temp;
    while(1){
        n/=10;
        temp++;
        if(n==0) break;
    }
    return temp;
}

void func(int idx){
    if(idx==limit){ //수를 다 만듦
        for(int i=0;i<idx;i++){
            cout<<temparr[i]<<" ";
        }
        cout<<endl;
    }

    for(int i=0;i<10;i++){
        if(!isBroken[i]){
            temparr[idx]= arr[i];
            func(idx+1);
            cout<<"entered"<<" ";
        }
    }

}

int main(void){
    cin>>input;
    cin>>n;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        isBroken[temp]=true;
    }    
    limit = idxSize(input);
    func(0);
    return 0;
}