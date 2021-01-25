//다시 풀어야함.
#include <bits/stdc++.h>
using namespace std;
#define MAX 100001

int g, p; //게이트, 비행기 수
int parent[MAX];
vector<int> plane;

int findParent(int x) {
    if(x==parent[x]) return x;
    return parent[x] = findParent(parent[x]);
}

void unionParent(int a, int b) {
    a = findParent(a);
    b = findParent(b);
    if(a>b) parent[a] = b;
    else parent[b] = a;
}

int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);
    cin >> g >> p;
    for (int i = 0;i < p;i++) {
        int x; cin>>x; plane.push_back(x);
    }

    //1. 자기 자신 바라보도록 초기화
    for(int i=1;i<=g;i++) {
        parent[i] = i;
    }

    int maxPlane = 0;

    //2. union-find
    for(int i=0;i<p;i++) {
        // cout<<"Plane"<<plane[i]<<" ";
        //3. 현재 비행기의 부모 확인
        int curParent = findParent(plane[i]);

        //4. 0이면, 이미 만땅인 거니까 못들어감. break;
        if(curParent == 0 ) break; 

        //5. 자기 자신이거나, 0이 아니면 도킹 가능함. 
        unionParent(curParent,curParent-1);
        maxPlane++;
    }

    cout<<maxPlane<<"\n";
    return 0;
}