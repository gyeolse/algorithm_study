#include <bits/stdc++.h>
using namespace std;

#define MAX 20001
#define INF 987654321

int n, m, start;
vector<pair<int,int>> graph[MAX];
int dist[MAX];

void solve_ (int start) {
    //1. priority queue 선언. {비용, 노드}
    priority_queue<pair<int,int>> pq;

    //2. 실행
    pq.push({0,start});
    dist[start] = 0;

    //3. pq가 빌 때까지 반복
    while(!pq.empty()) {
        pair<int,int> cur = pq.top(); pq.pop();
        int curDist = -cur.first;
        int curNode = cur.second;

        //4. 전에 처리한적 있는지 비교 
        if(dist[curNode] < curDist ) continue;

        //5. 현 노드의 사이즈만큼 돌면서, 비용 비교 
        for(int i=0;i<graph[curNode].size();i++){
            int cost = curDist + graph[curNode][i].second;
            if(cost < dist[graph[curNode][i].first]) {
                dist[graph[curNode][i].first] = cost;
                pq.push({-cost,graph[curNode][i].first});
            }
        }        
    }

}


int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);
    cin>>n>>m>>start;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        graph[a].push_back({b,c}); //정점, 연결된정점, 가중치
    }

    //INF로 초기화
    fill_n(dist,MAX,INF);

    //다익스트라 알고리즘 실행
    solve_(start);

    //출력. 시작점은 빼고
    for(int i=1;i<=n;i++){
        if(dist[i] == INF ) {
            cout<<"INF"<<"\n";
        }
        else {
            cout<<dist[i]<<"\n";
        }
    }
    return 0;;
}