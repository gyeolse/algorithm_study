/**
 * dfs와 bfs : https://www.acmicpc.net/problem/1260
 * 그래프 dfs, bfs 순회
 */


#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int vertex, edge, start;
int arr[1001][1001]; //인접 행렬
bool visit[1001]; //방문했는지
void dfs(int n);
void bfs(int n);

int main(void) {
    cin >> vertex >> edge >> start;

    for (int i = 0; i < edge; i++) {
        int x, y;
        cin >> x >> y;
        arr[x][y] = arr[y][x] = 1; //주어진 edge가 양방향
    }

    //dfs, bfs
    dfs(start);
    cout << "\n";
    memset(visit, false, sizeof(visit));

    bfs(start);

}

void dfs(int n) {
    cout << n << " ";
    visit[n] = true;

    for (int i = 1; i <= vertex; i++) {
        if (visit[i] == false && arr[n][i] == 1)
            dfs(i);
    }
}

void bfs(int n) {
    queue<int> que;

    que.push(n);
    visit[n] = true;

    while (!que.empty()) {
        int currentNode = que.front();
        que.pop();
        cout << currentNode << " ";
        for (int i = 0; i <= vertex; i++) {
            if (visit[i] == false && arr[currentNode][i] == 1) {
                que.push(i);
                visit[i] = true;
            }
        }

    }
}