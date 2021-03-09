#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<string> inputData;

int chk[26];
int res = 0;

void init () {
    //0,13, 19, 8, 2 는 항상 1이여야 함
    chk[0] = 1;
    chk[13] = 1;
    chk[19] = 1;
    chk[8] = 1;
    chk[2] = 1;
}

void func(int idx, int cnt) {
    //cnt == k-5일떄 return; 
    if(cnt == k-5) {
        int temp = 0;
        for(int i=0;i<n;i++) {
            // 배우지 않은 단어가 있는지 체크
            bool isAvailable = true; 

            for(int j=0;j<inputData[i].size();j++) {
                if(chk[inputData[i][j]-'a'] == 0) {
                    isAvailable = false;
                    break;
                }
            }

            if(isAvailable) {
                temp++;
            }
        }

        res = max(res,temp);
        return;
    }

    //K개를 배우지 않았을 때 
    /////////////////////////////////////////////////////////////
    for(int i=idx;i<26;i++) {
        if(!chk[i]) {
            //체크 안된 알파벳
            chk[i] = 1;
            func(i, cnt+1);
            chk[i] = 0;
        }
    }
    /////////////////////////////////////////////////////////////    
}


int main() {
    cin >> n >> k;

    if (k < 5) {
        cout << 0 << "\n";
        return 0;
    }

    for (int i = 0;i < n;i++) {
        string s; cin >> s;
        inputData.push_back(s);
    }

    init(); //a,n,t,i,c에 해당하는 idx를 1로 세팅

    //alpha에 해당 idx를 1로 세팅해둔 상태.
    //전체 알파벳에서 k-5개 만큼 선택함.
    
    //현재 idx와, 총 구해야할 크기
    func(0,0);

    cout<<res<<"\n";
}

