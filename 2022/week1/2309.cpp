#include <bits/stdc++.h>
using namespace std;
vector<int> res;
int arr[9] = { 0,0,1,1,1,1,1,1,1 };

int main() {
    for (int i = 0;i < 9;i++) {
        int a; cin >> a; res.push_back(a);
    }
    sort(res.begin(), res.end());

    do {
        int curVal = 0;
        vector<int> tempVec;
        for (int i = 0;i < 9;i++) {
            if (arr[i] == 1) {
                curVal += res[i];
                tempVec.push_back(res[i]);
            }
        }

        if (curVal == 100) {
            for (int i = 0;i < 7;i++) {
                cout << tempVec[i] << "\n";
            }
            return 0;
        }
    } while (next_permutation(arr, arr + 9));

    return 0;
}