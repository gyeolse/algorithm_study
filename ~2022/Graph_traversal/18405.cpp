#include <bits/stdc++.h>
using namespace std;
#define MAX 201
int n,k,s,x,y; //자연수, 최대바이러스번호, s초, x,y에 있는 바이러스
int board[MAX][MAX];
int dirX[4] = {0,1,0,-1};
int dirY[4] = {1,0,-1,0};

//시간초과 난 원인 : 큐에 해당 노드에 대한 정보만 넣고, push하지 않도록 해둠. 
// 떄문에, 많은 노드들이 존재할 경우, 2중 포문을 돌면서 다 넣어주게 되는데, 
// 이것때문에 터진것 같다.
// 방법 : 아예 큐에 바이러스에 대한 정보를 다 넣기.
int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);
    cin>>n>>k;

    vector<pair<int,pair<int,pair<int,int>>>> vec; //바이러스 종류, 시간, x,y

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++){
            cin>>board[i][j];
            if(board[i][j] != 0) {
                vec.push_back({board[i][j],{0,{i,j}}});
            }
        }
    }
    cin>>s>>x>>y;

    sort(vec.begin(),vec.end());

    queue<pair<int,pair<int,pair<int,int>>>> que; //바이러스 종류, 시간, x,y
    for(int i=0;i<vec.size();i++){
        que.push({vec[i].first,{vec[i].second.first,{vec[i].second.second.first,vec[i].second.second.second}}});
    }

    while(!que.empty()) {
        auto cur = que.front(); que.pop();
        // cout<<endl;
        // for(int i=0;i<n;i++) {
        //     for(int j=0;j<n;j++){
        //         cout<<board[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;

        if(cur.second.first == s) break;
        for(int dir=0;dir<4;dir++) {
            int curX = cur.second.second.first + dirX[dir];
            int curY = cur.second.second.second + dirY[dir];
            if(curX>=n || curY>=n || curX < 0 || curY < 0 ) continue;
            if(board[curX][curY] == 0 ) {
                //1. 번호 처리
                board[curX][curY] = cur.first;
                //2. push
                int t_ = cur.second.first+1;
                que.push({cur.first,{t_,{curX,curY}}});
            }
        }
    }

    //s초 후의 상황. x,y에 바이러스 존재하는지 안하는지
    cout<<board[x-1][y-1]<<"\n";
    return 0;
}
