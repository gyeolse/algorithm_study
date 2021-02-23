#include <bits/stdc++.h>
using namespace std;

int tc;

int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);
    cin >> tc;

    while (tc--) {
        vector<int> graph[20001];
        queue<int> que;
        int color[20001]; //1 red,  2 blue

        memset(color, 0, sizeof(color));
        int v, e;
        cin >> v >> e;
        int s_ = 0;

        for (int i = 0;i < e;i++) {
            int one, two;
            cin >> one >> two;
            graph[one].push_back(two);
            graph[two].push_back(one);
        }

        bool flag = true;

        //시작점을 첫번째로 둔 것이 문제였다. 
        //시작점으로부터 도달할 수 없는 어느 한 정점이 존재할 수 있는데, 
        //그 부분을 간과해서 생긴 문제.

        for (int i = 1;i <= v;i++) {
            if (color[i] == 0) {
                que.push(i);
                color[i] = 1; //red로 시작
            }
            while (!que.empty()) {
                int cur = que.front(); que.pop();

                for (int i = 0;i < graph[cur].size();i++) {
                    int temp = graph[cur][i]; //이번 순서 정점 번호
                    if (color[temp] == 0) {
                        if (color[cur] == 1) {
                            color[temp] = 2;
                        }
                        else {
                            color[temp] = 1;
                        }

                        que.push(temp);
                    }
                    else if (color[temp] == color[cur]) {
                        flag = false;
                        break;
                    }
                }
            }
        }


        if (flag == false) {
            cout << "NO" << "\n";
        }
        else {
            cout << "YES" << "\n";
        }
    }
}