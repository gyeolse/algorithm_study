#include <iostream>
#include <queue>

#define MAX_SIZE 220

using namespace std;

int start_, end_, cnt, ans;
int n, k;
int belt[MAX_SIZE];
bool visit[MAX_SIZE];
queue<int> robot;

void move_belt() {
    start_--;
    end_--;
    if (start_ < 1) start_ = 2 * n;
    if (end_ < 1) end_ = 2 * n;
}

void move_robot() {
    int sz = robot.size();

    for (int i = 0;i < sz;i++) {
        // 현재 위치에서 나올거니까
        int cur = robot.front();
        visit[cur] = false;
        robot.pop();

        if (cur == end_) continue; // 내보내기

        int next = cur + 1;
        if (next > 2 * n) next = 1;
        if (belt[next] >= 1 && visit[next] == false) {
            belt[next]--; // 내구도
            if (belt[next] == 0) cnt++; // 0 카운트
            if (next == end_) continue; // 내보내기
            visit[next] = true;
            robot.push(next);
        }
        else { // 이동할 수 없다면 가만히 있는다. 
            visit[cur] = true;
            robot.push(cur);
        }
    }
}

void make_robot() {
    if (visit[start_] == false && belt[start_] >= 1) {
        visit[start_] = true;
        belt[start_]--;
        robot.push(start_);

        if (belt[start_] == 0) cnt++;
    }
}

int main() {
    // input
    cin >> n >> k;
    for (int i = 1;i <= n * 2;i++) {
        cin >> belt[i];
    }

    // solution
    start_ = 1;
    end_ = n;

    while (cnt < k) {
        ans++;
        move_belt();
        move_robot();
        make_robot();
    }

    cout << ans << "\n";
    return 0;
}