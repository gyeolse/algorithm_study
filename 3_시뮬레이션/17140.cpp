#include <bits/stdc++.h>
#define MAX 101

using namespace std;
int board[MAX][MAX];

int r, c, k;
int ans = 0;

void input();
void print();

// i, j, k
bool isExist(int i, int j, int k) {
    if (board[i][j] == k) return  true;
    return false;
}

int main() {
    input();

    while (1) {

        // r, c
        vector<vector<int>> curVec;
        for (int i = 0;i < r;i++) {
            for (int j = 0;j < c;j++) {
                curVec[i].push_back(j);
            }
        }







        if (isExist(r, c, k) == true) break;
        if (ans == 100) break;
        ans++;
    }

    print();
    return 0;
}

void print() {
    if (ans == 100) {
        cout << -1 << "\n";
    }
    else {
        cout << ans << "\n";
    }
}

void input() {
    cin >> r >> c >> k;
    for (int i = 0;i < r;i++) {
        for (int j = 0;j < c;j++) {
            cin >> board[i][j];
        }
    }
}