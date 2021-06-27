#include <bits/stdc++.h>
using namespace std;
vector<int> vec;


int main() {

    for (int i = 0;i < 9;i++) {
        int x; cin >> x;
        vec.push_back(x);
    }

    vector<int> forLoop;

    for (int i = 0;i < 2;i++) {
        forLoop.push_back(0);
    }

    for (int i = 0;i < 7;i++) {
        forLoop.push_back(1);
    }

    do
    {
        int temp = 0;
        vector<int> res;

        for (int i = 0;i < forLoop.size();i++) {
            if (forLoop[i]) {
                temp += vec[i];
                res.push_back(vec[i]);
            }
        }

        if (temp == 100) {
            for (int i = 0;i < res.size();i++) {
                cout << res[i] << "\n";
            }
        }
    } while (next_permutation(forLoop.begin(), forLoop.end()));

    return 0;
}