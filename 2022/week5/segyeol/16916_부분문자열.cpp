#include <bits/stdc++.h>
using namespace std;
string s, p;
int n;

vector<int> failFunc(string p) {
    int pLength = p.length();
    vector<int> failVec(pLength, 0);

    int j = 0;
    for (int i = 1;i < pLength;i++) {
        while (j > 0 && p[i] != p[j]) {
            j = failVec[j - 1];
        }
        if (p[i] == p[j]) {
            failVec[i] = ++j;
        }
    }
    return failVec;

}

int kmp(string s, string p) {
    vector<int> failVector = failFunc(p);
    int j = 0;

    for (int i = 0;i < s.length();i++) {
        while (j > 0 && s[i] != p[j]) {
            j = failVector[j - 1];
        }

        if (s[i] == p[j]) {
            if (j == p.length() - 1) return 1; // 찾았을 경우
            else j += 1;
        }
    }

    return 0; // 못 찾은 경우
}

int main() {
    cin >> s >> p;
    n = s.length();

    int res = kmp(s, p);
    cout << res << "\n";

}