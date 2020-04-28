#include <iostream>
#include <math.h>

using namespace std;

int length(int num){
    int cnt = 0;
    do{
        num = int(num/10);
        cnt++;

    }while(num>0);

    return cnt;
}

int main(void){
    int n;
    int result=0;
    int t_length;
    cin>>n;
    t_length = length(n);
    for(int i=0;i<t_length;i++){
        int temp=0;
        if((pow(10,i+1)-1)<n){
            temp = (pow(10,i+1)-1)-pow(10,i)+1;
        }
        else {
            temp = n-(pow(10,i))+1;
        }
     //   cout<<temp<<" ";
        result+=temp*(i+1);
   //     cout<<result<<"\n";
    }

    cout<<result<<"\n";
    return 0; 
}