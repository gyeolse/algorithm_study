#include <bits/stdc++.h>
#define MAX 300001
using namespace std;

int n, m, k, x;
vector<int> graph[MAX];
int chk[MAX];
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m >> k >> x; //도시 갯수, 도로의 갯수, 최단 거리 , 출발 도시의 번호
    for (int i = 0;i < m;i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    //초기화 
    memset(chk, -1, sizeof(chk));
    chk[x] = 0;

    queue<int> que;
    que.push(x);

    while (!que.empty()) {
        int cur = que.front(); que.pop();
        for (int i = 0;i < graph[cur].size();i++) {
            int city = graph[cur][i];
            if (chk[city] == -1) {
                chk[city] = chk[cur] + 1;
                que.push(city);
            }
        }
    }

    vector<int> res;
    for (int i = 0;i <= n;i++) {
        if (chk[i] == k) {
            res.push_back(i);
        }
    }

    if (res.size() == 0) {
        cout << -1 << "\n";
    }
    else {
        for (int i = 0;i < res.size();i++) {
            cout << res[i] << "\n";
        }
    }
    return 0;
}