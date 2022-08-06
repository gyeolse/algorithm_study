#include <bits/stdc++.h>
using namespace std;

int alpha[30]; //알파벳 value 저장
vector<string> words;
int n; //단어의 갯수

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++) {
        string t;
        cin>>t;
        words.push_back(t);
    }

    //1. word : words[i][j] -'0' - 17 (A가 17) (alpha에 넣어줄 때)
    //알파벳이 어느 자릿수에, 얼마나 등장하는지 alpha 배열에 넣어줌
    for(int i=0;i<n;i++) {
        for(int j=0;j<words[i].size();j++) {
            int cur = words[i][j]-'0'-17; //1234일떄 1은 1000 (10^3)
            int curValue = pow(10,words[i].size()-(j+1));
            alpha[cur] += curValue;
        }
    }

    //2. alpha 배열의 idx, 빈도수를 같이 저장
    vector<pair<int,int>> alphaPair;
    for(int i=0;i<30;i++) {
        if(alpha[i] == 0) continue;
        alphaPair.push_back({alpha[i],i}); //value, idx
    }
    
    sort(alphaPair.begin(),alphaPair.end(),greater<>());

    //3. 숫자 부여
    int cur = 9;
    int res = 0;
    for(int i=0;i<alphaPair.size();i++) {
        int t = alphaPair[i].first * cur;
        res += t;
        cur--;        
        // cout<<alphaPair[i].first<<" "<<alphaPair[i].second<<endl;
    }

    cout<<res<<endl;

    return 0;
}