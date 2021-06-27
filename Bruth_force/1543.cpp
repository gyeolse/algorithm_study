#include <bits/stdc++.h>
using namespace std;

int main() {
    string document, target;

    getline(cin, document);
    getline(cin, target);

    int res = 0;

    if (target.size() > document.size()) {
        cout << "0" << "\n";
        return 0;
    }

    for (int i = 0;i < document.size();i++) {
        int cnt = 0;
        for (int j = 0;j < target.size();j++) {
            if (document[i + j] == target[j]) {
                cnt++;
            }
            else {
                break;
            }
        }

        if (cnt == target.size()) {
            i += target.size() - 1; //어차피 다음 loop 이동시에 +1이 되므로
            res++;
        }
    }

    cout << res << "\n";
    return 0;
}