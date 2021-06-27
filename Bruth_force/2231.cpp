#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int res = 0;

    for (int i = 0;i < n;i++) {
        int temp = 0;
        int div = i;

        //몫이 0이 아닐 때 까지 계속 나눔
        while (div != 0) {
            temp += (div % 10);
            div = div / 10;
        }

        if ((temp + i) == n) {
            res = i;
            break;
        }
    }

    cout << res << "\n";
    return 0;
}
// int main() {
//     int n;
//     cin >> n;

//     int res = 0;
//     for (int i = 0;i < n;i++) {
//         //1. string 으로 형 변환 
//         int temp = 0;
//         string s = to_string(i);

//         for (int i = 0;i < s.size();i++) {
//             temp += s[i] - '0';
//         }
//         if ((temp + i) == n) {
//             res = i;
//             break;
//         }
//     }

//     cout << res << "\n";
//     return 0;
// }