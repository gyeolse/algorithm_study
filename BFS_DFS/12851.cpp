#include <bits/stdc++.h>
using namespace std;
#define MAX 100001
int board[MAX];
int cnt[MAX];
int visit[MAX];
int n,k;


int main(){
    cin>>n>>k;
    queue<int> que;
    que.push(n);
    visit[n] = 1;
    board[n] = 0; //0으로 시작
    cnt[n] = 1;

    while(!que.empty()){
        int cur = que.front(); que.pop();
        if(cur+1 < MAX) {
            //처음 방문한 경우
            if(visit[cur+1] == 0) {
                visit[cur+1] = 1;
                board[cur+1] = board[cur]+1;
                cnt[cur+1] = cnt[cur];
                que.push(cur+1);
            }
            //걸린 시간이 같은 경우에 대한 예외처리
            else if(board[cur+1] == board[cur]+1) {
                cnt[cur+1] += cnt[cur];
            }
        }
        if(cur*2 < MAX) {
            //처음 방문한 경우
            if(visit[cur*2] == 0) {
                visit[cur*2] = 1;
                board[cur*2] = board[cur]+1;
                cnt[cur*2] = cnt[cur];
                que.push(cur*2);
            }
            //걸린 시간이 같은 경우에 대한 예외처리
            else if(board[cur*2] == board[cur]+1) {
                cnt[cur*2] += cnt[cur];
            }
        }
        if(cur-1 >= 0) {
            //처음 방문한 경우
            if(visit[cur-1] == 0) {
                visit[cur-1] = 1;
                board[cur-1] = board[cur]+1;
                cnt[cur-1] = cnt[cur];
                que.push(cur-1);
            }
            //걸린 시간이 같은 경우에 대한 예외처리
            else if(board[cur-1] == board[cur]+1) {
                cnt[cur-1] += cnt[cur];
            }
        }
    }

    cout<<board[k]<<"\n";
    cout<<cnt[k]<<"\n";
    return 0;
}