#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> operations) {
    queue<pair<char,int>> cmd;    
    priority_queue<int,vector<int>,less<int>> minHeap;
    priority_queue<int,vector<int>,greater<int>> maxHeap;

    for(int i=0;i<operations.size();i++) {
        char c_ = operations[i][0];
        int temp = stoi(operations[i].substr(2, operations[i].size()-2));
        cmd.push({c_,temp});
    }
    
    while(!cmd.empty()) {
        auto cur = cmd.front(); cmd.pop();
        int value = cur.second; char oper = cur.first;
        if(oper=='I') {-------------------
            //삽입
            if(maxHeap.size() == 0 && minHeap.size() ==0 ) {
                maxHeap.push(value);
            }
            else if (maxHeap.top() < value && minHeap.top() == 0 ) {
                int max_ = value;
                int min_ = maxHeap.top(); maxHeap.pop();
                maxHeap.push(max_); minHeap.push(min_);
            }
            else if(value < minHeap.top()) {
                minHeap.push(value);
            }
            else if(maxHeap.top() > value && minHeap.top() < value ) {
                maxHeap.push(value);
            }            
        }
        else if (oper == 'D') {
            //삭제
            if(maxHeap.size() == 0 || minHeap.size() == 0 ) continue; //무시
            if(value == -1) { //최솟값 삭제
                if(minHeap.size()==0) continue;
                minHeap.pop();
            }
            else if(value == 1) { //최댓값 삭제
                if(maxHeap.size()==0) continue;
                maxHeap.pop();
            }
        }    
    }
    
    vector<int> answer(2);
    if(maxHeap.size()!=0) {
        answer[0] = maxHeap.top();
    }
    else {
        answer[0] = 0;
    }
    
    if(minHeap.size() !=0 ) {
        answer[1] = minHeap.top();
    }
    else {
        answer[1] = 0;
    }
    
    return answer;
}

int main() {
    vector<int> ans; 

    //[I 7,I 5,I -5,D -1]	
    string one = "I 16";
    string two = "D 1";

    // string one = "I 7";
    // string two = "I 5";
    // string three = "I -5";
    // string four = "D -1";        
    vector<string> vec;
    vec.push_back(one);
    vec.push_back(two);

    ans = solution(vec);

    for(int i=0;i<ans.size();i++) {
        cout<<ans[i]<<endl;
    }
    return 0;
}