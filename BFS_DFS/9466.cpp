#include <bits/stdc++.h>
using namespace std;

//https://lmcoa15.tistory.com/51
//https://transferhwang.tistory.com/277

int T, n; 
int student[100001]; //학생이 가리키는 다른 학생의 번호를 저장
int first[100001]; //처음으로 dfs 시작하는 번호를 저장
int visit[100001]; //방문 유무 및 횟수를 저장

int dfs(int start, int now, int cnt){
    //방문했던 학생인 경우
    if(visit[now]){
        //이전에 사이클이 생성된 경우
        if(first[now] != start) return 0;
        return cnt-visit[now];
    }
    first[now] = start;
    visit[now] = cnt;
    return dfs(start,student[now],cnt+1); //시작번호, 다음번호, 방문횟수
}
int main(){
    cin>>T;
    while(T--){
        memset(first,0,sizeof(first));
        memset(visit,0,sizeof(visit));
        int answer=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>student[i];
        }

        for(int i=1;i<=n;i++){
            if(!visit[i]){
                answer+=dfs(i,i,1); //시작번호, 현재번호, 방문횟수
            }
        }

        cout<<n-answer<<"\n";
    }
    return 0;
}