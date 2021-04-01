#include <bits/stdc++.h>
using namespace std;
#define MAX 101

int n;
int t;

vector<int> board[MAX];
bool chk[MAX];

void bfs() {
    // bfs. 1번부터 시작. 
    memset(chk, 0, sizeof(chk));
    queue<int> que;
    que.push(1);
    chk[1] = true;

    while (!que.empty()) {
        int cur = que.front(); que.pop();
        for (int i = 0;i < board[cur].size();i++) {
            int x = board[cur][i];
            if (chk[x] == false) {
                que.push(x);
                chk[x] = true;
            }
        }
    }
}

void func(int cur) {
    // recursive
    for (int i = 0;i < board[cur].size();i++) {
        int x = board[cur][i];
        if (chk[x] == false) {
            chk[x] = true;
            func(x);
        }
    }
}

void dfs() {
    memset(chk, 0, sizeof(chk));

    func(1);
}

void output() {
    int res = 0;
    for (int i = 1;i <= n;i++) {
        if (i != 1 && chk[i] == true) {
            res++;
        }
    }
    cout << res << "\n";
}

void print() {
    for (int i = 1;i <= n;i++) {
        cout << chk[i] << " ";
    }
    cout << endl;
}

void input() {
    cin >> n;
    cin >> t;
    for (int i = 0;i < t;i++) {
        int a, b;
        cin >> a >> b;
        board[a].push_back(b);
        board[b].push_back(a);
    }
}

int main() {

    input();
    // bfs();
    dfs();
    output();
    return 0;
}