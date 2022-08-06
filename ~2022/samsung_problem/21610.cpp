#include <bits/stdc++.h>
using namespace std;
#define MAX 55

int n, m, ans;
int MAP[MAX][MAX];
bool cloudMap[MAX][MAX];
vector<pair<int, int>> cloud;
vector<pair<int, int>> cmd;

int dx[] = { 0,0,-1,-1,-1,0,1,1,1 };
int dy[] = { 0,-1,-1,0,1,1,1,0,-1 };

void input() {
    cin >> n >> m;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            cin >> MAP[i][j];
        }
    }

    for (int i = 0;i < m;i++) {
        int d, s;
        cin >> d >> s;
        cmd.push_back({ d,s });
    }
}

void initCloud() {
    cloud.push_back({ n - 2, 0 });
    cloud.push_back({ n - 2, 1 });
    cloud.push_back({ n - 1, 0 });
    cloud.push_back({ n - 1,1 });
    cloudMap[n - 2][0] = true;
    cloudMap[n - 2][1] = true;
    cloudMap[n - 2][0] = true;
    cloudMap[n - 2][1] = true;
}

int makeRange(int x) {
    if (x < 0) return n - 1;
    if (x >= n) return 0;
    return x;
}

void moveCloud(int i) {
    int dir = cmd[i].first;
    int cnt = cmd[i].second;
    memset(cloudMap, false, sizeof(cloudMap));
    for (int i = 0;i < cloud.size();i++) {
        int x = cloud[i].first;
        int y = cloud[i].second;
        int nx = x;
        int ny = y;

        for (int j = 0;j < cnt;j++) {
            nx += dx[dir];
            ny += dy[dir];
            nx = makeRange(nx);
            ny = makeRange(ny);
        }
        cloud[i].first = nx;
        cloud[i].second = ny;
    }

    for (int i = 0;i < cloud.size();i++) {
        int x = cloud[i].first;
        int y = cloud[i].second;
        cloudMap[x][y] = true;
    }
}

void makeRain() {
    for (int i = 0;i < cloud.size();i++) {
        int x = cloud[i].first;
        int y = cloud[i].second;
        MAP[x][y]++;
    }
}

void waterBug() {
    for (int i = 0;i < cloud.size();i++) {
        int x = cloud[i].first;
        int y = cloud[i].second;
        int cnt = 0;
        for (int j = 0;j <= 8;j++) {
            int nx = x + dx[j];
            int ny = y + dy[j];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (MAP[nx][ny] >= 1) cnt++;
        }
        MAP[x][y] += cnt;
    }
}

void deleteCloud() {
    cloud.clear();
}

void makeCloud() {
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            if (cloudMap[i][j] == true) continue;
            if (MAP[i][j] < 2) continue;
            MAP[i][j] -= 2;
            cloud.push_back({ i,j });
        }
    }

    memset(cloudMap, false, sizeof(cloudMap));
    for (int i = 0;i < cloud.size();i++) {
        int x = cloud[i].first;
        int y = cloud[i].second;
        cloudMap[x][y] = true;
    }
}

int main() {

    input();
    initCloud();

    for (int i = 0;i < m;i++) {
        moveCloud(i);
        makeRain();
        waterBug();
        deleteCloud();
        makeCloud();
    }


    return 0;
}