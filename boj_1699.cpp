#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int dp[100001];

//전체 크기 N에서 그 수를 뺄 수 있는 가장 큰 제곱수 a로 빼기
//뺀 후 남은 dp[N] = dp[N-a] + 1
//제곱수를 어떻게 구할것인가

int main(void){
    cin>>n;
    for(int i=1;i<=n;i++){
        dp[i] = i; 
        for(int j=1;j*j<=i;j++){ //차례대로 제곱수를 찾아가는 과정
            if(dp[i]>dp[i-j*j]+1){
                dp[i] = dp[i-j*j]+1;
            }
        }
    }

    cout<<dp[n]<<"\n";
    return 0;
}