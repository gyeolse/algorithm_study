#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> arr;
int oper[4];
int minValue = +1000000000;
int maxValue = -1000000000;

void func(int res, int plus, int minus, int multiply, int divide, int idx) {
    if (plus < 0 || minus < 0 || multiply < 0 || divide < 0) return;
    if (idx == n) {
        if (minValue > res) {
            minValue = min(res, minValue);
        }
        if (maxValue < res) {
            maxValue = max(res, maxValue);
        }
        return;
    }
    // cout << "cur Value : " << plus << " " << minus << " " << multiply << " " << divide << "\n";
    func(res + arr[idx], plus - 1, minus, multiply, divide, idx + 1);
    func(res - arr[idx], plus, minus - 1, multiply, divide, idx + 1);
    func(res / arr[idx], plus, minus, multiply, divide - 1, idx + 1);
    func(res * arr[idx], plus, minus, multiply - 1, divide, idx + 1);
}



int main() {
    cin >> n;

    for (int i = 0;i < n;i++) {
        int x; cin >> x;
        arr.push_back(x);
    }

    int cnt = 0;
    for (int i = 0;i < 4;i++) {
        cin >> oper[i];
    }

    //재귀. +/-/*// 갯수, 총 갯수, 
    func(arr[0], oper[0], oper[1], oper[2], oper[3], 1);
    cout << maxValue << endl << minValue;

    return 0;
}