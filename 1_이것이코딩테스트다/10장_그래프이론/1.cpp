// 기본적인 서로소 집합 알고리즘
#include <bits/stdc++.h>
using namespace std;

int v,e;
int parent[100001]; //부모 테이블

//2. 원소가 속한 집합 찾기 -- 개선 전
// int findParent (int x) {
//     if(x==parent[x]) return x;
//     return findParent(parent[x]);
// }

//2-1. 개선 후. findParent를 재귀적으로 호출해서, 바로 부모 테이블 값 개선
int findParent(int x) {
    // 루트 노드가 아니면, 루트 노드 찾을 때 까지 재귀적 호출
    if(x==parent[x]) return x;
    return parent[x] = findParent(parent[x]);
}
//1. 두 원소가 속한 집합 합치기
void unionParent(int a, int b) {
    a = findParent(a);
    b = findParent(b);

    if(a<b) parent[b] =a;
    else parent[a] = b;
}
int main() {
    cin>>v>>e;

    //부모 테이블을 자기 자신으로 초기화
    for(int i=1;i<=v;i++){
        parent[i] = i;
    }

    //union 연산 수행
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        unionParent(a,b);
    }

    //각 원소가 속한 집합
    for(int i=1;i<=v;i++){
        cout<<findParent(i)<<" ";
    }
    cout<<"\n";
    
    //부모 테이블
    for(int i=1;i<=v;i++){
        cout<<parent[i]<<" ";
    }
    cout<<"\n";

    return 0;
}