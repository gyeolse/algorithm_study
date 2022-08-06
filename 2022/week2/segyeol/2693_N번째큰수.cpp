#include <bits/stdc++.h>
using namespace std;
int t;

// compare function 바뀌어야할떄 true
bool compFunc(int a, int b) {
    if (a > b) return true;
    else return false;
}

int main() {
    cin >> t;
    for (int i = 0;i < t;i++) {
        vector<int> vec;
        for (int j = 0;j < 10;j++) {
            int a; cin >> a;
            vec.push_back(a);
        }

        sort(vec.begin(), vec.end(), compFunc);

        cout << vec[2] << "\n";
    }
    return 0;

}