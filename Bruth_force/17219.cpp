#include <bits/stdc++.h>
using namespace std;

int n, m;

int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);
    cin >> n >> m;
    map<string, string> vec;

    for (int i = 0;i < n;i++) {
        string a, b;
        cin >> a >> b;
        vec.insert({ a,b });
    }

    for (int i = 0;i < m;i++) {
        string a;
        cin >> a;

        cout << vec[a] << "\n";
    }
    return 0;
}