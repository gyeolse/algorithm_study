#include <bits/stdc++.h>
using namespace std;

#define MAX 101

int n, m;
char board[MAX][MAX];
int chk[MAX][MAX];

void input() {
    cin >> n >> m;

    for (int i = 0;i < n;i++) {
        string s;
        cin >> s;
        for (int j = 0;j < s.size();j++) {
            board[i][j] = s[j];
        }
    }
}

void output() {
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

void bfs() {
    
}
int main() {
    input();
    output();
    return 0;
}


