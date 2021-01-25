#include <bits/stdc++.h>
using namespace std;
#define MAX 201
int n,m;
int parent[MAX];
int board[MAX][MAX];

queue<pair<int,int>> que;

int findParent(int x) {
    if(x==parent[x]) return x;
    return parent[x] = findParent(parent[x]);
}

void unionParent(int a, int b) {
    a = findParent(a);
    b = findParent(b);
    if(a>b) parent[a] = b;
    else parent[b] = a;
}

int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);
    cin>>n>>m;

    //0. parent 테이블 초기화 : 왜 계속 까먹을까 
    for(int i=1;i<=n;i++) {
        parent[i] = i;
    }
    //1. 입력과 동시에, i>j 이고, 연결된 경우에만 que에 push
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) {
            cin>>board[i][j];
            if(i>j && board[i][j]==1) que.push({i,j});
        }
    }

    while(!que.empty()) {
        pair<int,int> cur = que.front(); que.pop();
        //2. union-find 수행 
        int a = cur.first; int b = cur.second;
        int aParent = findParent(a); int bParent = findParent(b);
        unionParent(a,b);
    }

    //3. 도시들을 입력받는다. 
    vector<int> cities;
    for(int i=0;i<m;i++) {
        int x; cin>>x; cities.push_back(x);
    }

    //4. 가능/불가능 체크
    int chkParent = findParent(cities[0]);
    // cout<<chkParent<<" ";
    bool isAvailable = true;
    for(int i=1;i<cities.size();i++) {
        // cout<<findParent(cities[i])<<" ";
        if(chkParent != findParent(cities[i])){
            isAvailable = false;
            break;
        }
    }
    
    //5. 출력
    if(isAvailable) cout<<"YES"<<"\n";
    else cout<<"NO"<<"\n";

    return 0;    
}