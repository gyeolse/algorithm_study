#include <iostream>
#include <vector>
using namespace std;
const long mod=1000000009LL;
long long d[100001][4]; //배열 d
const int limit = 100000;
/*
    1. 점화식
        d[n][1] = d[n-1][2] + d[n-1][3]
        d[n][2] = d[n-2][1] + d[n-1][3]
        d[n][3] = d[n-3][1] + d[n-1][2]
    2. 큰 것 -> 작게
*/
int main(void){

    int test_case;
    int n;

    for(int i=1;i<=limit;i++){
        if(i-1>=0){
            d[i][1] = d[i-1][2] + d[i-1][3];
            if(i==1){
                d[i][1]=1;
            }
        }
        if(i-2>=0){
            d[i][2] = d[i-2][1] + d[i-2][3];
            if(i==2){
                d[i][2] = 1;
            }
        }
        if(i-3>=0){
            d[i][3] = d[i-3][1] + d[i-3][2];
            if(i==3){
                d[i][3]=1;
            }
        }
        d[i][1] %=mod;
        d[i][2] %=mod;
        d[i][3] %=mod;
    }
   
    cin>>test_case;
    for(int i=0;i<test_case;i++){
        cin>>n;
        cout<<(d[n][1]+d[n][2]+d[n][3])%mod<<'\n';
    }
    return 0;
}
