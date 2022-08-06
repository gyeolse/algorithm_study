#include <bits/stdc++.h>
using namespace std;
#define MAX 100001
#define INF 999999999

int n, k;
int visit[MAX];

// 가중치가 다름 -> 해당 위치에 몇초만에 갔는지 배열에 기록하고, 그거보다 더 빠르게 도착하면 업데이트 

int bfs() {
    queue<int> que;
    que.push(n);
    visit[n] = 0;

    while (!que.empty()) {
        int cur = que.front(); que.pop();
        if (cur == k) return visit[k];

        if (cur + 1 < MAX && visit[cur + 1] > visit[cur] + 1) {
            visit[cur + 1] = visit[cur] + 1;
            que.push(cur + 1);
        }

        if (cur - 1 >= 0 && visit[cur - 1] > visit[cur] + 1) {
            visit[cur - 1] = visit[cur] + 1;
            que.push(cur - 1);
        }

        if (cur * 2 < MAX && visit[cur * 2] > visit[cur]) {
            visit[cur * 2] = visit[cur];
            que.push(cur * 2);
        }
    }
}

int main() {
    cin >> n >> k;
    for (int i = 0;i < MAX;i++) {
        visit[i] = INF;
    }

    int res = bfs();
    cout << res << '\n';
}
