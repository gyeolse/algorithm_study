#include <bits/stdc++.h>
using namespace std;

#define INF 987654321
#define MAX 501

int n,m;
int graph[MAX][MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin>>n>>m;
    
    //1. 최단거리 테이블 모두 무한으로 초기화 시키기 
    for(int i=0;i<MAX;i++){
        // fill(graph[i],graph[i]+501,INF);
        fill_n(graph[i],MAX,INF);
    }

    //2. 자기 자신으로 가는 비용은 모두 0으로 초기화
    for(int a=1;a<=n;a++){ //1로 해두는게 코딩할 떄 더 편할 것 같다
        for(int b=1;b<=n;b++){
            if(a==b) graph[a][b] = 0;
        }
    }

    //3. 각 간선에 대한 정보를 입력받고, 그 값으로 초기화함. 
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        int v_ = graph[a][b];
        graph[a][b] = min(c,graph[a][b]);
    }

    //4. 플로이드 워셜 알고리즘 진행 -> 3중 for
    for(int i=1;i<=n;i++) {
        for(int a=1;a<=n;a++){
            for(int b=1;b<=n;b++){
                graph[a][b] = min(graph[a][b],graph[a][i]+graph[i][b]);
            }
        }
    }

    //5. 출력
    for(int a=1;a<=n;a++) {
        for(int b=1;b<=n;b++){
            if(graph[a][b]==INF) {
                cout<<"0"<<" ";
            }
            else {
                cout<<graph[a][b]<<" ";
            }
        }
        cout<<"\n";
    }


    return 0;
}