#include <bits/stdc++.h>
using namespace std;

vector<string> words;
int mustAlpha[5] = { 0, 2, 8, 13, 19 };
bool alpha[26];
int n, k;
int ans;

void setMustLearnLang() {
    for (int i = 0;i <= 5;i++) {
        alpha[mustAlpha[i]] = true;
    }
}

void func(int idx, int cnt) {
    if (cnt == k - 5) {
        int curRes = 0;

        for (int i = 0;i < n;i++) {
            bool isAvailable = true;
            for (int j = 0;j < words[i].size();j++) {
                if (alpha[words[i][j] - 'a'] == false) {
                    isAvailable = false;
                }
            }
            if (isAvailable == true) curRes++;
        }

        ans = max(ans, curRes);
        return;
    }

    for (int i = idx;i <= 26;i++) {
        if (alpha[i] != true) {
            alpha[i] = true;
            func(i + 1, cnt + 1); // 다음꺼부터 가는게 맞음.
            alpha[i] = false;
        }
    }
}

int main() {
    cin >> n >> k;

    for (int i = 0;i < n;i++) {
        string s; cin >> s;
        words.push_back(s);
    }

    // k < 5 라면 어차피 불가능
    if (k < 5) {
        cout << "0" << "\n";
        return 0;
    }

    // 완탐 시작. 어차피 배워야하는 단어들 : a, n, t, i, c. 
    setMustLearnLang();

    func(0, 0);

    cout << ans << "\n";

    return 0;

}