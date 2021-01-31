#include <bits/stdc++.h>

using namespace std;

string func(string s, int len) {
    if(s.size() < len ) return s;
    string s_;
    for(int i=0;i<len;i++) {
        s_ += s[i];
    }
    return s_;
}

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(),phone_book.end());
    bool answer = true;
    
    //1. phone_book 순회
    for(int i=0;i<phone_book.size();i++) {
        map<string,int> m;
        int len = phone_book[i].length();
        
        for(int j=0;j<phone_book.size();j++) {
            string tempString = func(phone_book[j],len);
            cout<<tempString<<"\n";
            if(m.find(tempString) != m.end() && tempString == phone_book[i]) return false; //하나라도 같은 것이 있고, 현재 tempString과 현 loop의 접두사 phon_book[i] 와 같다면
            else {
                m.insert({tempString, 1});
            }                
        }
    }
        return true;                    
}