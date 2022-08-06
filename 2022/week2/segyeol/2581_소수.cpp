#include <bits/stdc++.h>
using namespace std;

int sumValue;
int minValue;
vector<int> vec;
bool chk[10001];

void findPrime() {
    for (int i = 2; i * i <= 10001;i++) {
        if (chk[i] == false) {
            for (int j = i * i;j <= 10001; j += i) {
                chk[j] = true;
            }
        }
    }

}

int main() {
    int m, n;
    cin >> m >> n;
    chk[0] = true; chk[1] = true;

    findPrime();

    for (int i = m; i <= n;i++) {
        if (chk[i] == false) {
            vec.push_back(i);
        }
        // cout << chk[i] << " ";
    }

    sort(vec.begin(), vec.end());

    for (int i = 0;i < vec.size();i++) {
        sumValue += vec[i];
    }

    if (vec.size() == 0) {
        cout << "-1" << "\n";
    }
    else {
        cout << sumValue << "\n";
        cout << vec[0] << "\n";
    }
    return 0;
}