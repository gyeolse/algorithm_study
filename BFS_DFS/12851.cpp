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
    cnt[n] = 1; //경우의 수를 따져주기 위한 cnt배열. 인덱스에 접근하게 되는 경우가 1가지 이상일 경우 1이상의 값으로 설정됨

    while(!que.empty()){
        int cur = que.front(); que.pop();
        if(cur+1 < MAX) {
            //처음 방문한 경우
            if(visit[cur+1] == 0) {
                visit[cur+1] = 1; //visit 처리
                board[cur+1] = board[cur]+1; //해당 idx까지 걸리는 시간 처리
                cnt[cur+1] = cnt[cur]; //처음 방문한다 == 경우의 수가 그 cur까지 온 경우뿐이다 == 그러므로 cur+1이나 cur이나 경우의 수는 그대로다
                que.push(cur+1);
            }
            //걸린 시간이 같은 경우에 대한 예외처리
            else if(board[cur+1] == board[cur]+1) {
                cnt[cur+1] += cnt[cur]; //걸린 시간이 같은 경우는, visit 배열을 처리해줄 필요가 없다. 왜냐면 이미 방문했을거니까. 그리고, board도 처리해줄 필요가 없다. 왜냐면 이미 board도 값이 세팅 되어있을 거니까 
                //여기서 해줄 것은 cnt 배열에 cur+1까지 오는 방법이 더 있다는것을 넘겨주어야하고, cur까지 온 경우의 수를 더해주면 된다. 
                // 예를 들어서, 1-> 1*2 나, 1 -> 1+1이나 같잖아.여기서 접근했을 때, 1*2를 통해서 이미 visit, board가 업데이트가 되었다고 가정하자
                // 그러면, cnt[1+1] +=cnt[1] 이 되겠지 그래서 2가 될 것임. 이런 식으로, cnt[cur] 만큼 오는데 걸렸던 경우의 수들을 cnt[cur+1]에 더해주는 것을 말하고,
                // 이걸 cur+1, cur-1, cur*2에서 다 case를 만들어주어서, 예외 처리해주면 됨
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