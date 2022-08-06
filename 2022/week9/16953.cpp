#include <bits/stdc++.h>
using namespace std;

int bfs(long long a, long long b) {
    queue<pair<long long, long long>> que;
    que.push({ a, 1 });

    while (!que.empty()) {
        pair<long long, long long> cur = que.front(); que.pop();
        if (cur.first == b) {
            return cur.second;
        }
        if (cur.first * 2 <= b) {
            que.push({ cur.first * 2, cur.second + 1 });
        }
        if (cur.first * 10 + 1 <= b) {
            que.push({ cur.first * 10 + 1, cur.second + 1 });
        }
    }
    return -1;
}

int main() {
    long long a, b;
    cin >> a >> b;
    cout << bfs(a, b);

    return 0;
}