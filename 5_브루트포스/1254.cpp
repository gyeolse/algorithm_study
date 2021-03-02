#include <bits/stdc++.h>
using namespace std;

string alpha = "abcdefghijklmnopqrstuvwxyz";

int main() {
    string s;
    cin >> s;

    string res = s;

    while (1) {
        bool isAvailable = false;
        for (int i = 0;i < 26;i++) {
            string temp = res + alpha[i];

            int start = 0;
            int end = res.size() - 1;

            int cnt = 0;
            while (start < end) {
                if (res[start] == res[end]) cnt++;
            }

            if (cnt == res.size() / 2) {
                res = temp;
                isAvailable = true;
                break;
            }
            cout << temp << " ";
        }

        if (isAvailable) {
            break;
        }

    }

    cout << res.length() << "\n";
    return 0;
}