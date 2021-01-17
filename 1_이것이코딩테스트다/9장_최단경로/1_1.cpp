#include <bits/stdc++.h>
using namespace std;

#define MAX 100001
#define INF 987654321

//노드의 갯수, 간선의 갯수, 시작점
int n,m,start;

vector<pair<int,int>> graph[MAX]; //각 노드에 연결된 정보에 대한 배열
bool visited[MAX]; //방문 체크 배열
int dist[MAX]; //최단거리 테이블

//방문하지 않은 노드들 중에서, 가장 최단 경로가 짧은 것을 고름
//-> 한~번도 방문하지 않은 노드들은 어차피 경로가 INF임. 그러므로, 하나라도, 연결되어있는 놈들이
//-> 값을 가지고 있을 것.
int smallNode () {
    int min_value = INF;
    int idx=0;
    for(int i=0;i<n;i++){
        if(dist[i] < min_value && visited[i]==false) {
            min_value = dist[i];
            idx=i;
        }
    }
    return idx;
}


void dijk(int start) {
    //방문 체크, 시작노드는 0으로 초기화
    dist[start] = 0;
    visited[start] = true; //방문

    for(int j=0;j<graph[start].size();j++) { //start 점과 연결된 수만큼
        dist[graph[start][j].first] = graph[start][j].second; //맨 처음일 것임. 비용 세팅
    }

    //시작 노드 제외한 n-1개에서 반복이 이루어짐
    for(int i=0;i<n-1;i++){
        //최단 거리가 가장 짧은 노드를 꺼내고, 방문 처리를 해주어야함.
        int now = smallNode();
        visited[now] = true;

        //최단경로를 비교한 후, 새로고침해주어야 함.
        //-> now노드와 연결된 친구들이 현재 노드를 통해, 다른 노드로 이동하는 거리가
        //-> 더 짧다면 변경
        for(int j=0;j<graph[now].size();j++){
            int cost = dist[now] + graph[now][j].second; //비용
            if(cost<dist[graph[now][j].first]) {
                //현재 노드를 거쳐 해당 노드로 이동하게 되는 거리가 더 짧다면
                dist[graph[now][j].first] = cost;
            }
        }
    }
}

int main() {
    cin>>n>>m>>start; 

    for(int i=0;i<n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        graph[a].push_back({b,c});
    }

    //모두 무한으로 초기화
    // memset(dist,INF,sizeof(dist)); -> 큰 수를 넣으려고 할 때에는 fill_n을 쓰도록 하자 
    fill_n(dist, MAX, INF);

    //다익스트라 start
    dijk(start);

    //최단 거리 출력
    for(int i=1;i<=n;i++){
        if(dist[i]==INF){
            cout<<"INF"<<"\n";
        }
        else{
            cout<<dist[i]<<"\n";
        }
    }
    return 0;
}