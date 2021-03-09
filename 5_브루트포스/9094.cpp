#include <bits/stdc++.h>
using namespace std;

int t;

set<pair<int, int>> s;

int solution(int n, int m) {
    int cnt = 0;
    for (int a = 1;a < n;a++) {
        for (int b = 1;b < n;b++) {
            if (a < b) {
                if (((a * a + b * b + m) % (a * b)) == 0) {
                    cnt++;
                }
            }
        }
    }

    return cnt;
}

int main() {
    cin >> t;
    for (int i = 0;i < t;i++) {
        int n, m;
        cin >> n >> m;

        cout << solution(n, m) << "\n";
    }
}