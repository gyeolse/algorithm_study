#include <bits/stdc++.h>
using namespace std;

int n;
int arr[11];
int ans = 987654321;
bool chk[11];

vector<int> vec[11];
int isVisited[11];

void input() {
    cin >> n;

    for (int i = 1;i <= n;i++) {
        int x; cin >> x;
        arr[i] = x;
    }

    for (int i = 1;i <= n;i++) {
        int a; cin >> a;
        for (int j = 0;j < a;j++) {
            int b; cin >> b;
            vec[i].push_back(b);
            vec[b].push_back(i);
        }
    }

}

bool checkConnect(vector<int> v, bool b) {

    memset(isVisited, false, sizeof(isVisited));

    //연결되어 있는지 확인 -> bfs
    queue<int> q;
    q.push(v[0]);
    isVisited[v[0]] = true;
    int cnt = 1;

    while (!q.empty()) {
        int cur = q.front(); q.pop();

        for (int i = 1;i <= n;i++) {
            if (vec[cur][i] == true && chk[i] == b && isVisited[i] == false) {
                isVisited[i] = true;
                cnt++;
                q.push(i);
            }
        }
    }
    if (v.size() == cnt) return true;
    return false;
}

bool check() {
    //선거구에 포함된 구역 개수 확인

    //선거구에 포함된 구역끼리 연결되어 있는지 확인 

    vector<int> a, b;
    for (int i = 1;i <= n;i++) {
        if (chk[i] == 1) a.push_back(i);
        else b.push_back(i);
    }

    if (a.size() == 0 || b.size() == 0) return false;

    bool isAConnect = checkConnect(a, true);
    if (isAConnect == false) return false;

    bool isBConnect = checkConnect(b, false);
    if (isBConnect == false) return false;

    return true;
}

void dfs(int idx, int cnt) {
    if (cnt >= 1) { //cnt가 1보다 큰 경우들은 모두, 체크해주어야할 것.
        //선거구의 조건들을 체크. 
        if (check() == true) {
            int aRes = 0; int bRes = 0;

            for (int i = 1;i <= n;i++) {
                if (chk[i] == true) aRes += arr[i];
                else bRes += arr[i];
            }
            ans = min(abs(aRes - bRes), ans);
        }
    }

    //선거구 선택 -> 재귀 
    for (int i = idx;i <= n;i++) {
        if (chk[i] == 1) continue;
        chk[i] = true;
        dfs(i, cnt + 1);
        chk[i] = false;
    }
}

void print() {
    if (ans == 987654321) {
        cout << -1 << endl;
    }
    else {
        cout << ans << '\n';
    }
}


int main() {
    //1. 입력
    input();

    //2. 조합 구현 -> dfs
    dfs(1, 0); //idx, cnt

    //3. 값 출력
    print();
}
