#include <bits/stdc++.h>
using namespace std;
string a, b;

// A가 abc, B가 abcdefg 라면, B에 A를 일일이 붙이면서, 그 때의 차이 값을 계산해본다.

int main() {
    cin >> a >> b;

    int res = 987654321;

    for (int i = 0;i <= b.size() - a.size();i++) {
        int temp = 0;
        for (int j = 0;j < a.size();j++) {
            if (a[j] != b[j+i]) temp++;
        }
        res = min(res, temp);
    }

    cout<<res<<"\n";
    return 0;
}