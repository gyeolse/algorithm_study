#include <bits/stdc++.h>
using namespace std;

int dist[200001];
bool check[200001];
int from[200001];

int main(void) {

    void init();
    int n, k;
    cin >> n >> k;

    check[n] = true;
    dist[n] = 0;
    queue<int> que;
    que.push(n);

    while (!que.empty()) {
        int now = que.front();
        que.pop();
        if (now - 1 >= 0) {
            if (check[now - 1] != true) {
                que.push(now - 1);
                check[now - 1] = true;
                dist[now - 1] = dist[now] + 1;
                from[now - 1] = now;

            }
        }

        if (now + 1 < 200000) {
            if (check[now + 1] != true) {
                que.push(now + 1);
                check[now + 1] = true;

                dist[now + 1] = dist[now] + 1;
                from[now + 1] = now;

            }
        }

        if (now * 2 < 200000) {
            if (check[now * 2] != true) {
                que.push(now * 2);
                check[now * 2] = true;

                dist[now * 2] = dist[now] + 1;
                from[now * 2] = now;
            }
        }

    }
    cout << dist[k] << "\n";

    stack <int> stk;

    for (int i = k;i != n;i = from[i]) {
        stk.push(i);
    }

    stk.push(n);
    while (!stk.empty()) {
        cout << stk.top() << " ";
        stk.pop();
    }
    return 0;
}