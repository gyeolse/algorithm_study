#include <bits/stdc++.h>
using namespace std;
#define MAX 1001
int n, m;
int graph[MAX][MAX];

bool dfs(int i, int j) {
    if (i >= n || j >= m || i < 0 || j < 0) return false;

    //해당 노드 방문하지 않았을 경우,
    if (graph[i][j] == 0) {
        //방문 처리
        graph[i][j] = 1;
        //상, 하, 좌, 우 모두 재귀호출
        dfs(i - 1, j);
        dfs(i, j - 1);
        dfs(i + 1, j);
        dfs(i, j + 1);
        return true;
    }
    return false;
}

int main() {
    //1. input
    cin >> n >> m;
    for (int i = 0;i < n;i++) {
        string s; cin >> s;
        for (int j = 0;j < s.size();j++) {
            if (s[j] == '0') graph[i][j] = 0;
            else if (s[j] == '1') graph[i][j] = 1;
        }
    }

    //2. dfs
    int res = 0;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            if (dfs(i, j)) {
                res += 1;
            }
        }
    }
    cout<<res<<"\n";
    return 0;
}