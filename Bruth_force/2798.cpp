#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> vec;
int main() {
    cin >> n >> m;
    for (int i = 0;i < n;i++) {
        int x; cin >> x; vec.push_back(x);
    }

    vector<int> res;

    //3중 for문
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            for (int k = 0;k < n;k++) {
                if (i == j || j == k || k == i) continue;
                int temp = vec[i] + vec[j] + vec[k];
                if (temp <= m) res.push_back(temp);
            }
        }
    }

    sort(res.begin(), res.end(), greater<>());

    cout << res[0] << "\n";
    return 0;
}


// int n, m;
// int main() {
//     vector<int> vec;

//     cin >> n >> m;
//     for (int i = 0;i < n;i++) {
//         int x; cin >> x;
//         vec.push_back(x);
//     }

//     vector<int> forLoop;
//     vector<int> res;

//     //n개 중 3개를 고르기 
//     for (int i = 0;i < n - 3;i++) {
//         forLoop.push_back(0);
//     }
//     for (int i = 0;i < 3;i++) {
//         forLoop.push_back(1);
//     }

//     do
//     {
//         int temp = 0;
//         for (int i = 0;i < forLoop.size();i++) {
//             if (forLoop[i] == 1) {
//                 temp += vec[i];
//             }
//         }

//         if (temp <= m) {
//             res.push_back(temp);
//         }
//     } while (next_permutation(forLoop.begin(), forLoop.end()));

//     sort(res.begin(), res.end(), greater<>());

//     cout << res[0] << "\n";
//     return 0;
// }