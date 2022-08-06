#include <bits/stdc++.h>
using namespace std;
#define MAX 100001
#define INF 987654321

int n, m, start;
vector<pair<int,int>> graph[MAX]; // curNode, nextNode, dist
int dist[MAX];

void dijkstra(int start) {

    //1. pq 선언
    priority_queue<pair<int,int>> pq;

    //2. pq에 push (앞이 cost, 뒤가 node)
    pq.push({0,start});
    dist[start] = 0;

    while(!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        int curDist = -cur.first;
        int curNode = cur.second;

        //3. 이미 처리한 적 있으면 continue
        if(curDist > dist[curNode]) continue;

        for(int i=0;i<graph[curNode].size();i++) {
            int cost = graph[curNode][i].second + curDist;
            //4. 현 노드에 연결된 노드들 탐색 -> 현재 cost보다 더 크면 업데이트 후, push 
            if(cost < dist[graph[curNode][i].first]) {
                dist[graph[curNode][i].first] = cost;
                pq.push({-cost, graph[curNode][i].first});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m >> start;

    for (int i = 0;i < m;i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({ b,c });
    }

    fill_n(dist,MAX,INF);

    dijkstra(start);

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