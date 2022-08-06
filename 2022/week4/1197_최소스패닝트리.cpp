#include <bits/stdc++.h>
using namespace std;

int v, e;
vector<pair<int, pair<int, int>>> vec;
int ans = 0;
int parent[100001]; // parent 별도로 보관

// Prime, Kruskal. minimum spanning tree

// 가중치가 최소여야 한다 -> 매번 최소를 골라서 합치고 합쳐버리기
// 최소 순으로 정렬시켜두고, 그대로 크루스칼 조지기

int findParent(int a) {
    if (parent[a] == a) return a;
    return parent[a] = findParent(parent[a]);
}

void unionParent(int a, int b) {
    a = findParent(a);
    b = findParent(b);

    // 더 숫자가 작은 놈으로 합치기
    if (a > b) parent[a] = b;
    else parent[b] = a;
}

// a, b, c. a번 정점, b번 정점, c는 가중치
int main() {
    cin >> v >> e;

    // 부모 별도로 세팅
    for (int i = 1; i <= 10001;i++) {
        parent[i] = i; // 지 자신으로 일단 세팅
    }

    for (int i = 0;i < e;i++) {
        int a, b, c; cin >> a >> b >> c;
        vec.push_back({ c,{a,b} });
    }

    sort(vec.begin(), vec.end()); // 가중치 순으로 정렬할거라

    for (int i = 0;i < vec.size();i++) {
        int cost_ = vec[i].first;
        int a_ = vec[i].second.first;
        int b_ = vec[i].second.second;

        if (findParent(a_) != findParent(b_)) {
            unionParent(a_, b_);
            ans += cost_;
        }
    }
    cout << ans << "\n";
    return 0;
}