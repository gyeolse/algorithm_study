#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<int, int>> vec;

int main() {
    cin >> n;

    for (int i = 0;i < n;i++) {
        int a, b;
        cin >> a >> b;
        vec.push_back({ a,b }); //몸무게, 키
    }

    vector<int> res;

    for (int i = 0;i < n;i++) {
        int rnk = 1;
        for (int j = 0;j < n;j++) {
            if (vec[i].first < vec[j].first && vec[i].second < vec[j].second) {
                rnk++;
            }
        }
        res.push_back(rnk);
    }

    for (int i = 0;i < n;i++) {
        cout << res[i] << " ";
    }
    return 0;
}