#include <bits/stdc++.h>
using namespace std;

int main() {
    int loop_ = 1;

    vector<int> vec;
    while (loop_ != -1) {
        cin >> loop_;
        vec.push_back(loop_);
        int temp = 1;
        while (temp != 0 && loop_ != -1) {
            cin >> temp;
            vec.push_back(temp);
        }

        int cnt = 0;
        for (int i = 0;i < vec.size();i++) {
            for (int j = 0;j < vec.size();j++) {
                if (i != j) {
                    if (vec[i] * 2 == vec[j]) {
                        cnt++;
                    }
                }
            }
        }

        if (loop_ != -1) {
            cout << cnt << "\n";
        }
        vec.clear();
    }

    return 0;
}