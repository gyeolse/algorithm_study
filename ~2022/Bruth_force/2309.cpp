#include <bits/stdc++.h>
using namespace std;

vector<int> arr;
vector<int> ans;
int main() {
    for (int i = 0;i < 9;i++) {
        int x; cin >> x; arr.push_back(x);
    }

    sort(arr.begin(), arr.end());

    int tempArr[9] = { 0,0,1,1,1,1,1,1,1 };
    do
    {
        vector<int> vec;
        int res = 0;
        for (int i = 0;i < 9;i++) {
            if (tempArr[i] == 1) {
                vec.push_back(arr[i]);
                res += arr[i];
            }
        }

        if (res == 100) {
            for (int i = 0;i < vec.size();i++) {
                ans.push_back(vec[i]);
            }
            break;
        }
    } while (next_permutation(tempArr, tempArr + 9));

    sort(ans.begin(), ans.end());

    for (int i = 0;i < ans.size();i++) {
        cout << ans[i] << endl;
    }

    return 0;
}