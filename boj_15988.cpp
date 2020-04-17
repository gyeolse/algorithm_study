#include <iostream>
using namespace std;

const long long MOD = 1000000009;
long long dp[1000001];
int n;
int T;

int main(void){
    dp[0]=1;
    for(int i=1;i<=1000000;i++){
        if(i-1>=0){ //1일때부터 수행
            dp[i] +=dp[i-1];
        }
        if(i-2>=0){ //2일때부터 수행
            dp[i] +=dp[i-2];
        }
        if(i-3>=0){ //3일때부터 수행
            dp[i] +=dp[i-3];
        }

        dp[i] %=MOD; //mod 연산
    }
    
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>n;
        cout<<dp[n]<<"\n";
    }
    return 0;
}