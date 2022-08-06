#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> arr;

int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0;i < n;i++) {
        int x; cin >> x; arr.push_back(x);
    }

    sort(arr.begin(), arr.end());

    cout << arr[(n - 1) / 2] << "\n";

    return 0;
}