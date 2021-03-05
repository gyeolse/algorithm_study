#include <bits/stdc++.h>
using namespace std;

string S = "ABC";
string C = "BABC";
string H = "CCAABB";
string totalS;
string totalC;
string totalH;

int main() {
    int n; string s;
    cin >> n;
    cin >> s;

    int res[3];
    memset(res, 0, sizeof(res));

    string name_[3] = { "Adrian", "Bruno", "Goran" };

    for (int i = 0;i < 100;i++) {
        totalS += S;
        totalC += C;
        totalH += H;
    }

    for (int i = 0;i < s.size();i++) {
        if (s[i] == totalS[i]) {
            res[0]++;
        }
        if (s[i] == totalC[i]) {
            res[1]++;
        }
        if (s[i] == totalH[i]) {
            res[2]++;
        }
    }

    int ans = *max_element(res, res + 3);
    cout << ans << "\n";
    for (int i = 0;i < 3;i++) {
        if (ans == res[i]) {
            cout << name_[i] << "\n";
        }
    }

    return 0;
}