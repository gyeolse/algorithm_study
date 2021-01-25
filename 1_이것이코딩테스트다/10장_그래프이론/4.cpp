#include <bits/stdc++.h>
using namespace std;

int v, e;
int parent[100001];


int findParent(int x) {
    if(x==parent[x]) return parent[x];
    return parent[x] = findParent(parent[x]);
}

void unionParent(int a, int b) {
    a = findParent(a);
    b = findParent(b);
    a < b ? parent[b] = a : parent[a] = b;
}


int main() {
    cin >> v >> e;

    //1. 자기 자신 - 부모 초기화
    for (int i = 1;i <= v;i++) {
        parent[i] = i;
    }

    bool cycle = false; 
    //2. 간선만큼 추가
    for(int i=0;i<e;i++) {
        int a,b;
        cin>>a>>b;

        // 사이클 수행 확인
        if(findParent(a) == findParent(b)) {
            cycle = true;
            break;
        }
        //사이클 발생하지 않은 경우, 합집합 연산 수행 
        else {
            unionParent(a,b);
        }
    }

    if(cycle) {
        cout<<"Cycle"<<"\n";
    }
    else {
        cout<<"No Cycle"<<"\n";
    }
}