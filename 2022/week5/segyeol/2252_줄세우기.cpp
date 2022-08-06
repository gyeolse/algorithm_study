#include <bits/stdc++.h>
using namespace std;

vector<int> graph[32001];
int inDegree[32001];
int n, m;

void sort_() {
    queue<int> q;

    for (int i = 1;i <= n;i++) {
        if (!inDegree[i]) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        cout << cur << " "; // 정렬
        for (int i = 0;i < graph[cur].size();i++) {
            inDegree[graph[cur][i]]--;
            if (!inDegree[graph[cur][i]]) {
                q.push(graph[cur][i]);
            }
        }
    }

}

int main() {
    cin >> n >> m;

    for (int i = 0;i < m;i++) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        inDegree[b]++; // b의 차수를 1만큼 추가
    }
    sort_();

    return 0;
}