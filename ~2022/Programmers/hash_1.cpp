#include <bits/stdc++.h>
#include <map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    
    map<string,int> m;
    
    for(auto cur : completion) {
        if(m.find(cur) == m.end()) m[cur] = 1; //key, value 설정
        else m[cur]++; //value를 ++ 해줌. 
    }
    
    for(auto cur : participant) {
        if(m.find(cur) == m.end()) return cur; //찾으면 바로 return
        else {
            m[cur]--;
            // -1이라면
            if(m[cur] < 0) return cur;            
        }
    }   
}