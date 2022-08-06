#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>

using namespace std;
#define MAX 25

struct coord {
    int x; int y;
};

int arr[MAX][MAX]; // 0은 빈칸. 1은 벽
int n, m, fuel;
int dirX[4] = { 0,0,1,-1 };
int dirY[4] = { -1,1,0,0 };
bool isLoopAvailable = true;

coord taxi;
vector<pair<coord, coord>> passenger;

vector<pair<int, int>> passengerVec; // 승객번호, 거리

bool comp(pair<int, int> a, pair<int, int> b) {
    // 바꿔야할 때, true. 그러면 뒤가 더 작으면 true
    // 1. 최단거리가 짧은 승객 
    // 2. 행 번호가 가장 작은 승객, 열 번호가 가장 작은 승객 이 먼저
    if (a.second <= b.second) {
        if (a.second == b.second) {
            // coord 비교 
            if (passenger[a.first].first.x <= passenger[b.first].first.x) {
                if (passenger[a.first].first.y <= passenger[b.first].first.y) {
                    return false;
                }
                return true;
            }
            return false;
        }
        return true;
    }
    return false;
}


int visit[MAX][MAX];

void step2() {
    // 1. array 에다가 승객 마킹 
    for (int i = 1;i <= passenger.size();i++) {
        arr[passenger[i - 1].first.x][passenger[i - 1].first.y] = i;
    }

    // 2. bfs 해서 승객이 어딨는지 찾기 
    queue<pair<int, int>> que;
    que.push({ taxi.x, taxi.y });
    memset(visit, 0, sizeof(visit));


    // 3. 승객 번호, 최단거리 세팅하기
    int cnt = 0;
    while (!que.empty()) {
        pair<int, int> cur = que.front(); que.pop();
        int curX = cur.first; int curY = cur.second;
        for (int dir = 0;dir < 4;dir++) {
            int dx = dirX[dir] + curX;
            int dy = dirY[dir] + curY;

            if (dx < 0 || dx >= n || dy < 0 || dy >= n) continue;
            if (arr[dx][dy] == -1) continue; // 벽이면 continue;

            que.push({ dx,dy });
            visit[dx][dy] = 1;

            if (arr[dx][dy] != 0) {
                // 사람이다! 
                // 여기에 있는 사람이 누군지 찾고, 
                // 승객 번호랑 최단거리를 저장한다. 
                for (int i = 1;i <= passenger.size();i++) {
                    if (passenger[i].first.x == dx && passenger[i].first.y == dy) {
                        passengerVec.push_back({ i, cnt });
                    }
                }
            }
            else {
                cnt++;
            }
        }
    }
}

void step3() {
    // 제일 가까운 승객 찾기 
    sort(passengerVec.begin(), passengerVec.end(), comp);


    // 목적지까지 이동
    pair<int, int> targetPassenger = passengerVec[0];

    // **** 승객 위치까지 연료 감소시키고 -> 확인하는 로직 필요함. 
    int tempFuel = targetPassenger.second;
    fuel -= tempFuel;
    if (tempFuel < 0) {
        isLoopAvailable = false;
        return;
    }

    coord destination = passenger[passengerVec[0].first].second;

    int vis[MAX][MAX];
    queue<pair<int, int>> que;
    que.push({ destination.x, destination.y });
    vis[destination.x][destination.y] = 1;

    int distanceCount = 0;

    while (!que.empty()) {
        pair<int, int> cur = que.front(); que.pop();
        int curX = cur.first;
        int curY = cur.second;

        for (int dir = 0;dir < 4;dir++) {
            int dx = curX + dirX[dir];
            int dy = curY + dirY[dir];

            if (dx < 0 || dx >= n || dy < 0 || dy >= n) continue;
            if (vis[dx][dy] != 0) continue; // 필요 X 

            // que.push
            que.push({ dx, dy });
            vis[dx][dy] = vis[curX][curY] + 1;

            if (dx == destination.x && dy == destination.y) {
                distanceCount = vis[dx][dy];
            }
        }
    }

    // 연료에서 빼기 => 
    fuel -= distanceCount;
    if (fuel > 0) {
        isLoopAvailable = false;
    }
    else {
        isLoopAvailable = true;
    }
}


int main() {

    // 1. input
    cin >> n >> m >> fuel; // n : map, m : passenger, fuel : init

    // 1 로 들어오는걸 -> -1 
    // array 에다가 1, 2, 3, 4 하면 됨. 
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            int a; cin >> a;
            if (a == 1) {
                arr[i][j] = -1;
            }
            else {
                arr[i][j] = a;
            }
        }
    }

    cin >> taxi.x >> taxi.y;

    for (int i = 0;i < m;i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        passenger[i].first.x = a;
        passenger[i].first.y = b;
        passenger[i].second.x = c;
        passenger[i].second.y = d;
    }

    while (1) {
        step2();

        step3();


        // check Person is in. 

        if (isLoopAvailable == false) {
            break;
        }
        else {
            fuel *= 2;
        }
    }

    if (isLoopAvailable == true) {
        cout << fuel << "\n";
    }
    else {
        cout << -1 << "\n";
    }
    // 3. 택시를 그 위치로 이동시키고, 연료 감소. 가는 길에  부족하면 break

    // 4. 거기서 목적지까지 bfs 로 이동, 연료 감소, 가는 길에 부족하면 break
    // 4-1. 제대로 도착시켰으면 *2 시키고 다음 loop

    // 5. 연료가 < 0 인지 체크, 사람들은 다 보냈는지 체크 

    return 0;

}