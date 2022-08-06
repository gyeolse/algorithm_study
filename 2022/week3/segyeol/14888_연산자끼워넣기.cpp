#include <bits/stdc++.h>
using namespace std;
int plus_, minus_, multiply_, divide_;
int n;
vector<int> input;
int min_ = 1000000000;
int max_ = -1000000000;

void func(int res, int idx, int plus, int minus, int multiply, int divide) {
    if (plus < 0 || minus < 0 || multiply < 0 || divide < 0) return;

    // escape
    if (idx == n) {
        min_ = min(min_, res);
        max_ = max(max_, res);
        return;
    }

    func(res + input[idx], idx + 1, plus - 1, minus, multiply, divide);
    func(res - input[idx], idx + 1, plus, minus - 1, multiply, divide);
    func(res * input[idx], idx + 1, plus, minus, multiply - 1, divide);
    func(res / input[idx], idx + 1, plus, minus, multiply, divide - 1);
}

int main() {
    cin >> n;
    for (int i = 0;i < n;i++) {
        int a; cin >> a; input.push_back(a);
    }

    cin >> plus_ >> minus_ >> multiply_ >> divide_;
    func(input[0], 1, plus_, minus_, multiply_, divide_);

    cout << max_ << "\n";
    cout << min_ << "\n";
    return 0;
}