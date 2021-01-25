//크루스칼 알고리즘
#include <bits/stdc++.h>
using namespace std;
int v, e;
int parent[100001]; // 부모 테이블
vector<pair<int, pair<int, int>>> edges; //cost, v1, v2
int res = 0;

//부모를 찾는 함수
int findParent(int x) {
    if (x == parent[x]) return x;
    return parent[x] = findParent(parent[x]);
}

//두 원소가 속한 집합 찾기. 작은 부모가 최고임
void unionParent(int a, int b) {
    a = findParent(a);
    b = findParent(b);
    if (a > b) parent[a] = b;
    else parent[b] = a;
}

int main() {
    //1. 정보 입력
    cin >> v >> e;
    for (int i = 0;i < e;i++) {
        int a, b, cost;
        cin >> a >> b >> cost;
        edges.push_back({ cost,{a,b} });
    }

    //2. parent 초기화 (까먹지 말자)
    for(int i=1;i<=v;i++){
        parent[i] = i;
    }
    //2. cost 별로 정렬
    sort(edges.begin(),edges.end());

    //3. 크루스칼 알고리즘 시작.
    for(int i=0;i<edges.size();i++) {
        int cost = edges[i].first;
        int a = edges[i].second.first;
        int b = edges[i].second.second;
        //1) 사이클인지 확인 -> 사이클이면 넘어가고,
        //2) 사이클이 아니면, Union 해준다.
        if(findParent(a) != findParent(b)) {
            unionParent(a,b);
            res +=cost;
        }
    }

    cout<<res<<"\n";
    return 0;
}

/*
7 9
1 2 29
1 5 75
2 3 35
2 6 34
3 4 7
4 6 23
4 7 13
5 6 53
6 7 25
*/