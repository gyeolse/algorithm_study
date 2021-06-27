#include <bits/stdc++.h>
#define MAX 
using namespace std;
int n, m, h;
int chk[30][30];
int res = 987654321;

// 사다리 돌기 하며, 조건 만족하는지 확인
bool game() {
    // 모든 세로선에서 진행
    for(int i=1;i<=n;i++) {
        int cur = i;
        for(int j=1;j<=h;j++){
            if(chk[cur][j] == true) cur +=1;
            else if(chk[cur-1][j] == true) cur-=1;
        }
        if(cur != i ) return false;
    }
    return true;
}

void func(int idx, int cnt) {
    //1. cnt가 3보다 클 경우에는 return
    if(cnt > 3) return; 

    //2. 매번 사다리를 타야함 
    if(game()) {
        res = min(res, cnt);
        return;
    }

    //3. 그 외에 완전 탐색 돌리기 (사다리 조작)
    for(int i=idx;i<=h;i++) {
        for(int j=1;j<=n;j++) {
            //4. 
            if(chk[j][i] == true) continue;
            if(chk[j-1][i] == true) continue;
            if(chk[j+1][i] == true) continue;
            chk[j][i] = true;
            func(i,cnt+1);
            chk[j][i] = false;
        }
    }
}
int main() {
    //1. 입력
    //세로선의 갯수, 가로선의 갯수, 세로선마다 가로선을 놓을 수 있는 위치의 개수    
    cin >> n >> m >> h; 

    for(int i=0;i<m;i++){
        int a; int b; //b, b+1 세로선을 a번 점선 위치에 배정
        cin>>a>>b;
        chk[b][a] = 1;
    }

    //2. 문제 풀이 
    func(1,0); //1번 세로줄부터 시작

    if(res == 987654321) cout<<-1<<"\n";
    else cout<<res<<"\n";
    return 0;
}