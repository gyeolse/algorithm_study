#include <bits/stdc++.h>
using namespace std;

stack<char> stk;
string s;

int main() {
    cin >> s;

    int tmp = 1;
    int res = 0;
    bool isAvailable = true;

    for (int i = 0;i < s.size();i++) {
        if (s[i] == '(') {
            tmp *= 2;
            stk.push(s[i]);
        }
        else if (s[i] == '[') {
            tmp *= 3;
            stk.push(s[i]);
        }

        // 닫는 놈들. ) 인데 바로 앞에 ( 가 없으면 불가능
        else if (s[i] == ')' && (stk.size() == 0 || stk.top() != '(')) {
            isAvailable = false;
            break;
        }
        else if (s[i] == ']' && (stk.size() == 0 || stk.top() != '[')) {
            isAvailable = false;
            break;
        }
        else if (s[i] == ')') {
            if (s[i - 1] == '(') {
                res += tmp;
            }
            stk.pop();
            tmp /= 2;
        }
        else if (s[i] == ']') {
            if (s[i - 1] == '[') {
                res += tmp;
            }
            stk.pop();
            tmp /= 3;
        }
    }

    if (stk.size() != 0 || isAvailable == false) {
        cout << 0 << "\n";
    }
    else {
        cout << res << "\n";
    }

    return 0;
}