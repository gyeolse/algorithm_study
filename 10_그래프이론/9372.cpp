#include <bits/stdc++.h>
using namespace std;
#define MAX 1001

int main() {
    // ios::sync_with_stdio(false); cin.tie(NULL);
    int tc;
    int n, m;
    cin >> tc;
    while (tc--) {
        //1. 
        int cnt = 0;
        bool visit[MAX];
        vector<int> vec[MAX];
        queue<int> que;

        memset(visit, 0, sizeof(visit));

        int f_ = 0;
        cin >> n >> m;

        for (int i = 0;i < m;i++) {
            int a, b;
            cin >> a >> b;
            if (i == 0) f_ = a;
            vec[a].push_back(b);
            vec[b].push_back(a);
        }

        //bfs
        que.push(f_);
        visit[f_] = 1;

        while (!que.empty()) {
            int cur = que.front(); que.pop();

            for (int j = 0;j < vec[cur].size();j++) {
                if (visit[vec[cur][j]] == 0) {
                    visit[vec[cur][j]] = 1;
                    que.push(vec[cur][j]);
                    cnt++;
                }
            }
        }

        cout << cnt << "\n";

    }
    return 0;
}