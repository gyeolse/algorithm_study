#include <bits/stdc++.h>
using namespace std;

int n,s,m; //곡의 갯수, 시작 볼륨, M(제한)
bool dp[101][1001]; //n번째에서 이용가능한 볼륨 
int arr[101];

int main() {
    cin>>n>>s>>m;

    for(int i=1;i<=n;i++) {
        cin>>arr[i];
    }

    //1. 처음 값을 true로 세팅 
    if(s + arr[1] <= m) dp[1][s + arr[1]] = true;
    if(s - arr[1] >= 0 ) dp[1][s-arr[1]] = true;

    //2. i번째에 이용 가능한 음정을 바탕으로 -> 
    //      n번째에서 이용가능한 음정 중 MAX값을 찾는다. 
    for(int i=2;i<=n;i++) {
        for(int j=0;j<=m;j++) {
            if(dp[i-1][j] == true) {
                if(j + arr[i] <= m) dp[i][j+arr[i]] = true;
                if(j - arr[i] >= 0) dp[i][j-arr[i]] =true; 
            }
        }
    }


    for(int i=m;i>=0;i--) {
        if(dp[n][i] == true) {
            cout<<i<<"\n";
            return 0;
        }
    }
    cout<<-1<<"\n";

    return 0;
}