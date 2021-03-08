#include <bits/stdc++.h>
using namespace std;

vector<pair<int, pair<int, int>>> vec;
int n;
bool isAvailable[1000];
bool checkTwice(int num) {
    string s = to_string(num);

    if (s[0] == s[1] || s[1] == s[2] || s[2] == s[0]) return false;
    return true;
}

bool checkZero(int num) {
    string s = to_string(num);
    if (s[0] == '0' || s[1] == '0' || s[2] == '0') return false;
    return true;
}

int main() {
    cin >> n;
    for (int i = 0;i < n;i++) {
        int a, b, c; //
        cin >> a >> b >> c;
        vec.push_back({ a,{b,c} });
    }

    //1. isAvailable 초기화
    memset(isAvailable, true, sizeof(isAvailable));

    for (int i = 123;i <= 999;i++) {
        if (!checkTwice(i)) {
            isAvailable[i] = false;
        }
        if (!checkZero(i)) {
            isAvailable[i] = false;
        }
    }

    //2. vector의 해당 수에 대한 스트라이크, 볼 체크
    for (int i = 0;i < vec.size();i++) {
        int cur = vec[i].first;
        int curStrike = vec[i].second.first;
        int curBall = vec[i].second.second;

        string curString = to_string(cur);


        for (int j = 123;j <= 999;j++) {
            int tempStrike = 0;
            int tempBall = 0;

            if (isAvailable[j] == true) {
                string tempString = to_string(j);
                for (int a = 0;a < 3;a++) {
                    for (int b = 0;b < 3;b++) {

                        //1. a==b이고, temp와 cur이 같은 경우
                        if (a == b && tempString[a] == curString[a]) tempStrike++;

                        //2. a!=b이고, temp와 cur이 같은 경우
                        if (a != b && tempString[a] == curString[b]) tempBall++;
                    }
                }
                if (tempStrike != curStrike || tempBall != curBall) isAvailable[j] = false;
            }
        }
    }

    int res = 0;

    for(int i=123;i<=999;i++) {
        if(isAvailable[i] == true) res++;
    }

    cout<<res<<"\n";

    return 0;
}