#include <bits/stdc++.h>
using namespace std;

vector<bool> solution(string program, vector<string> flag_rules, vector<string> commands) {
    vector<bool> answer;
    //1. 프로그램의 이름 지정    
    string ProgramName = program;
    vector<pair<string,string>> ruleVec;
    
    //2. flag_rules를 pair로 저장
    for(int i = 0;i<flag_rules.size();i++) {
        istringstream ss(flag_rules[i]);
        string stringBuffer;
        vector<string> vec;
        while(getline(ss,stringBuffer,' ')) {
            vec.push_back(stringBuffer);
        }

        ruleVec.push_back({vec[0],vec[1]});
    }

    //3. command를 돌면서, true, false 값을 지정
    for(int i=0;i<commands.size();i++) {
        istringstream ss(commands[i]);
        string stringBuffer; 
        //4. 일단, 프로그램명이 올바른지 확인 
        getline(ss,stringBuffer,' ');
        if(stringBuffer != ProgramName) {
            answer.push_back(false);
            continue;
        }
        
        vector<string> vec;
        while(getline(ss,stringBuffer,' ')) {
            vec.push_back(stringBuffer);
        }

        bool isAvailable = true;
        //5. vector를 돌면서 문제 확인    
        for(int j=0;j<vec.size();j++) {
            //첫 번째인 경우
            if(j==0) {
                if(vec[j][0] !='-') {
                    isAvailable =false;
                    continue;
                }
            }
            //1. '-'가 포함되어있는지 체크
            if(vec[j][0] == '-') {
                string flagString = vec[j];
                string flagArg;
                for(int k = 0; k<ruleVec.size();k++) {
                    if(flagString == ruleVec[k].first) {
                        flagArg = ruleVec[k].second;
                    }
                }

                // 체크
                if(flagArg == "STRING") {
                    bool isOk = false; 
                    regex pattern("^[a-zA-Z]+$");
                    if(regex_match(vec[j+1],pattern)) {
                        isAvailable = true;
                    }
                    else {
                        isAvailable = false; 
                    }
                    // cout<<vec[j+1]<<isAvailable<<endl;

                }
                else if(flagArg == "NUMBER") {
                    regex pattern("^[0-9]+$");
                    if(regex_match(vec[j+1],pattern)) {
                        isAvailable = true;
                    }
                    else {
                        isAvailable = false;
                    }
                    // cout<<vec[j+1]<<isAvailable<<endl;
                }
                else if(flagArg == "NULL") {
                    if(j== vec.size()-1) continue;
                    else {
                        if(vec[j+1][0] != '-') isAvailable =false;
                    }
                }
//                 추가
                else if(flagArg == "NUMBERS") {
                    regex pattern("^[0-9]+$");                    
                    while(vec[j+1][0] != '-') {
                        if(regex_match(vec[j+1],pattern)) isAvailable = true;
                        else isAvailable = false;
                        j++;  
                    }
                }
                else if(flagArg == "STRINGS") {
                    regex pattern("^[a-zA-Z]+$");
                    while(vec[j+1][0] != '-') {
                        if(regex_match(vec[j+1],pattern)) isAvailable = true;
                        else isAvailable = false;
                        j++;                        
                    }
                    
                }
            } 
        }    
        
        answer.push_back(isAvailable);
    }
    return answer;
}
int main() {

    vector<bool> ans = solution("line", {"-s STRING", "-n NUMBER", "-e NULL"}, {"line -n 100 -s hi -e", "lien -s Bye"});

    for(int i=0;i<ans.size();i++) {
        cout<<ans[i]<<" ";
    }
}