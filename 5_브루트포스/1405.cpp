#include <bits/stdc++.h>
using namespace std;

int n;
double percent[4];
double ans;

int dirX[4] = { 0,0,1,-1 };
int dirY[4] = { 1,-1,0,0 };

bool arr[100][100];

void dfs(int x, int y, int cnt, double res) {
    if (cnt == n) {
        ans += res;
        return;
    }

    int curX, curY;
    for (int i = 0;i < 4;i++) {
        curX = x + dirX[i];
        curY = y + dirY[i];

        if (arr[curX][curY] == 0) {
            arr[curX][curY] = 1;
            dfs(curX, curY, cnt + 1, res * percent[i]);
            arr[curX][curY] = 0;
        }
    }
}
int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);
    cin >> n;

    for (int i = 0;i < 4;i++) {
        cin >> percent[i];
        percent[i] /= 100;
    }

    arr[50][50] = 1;//gk Ssibla

    dfs(50, 50, 0, 1);
    cout.precision(11);
    cout.fixed;
    cout << ans << "\n";

    return 0;
}