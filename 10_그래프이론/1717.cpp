#include <bits/stdc++.h>
using namespace std;
#define MAX 1000001
int n,m;
int parent[MAX];

//1. 부모를 찾는 함수. 재귀
int findParent(int x) {
    if(x==parent[x]) return x;
    return parent[x] = findParent(parent[x]);
}

//2.부모를 합치는 함수
void unionParent(int a, int b) {
    a = findParent(a);
    b = findParent(b);
    if(a>b) parent[a] = b;
    else parent[b] = a;
}

int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);
    cin>>n>>m;
    //1. 자기 자신를 부모로 설정하는 과정
    for(int i=1;i<=n;i++){
        parent[i] = i;
    }

    for(int i=0;i<m;i++) {
        int t, a,b;
        cin>>t>>a>>b;

        if(t==0) { //합치기
            unionParent(a,b);
        }
        else if (t==1) { //출력
            int aParent = findParent(a);
            int bParent = findParent(b);
            if(aParent == bParent) cout<<"YES"<<"\n";
            else cout<<"NO"<<"\n";
        }
    }
    return 0;
}