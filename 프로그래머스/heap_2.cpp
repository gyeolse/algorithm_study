#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> jobs) {
    sort(jobs.begin(),jobs.end());
    int answer = 0; int j = 0; int time = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    //1. 대기열 없고, 우선순위 큐 빌 때 까지 반복
    while(j< jobs.size() || !pq.empty()) {
        //2. 들어올 대기열이 아직 있고, 들어올 대기열이 현재 시간보다 작다면
        if(jobs.size() > j  && time >= jobs[j][0]) {
            //우선 순위큐에 추가한다. 
            pq.push({jobs[j][1], jobs[j][0]});
            //인덱스 증가 
            j++;
            //같은 시간 대에 다른 작업이 있는지 확인 
            continue;
        }
        
        //큐 처리
        if(!pq.empty()) {
            time += pq.top().first; //걸리는 시간만큼 추가
            
            //현재 시간 - 들어온 시간 
            answer += time - pq.top().second;
            pq.pop();
        }
        else { //다음 작업시간으로 넘긴다. 
            time = jobs[j][0];
        }
        
    }
    
    return answer/jobs.size();
}