#include <bits/stdc++.h>
using namespace std;

int V, M;
vector<pair<int, int>> v[1001];
int upper[1001];

int func(int src) {
    // 시작점을 제외한 모든 정점 최단거리 초기화 
    fill_n(upper, 1001, 987654321);
    upper[src] = 0;
    bool updated;
    for (int i = 0;i < V;i++) {
        updated = false;
        for (int j = 1;j <= V;j++) {
            for (int k = 0;k < v[j].size();k++) {
                int there = v[j][k].first;
                int cost = v[j][k].second;

                if (upper[there] > upper[j] + cost) { // 이번거가 더 적으면
                    upper[there] = upper[j] + cost; // reset
                    updated = true;
                }
            }
        }
        if (!updated) break; // 모든 간선에 대해서 줄이기 실패하면 break
    }
    if (updated) return 1; // 음수 사이클이 있다.
    return 0;
}

int main() {
    cin >> V >> M;
    for (int i = 0;i < M;i++) {
        int a, b, c; cin >> a >> b >> c;
        v[a].push_back({ b,c });
    }
    int start, arrive; cin >> start >> arrive;
    if (!func(start)) {
        cout << upper[arrive];
    }

    return 0;
}