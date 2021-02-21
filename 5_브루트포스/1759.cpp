#include <bits/stdc++.h>
using namespace std;

int l, c;
vector<char> alpha;
vector<int> pick;
int moCount;
int jaCount;

int main() {
    cin >> l >> c;
    for (int i = 0;i < c;i++) {
        char x; cin>>x; alpha.push_back(x);
    }

    sort(alpha.begin(),alpha.end());

    //조합 생성

    for(int i=0;i<l;i++) { //4 1,1,1,1
        pick.push_back(0);
    }
    for(int i=0;i<(c-l);i++) { //6-4 0,0
        pick.push_back(1);
    }

    // for(int i=0;i<pick.size();i++) {
    //     cout<<pick[i]<<" ";
    // }

    sort(pick.begin(),pick.end());
    do
    {
        //4개를 뽑는 경우의 수
        //이번 loop의 문자 확인 
        string s;
        for(int i=0;i<c;i++){
            if(pick[i] == 0 ) s+=alpha[i];
        }

        int jaCount = 0 ;
        int moCount = 0 ;
        for(int i=0;i<s.size();i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                moCount++;
            }
            else {
                jaCount++;
            }
        }

        if(moCount >=1 && jaCount >=2) {
            cout<<s<<"\n";
        }
        else {
            continue;
        }
    } while (next_permutation(pick.begin(),pick.end()));
    
    return 0;
}