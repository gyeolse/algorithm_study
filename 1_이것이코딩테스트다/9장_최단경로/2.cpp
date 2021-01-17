#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define MAX 100001

int n,m,start; //노드, 간선, 노드번호

vector<pair<int,int>> graph[MAX]; 
int dist[MAX];

void dijk(int start) { 
    //우선순위 큐 사용
    priority_queue<pair<int,int>> pq;

    //시작점 처리
    pq.push({0,start});
    dist[start] = 0;

    while(!pq.empty()) {
        //가장 최단거리가 짧은 노드에 대한 정보 꺼내기
        auto cur = pq.top(); pq.pop();
        int curDist = -cur.first;
        int now = cur.second;

        //현재 노드가 이미 처리되었다면 무시
        if(dist[now] < curDist ) continue;

        //현재 노드와 연결된 인접한 노드들을 확인
        for(int i=0;i<graph[now].size();i++){
            int cost = curDist + graph[now][i].second;
            //현재 노드를 거쳐서, 다른 노드로 이동하는 것이 더 짧은 경우
            if(cost<dist[graph[now][i].first]) {
                dist[graph[now][i].first] = cost;
                pq.push({-cost,graph[now][i].first});

            }
        }
    }

}
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin>>n>>m>>start;

    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        graph[a].push_back({b,c});
    }

    fill_n(dist,MAX,INF);

    dijk(start);

    for(int i=1;i<=n;i++) {
        if(dist[i]==INF) {
            cout<<"INF"<<"\n";
        }
        else {
            cout<<dist[i]<<"\n";
        }
    }
    return 0;
}