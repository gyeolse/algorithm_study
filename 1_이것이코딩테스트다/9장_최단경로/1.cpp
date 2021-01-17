//다익스트라 -- 쉽게 구현
#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

//노드의 개수, 간선의 개수, 시작점
int n,m,start; 

//각 노드에 연결된 노드에 대한 정보를 담는 배열
vector<pair<int,int>> graph[100001];

//방문 체크 배열
bool visited[100001];

//최단거리 테이블
int dist[100001];

// 방문하지 않은 노드 중에서, 최단거리가 가장 짧은 노드 번호 반환
int SmallNode() {
    int min_value = INF;
    int idx = 0; //가장 최단거리가 짧은 노드
    for(int i=0;i<n;i++){
        if(dist[i] < min_value && visited[i]==false) {
            min_value = dist[i];
            idx = i;
        }
    }
    return idx;
}

void dijkstra(int start) {
    //시작 노드 초기화
    dist[start] = 0;
    visited[start] = true; //방문

    for(int j=0;j<graph[start].size();j++) { //연결된 수 만큼
        dist[graph[start][j].first] = graph[start][j].second; //비용 세팅
    }

    //시작 노드 제외한 전체 n-1개의 노드에 반복
    for(int i=0;i<n-1;i++){
        //최단 거리가 가장 짧은 노드를 꺼내서, 방문 처리
        int now = SmallNode();
        visited[now] = true;
        for(int j=0;j<graph[now].size();j++) {
            int cost = dist[now] + graph[now][j].second;
            //현재 노드를 거쳐서 다른 노드로 이동하는 거리가 더 짧다면 변경
            if(cost < dist[graph[now][j].first]) {
                dist[graph[now][j].first] = cost;
            }
        }
    }
}

int main() {
    cin>>n>>m>>start; // 노드, 간선, 시작점

    //간선 정보 입력
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        //a번 노드에서 b번 노드로 가는 비용은 c
        graph[a].push_back({b,c});
    }

    // memset(dist, 100001, INF); //무한으로 초기화
    fill_n(dist, 100001, INF);
    //다익스트라 알고리즘 실행
    dijkstra(start);

    //모든 노드로 가기 위한 최단 거리 출력
    for(int i=1;i<=n;i++){
        if(dist[i]==INF) {
            cout<<"INF"<<"\n";
        }
        else {
            cout<<dist[i]<<"\n";
        }
    }

    return 0;
}
