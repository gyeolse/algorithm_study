#include <bits/stdc++.h>
using namespace std;

int alwaysLearn[5] = { 0,2,8,13,19 };
int n, k;
int alpha[26];
vector<string> inputData;
int res = 0;

void func(int idx, int cnt ) {
    //탈출 조건
    if(cnt == k-5) {
        int temp = 0;

        for(int i=0;i<n;i++) {
            bool isAvailable = true;

            for(int j=0;j<inputData[i].size();j++) {
                if(alpha[inputData[i][j]-'a'] == 0) {
                    isAvailable = false;
                }
            }

            if(isAvailable) {
                temp++;
            }
        }

        res = max(res, temp);

        return;
    }

    //다음 탐색 조건
    for(int i=idx;i<26;i++) {
        if(alpha[i] == 0 ) {
            alpha[i] = 1;
            func(i+1,cnt+1);
            alpha[i] = 0; 
        }
    }
}

int main() {
    cin >> n >> k;
    for (int i = 0;i < n;i++) {
        string x; cin >> x; inputData.push_back(x);
    }

    //1. k가 5미만일 경우, 항상 배울 수 없음 
    if (k < 5) {
        cout << 0 << "\n";
        return 0;
    }

    //2. 매번 배워야만 하는 알파벳 설정
    for (int i = 0;i < 5;i++) {
        alpha[alwaysLearn[i]] = 1;
    }

    //idx, count
    func(0,0);

    cout<<res<<"\n";

    return 0;
}