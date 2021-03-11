#include <bits/stdc++.h>
#define MAX 11

using namespace std;
int n, res = 987654321;
int person[MAX]; //인구수 저장용

bool graph[MAX][MAX]; //graph 저장용
bool sel[MAX]; //조합 때 사용
bool chk[MAX]; //방문 확인용

bool isConnected(vector<int> vec, bool b) {
    // bfs 구현 
    memset(chk,false,sizeof(chk));
    queue<int> que;
    que.push(vec[0]); //하나만 넣어도 됨 
    // 방문설정 왜 안함?
    chk[vec[0]] = true;
    int cnt = 1; //갯수 카운트

    while(!que.empty()) {
        int cur = que.front(); que.pop();
        for(int i=1;i<=n;i++) {
            // 1. 현재 구역, 탐색 구역이 연결 유무
            if(graph[cur][i] != true) continue;
            // 2. 탐색 구역이 선거구에 맞는지 확인
            if(sel[i] != b) continue;
            // 3. 아직 방문하지 않은 구역인지 확인 
            if(chk[i] == true) continue;

            chk[i] = true;
            cnt++;
            que.push(i);
        }
    }

    //bfs cnt 값과, vecotr 사이즈가 같으면 OK
    if(vec.size() == cnt) return true;
    return false;
}

bool check() {
    vector<int> one_;
    vector<int> two_; 
    
    for(int i=1;i<=n;i++){
        if(sel[i] == true ) one_.push_back(i);
        else two_.push_back(i);
    }

    //1. 둘 중 하나라도 사이즈가 0이라면 해당사항 없음
    if(one_.size() == 0 || two_.size() == 0 ) return false;

    //2. 연결 확인
    if(!isConnected(one_,true)) {
        return false;
    }
    if(!isConnected(two_,false)) {
        return false;
    }
    return true;
}

void calculate() {
    int oneRes = 0; int twoRes = 0;

    for(int i=1;i<=n;i++) {
        if(sel[i] == true) oneRes += person[i];
        else twoRes += person[i];
    }

    res = min(abs(oneRes-twoRes), res);
}

void dfs(int idx, int cnt) {
    // 1이상이면 무조건 체크해주도록 하기. 대신, return은 하면 안된다.
    if(cnt >=1) {
        // 선택한 수 들이 조건을 충족시키는지 확인
        if(check()) {
            // 차이 계산
            calculate();
        }
    }

    for(int i=idx;i<=n;i++) {
        if(sel[i] == true) continue;
        sel[i] = true;
        dfs(i,cnt+1);
        sel[i] = false;
    }
}

int main() {
    //1. input
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> person[i];
    }

    for (int i = 1;i <= n;i++) {
        int x; cin >> x;
        for (int j = 0;j < x;j++) {
            int tmp; cin >> tmp;
            graph[i][tmp] = true;
            graph[tmp][i] = true;
        }
    }

    //2. 조합 구현
    dfs(1,0); //처음이 1,0

    if(res == 987654321) {
        cout<<-1<<"\n";
    }
    else {
        cout<<res<<"\n";
    }
    return 0;
}