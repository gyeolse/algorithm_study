#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int,vector<int>,greater<int>> pq;
    
    for(int i=0;i<scoville.size();i++) {
        pq.push(scoville[i]);
    }
    
    int cnt = 0;
    
    while(pq.top() < K && pq.size() > 1) {
        cnt++;
        
        //1. 제일 앞의 원소를 확인 및 비교
        int first = pq.top(); pq.pop();
        int second = pq.top(); pq.pop();
        
        //2. 넣는 과정만 한다
        pq.push((first + (second*2)));
    }
    
    //cnt가 0일 때에는 -1이고, 그 외에는 cnt 값이 된다.
    if(pq.top() < K) {
        answer = -1;
    } else {
        answer = cnt;
    }
    return answer;
}