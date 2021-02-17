#include <bits/stdc++.h>
using namespace std;
int n;

int main() {
    cin >> n;

    int cnt = 0;
    for (int i = 1;i <= n;i++) {
        string s = to_string(i);
        if (s.size() == 1) {
            cnt++;
        }
        else if (s.size() == 2) {
            cnt++;
        }
        else { //s의 크기가 3이상
            bool isAvailable = true;
            int past = s[1] - s[0];
            for (int j = 0;j < s.size() - 1;j++) {
                if (s[j + 1] - s[j] != past) {
                    isAvailable = false;
                    break;
                }
            }
            if (isAvailable == true) cnt++;
        }
    }

    cout << cnt << "\n";
    return 0;
}