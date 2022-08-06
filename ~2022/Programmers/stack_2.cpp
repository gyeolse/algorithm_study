#include <bits/stdc++.h>
using namespace std;

struct work {
    int one; //우선순위
    int two; //진도
    int three; //속도
    int four; //day
};

bool comp(work a, work b) {
    return a.one < b.one;
}

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    queue<work> que; //우선순위, 진도, 속도, day
    for(int i=0;i<progresses.size();i++) {
        work tempWork;
        tempWork.one = i;
        tempWork.two = progresses[i];
        tempWork.three = speeds[i];
        tempWork.four = 0;
        que.push(tempWork);
    }
    
    vector<work> vec; //우선순위, 진도, 속도, 날짜
    
    while(!que.empty()) {
        auto cur = que.front(); que.pop();
        if(cur.two < 100) { //100을 못채웠을 때
            cur.two += cur.three;
            cur.four += 1;
            que.push(cur);
        }
        else { //100 이상일 때
            //벡터에 넣어줌
            vec.push_back(cur);
        }
    }
    
    //우선순위 별로 정렬
    sort(vec.begin(),vec.end(),comp);
    
    for(int i=0;i<vec.size();i++) {
        // cout<<vec[i].one<<" "<<vec[i].two<<" "<<vec[i].three<<" "<<vec[i].four<<endl;
        que.push(vec[i]);
    }
    
    //배포작업 시작 
    // 1) 이번 배열에서 보낼 수 있는 애들을 체크.
    //    다음 배열에서 하나라도, 현재 날짜보다 긴 애들이 있으면 지금 배포 불가. 바로 배포해버리고, pop
    //    cnt 세고, 바로 answer에다가 push_back

    while(!que.empty()) {
        int dayCount = 1; //무조건 하나는 배포하게 됨.
        auto cur = que.front(); que.pop();
        
        for(int i=cur.one+1;i<vec.size();i++) {
            if(cur.four < vec[i].four) { //만약, 뒤의 일이 현재 day보다 크다면,
                break;
            }
            else { //뒤의 일이 현재 day 보다 작은 경우
                // cout<<"호출 확인"<<dayCount<<endl;
                if(que.size() != 0) {
                    dayCount++;
                    que.pop();
                }
            }
        }
        answer.push_back(dayCount);        
    }
    
    return answer;
}