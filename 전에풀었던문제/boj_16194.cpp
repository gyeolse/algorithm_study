//카드 구매하기 2. 16194
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//1. 점화식 세우기. D[i] = max(P[i]+D[i-j])
//2. 작게 쪼개기 Top-Down || Bottom Up

int main(void){
    int N;
    cin>>N;
    vector<int> a(N+1); //a. 크기 N+1. 가격 저장
    for(int i=1;i<=N;i++){
        cin>>a[i];
    }
    vector<int> d(N+1); //d. 최소값 저장.
    for(int i=1;i<=N;i++){
        d[i] = 1000*10000;
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=i;j++){
            d[i] = min(d[i],d[i-j]+a[j]);
        }
    }
    cout<<d[N]<<'\n';

    return 0;
}