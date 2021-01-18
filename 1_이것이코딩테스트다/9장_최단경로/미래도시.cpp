#include <bits/stdc++.h>
using namespace std;
#define MAX 200
#define INF 987654321

int n, m;
int graph[MAX][MAX]; //

int main() {
    cin >> n >> m;

    //1. INF, 자기자신노드 0으로 초기화
    for (int i = 0;i < MAX;i++) {
        fill_n(graph[i], MAX, INF);
    }
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            if (i == j) {
                graph[i][j] = 0;
            }
        }
    }
    //2. 입력
    for (int i = 0;i < m;i++) {
        int a, b;
        cin >> a >> b;
        graph[a][b] = 1;
        graph[b][a] = 1; //양방향
    }

    //3. 알고리즘 시행
    for(int k=1;k<=n;k++){
        for(int a=1;a<=n;a++){
            for(int b=1;b<=n;b++){
                graph[a][b] = min(graph[a][b],graph[a][k]+graph[k][b]);
            }
        }
    }

    //4. k.x
    int k,x;
    cin>>x>>k; //하... 바본가;;;
    int res=0;
    res = graph[1][k] + graph[k][x];
    if(res >= INF) {
        cout<<"-1"<<endl;
    } else {
        cout<<res<<endl;
    }

    return 0;

}