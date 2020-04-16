//ī�� �����ϱ�

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//1. ��ȭ�� �����. D[i] = max(P[i]+D[i-j])
//2. �۰� �ɰ��� Top-Down || Bottom Up

int main(void){
    int N;
    cin>>N;
    vector<int> a(N+1); //a. ũ�� N+1. ���� ����
    for(int i=1;i<=N;i++){
        cin>>a[i];
    }
    vector<int> d(N+1); //d. �ִ� ����.
    for(int i=1;i<=N;i++){
        for(int j=1;j<=i;j++){
            d[i] = max(d[i],d[i-j]+a[j]);
        }
    }
    cout<<d[N]<<'\n';

    return 0;
}