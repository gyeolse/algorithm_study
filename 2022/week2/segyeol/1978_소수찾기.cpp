#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> vec;
bool chk[1000];

// 에라토스테네스의 체. input > 1000. 2 ~ N
// 합성수들은 모두 거르고, 남은 수들만이 소수
void checkPrime() {
    for (int i = 2; i * i <= 1000;i++) {
        if (chk[i] == false) {
            for (int j = i * i;j <= 1000;j += i) {
                chk[j] = true;
            }
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0;i < n;i++) {
        int a; cin >> a;
        vec.push_back(a);
    }

    checkPrime();
    chk[0] = true; chk[1] = true;

    int ans = 0;

    for (int i = 0;i < vec.size();i++) {
        if (chk[vec[i]] == false) {
            ans++;
            // cout << vec[i] << " ";
        }
    }

    cout << ans << "\n";
    return 0;
}
