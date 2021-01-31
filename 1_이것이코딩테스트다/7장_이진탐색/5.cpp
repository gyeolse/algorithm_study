#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> arr;

int main() {
    cin >> n;
    for (int i = 0;i < n;i++) {
        int x; cin >> x; arr.push_back(x);
    }

    sort(arr.begin(), arr.end());
    cin >> m;
    for (int i = 0;i < m;i++) {
        int t;
        cin >> t;
        int res = binary_search(arr.begin(), arr.end(), t);
        if (res == 0) {
            cout << "NO" << " ";
        }
        else {
            cout << "YES" << " ";
        }
    }
    return 0;
}