#include <bits/stdc++.h>
using namespace std;

// 100*100*100 = 1000000

struct num {
    int a;
    int b;
    int c;
    int d;
};
int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);
    vector<num> vec;

    // a * a * a 
    for (int a = 1;a <= 100;a++) {
        int temp = a * a * a;

        for (int b = 2;b <= 100;b++) {
            for (int c = b;c <= 100;c++) {
                for (int d = c;d <= 100;d++) {
                    if (a != b && b != c && c != d && d != a) {
                        int bMul = b * b * b;
                        int cMul = c * c * c;
                        int dMul = d * d * d;
                        if (bMul + cMul + dMul == temp) {
                            num tempNum;
                            tempNum.a = a;
                            tempNum.b = b;
                            tempNum.c = c;
                            tempNum.d = d;
                            vec.push_back({ tempNum });
                        }
                    }
                }
            }
        }
    }

    for (int i = 0;i < vec.size();i++) {
        cout << "Cube = " << vec[i].a << ", Triple = (" << vec[i].b << "," << vec[i].c << "," << vec[i].d << ")" << "\n";
    }

    return 0;
}