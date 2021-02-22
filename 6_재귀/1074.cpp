#include <bits/stdc++.h>
using namespace std;
int n, r, c;

int func(int n, int r, int c) {
    //1. base condition
    if (n == 0) return 0;

    //2. 재귀 
    int half = pow(2, n - 1);
    //1번쨰 사각형
    if (r < half && c < half) {
        return func(n - 1, r, c);
    }
    else if (r < half && c >= half) {
        //2번째 사각형
        return half * half + func(n - 1, r, c - half);
    }
    else if (r >= half && c < half) {
        //3번째 사각형
        return half * half * 2 + func(n - 1, r - half, c);
    }
    else {
        //4번쨰 사각형
        return half * half * 3 + func(n - 1, r - half, c - half);
    }
}

int main() {
    cin >> n >> r >> c;

    cout << func(n, r, c) << "\n";
    return 0;
}