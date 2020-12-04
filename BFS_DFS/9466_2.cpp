#include <bits/stdc++.h>
using namespace std;

#define MAX 100001

int T; //testcase
int n; //student num
int student[MAX]; //팀 되길 희망하는 친구 번호
int visit[MAX]; //방문여부
int first[MAX]; //처음 방문하는 번호를 저장

int dfs(int start, int current, int cnt){
    if(visit[current]){
        //cycle인 경우
        if(first[current] != start ) return 0;
        return cnt-visit[current];
    }

    first[current] = start;
    visit[current] = cnt;

    return dfs(start,student[current],cnt+1);
}
int main(){
    cin>>T;
    while(T--) {
        int ans=0;
        memset(student,0,sizeof(student)); //초기화
        memset(visit,0,sizeof(visit)); //초기화
        cin>>n;
        for(int i=1;i<=n;i++){ //1부터
            cin>>student[i];
        }

        for(int i=1;i<=n;i++){
            if(!visit[i]){
                ans+=dfs(i,i,1); //시작점, 현재점, 카운트
            }
        }

        cout<<(n-ans)<<"\n";
    }
    return 0;
}