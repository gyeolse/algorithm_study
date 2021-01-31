#include <bits/stdc++.h>
using namespace std;
#define MAX 10000000

int d[MAX];
int n;

int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 2;i <= n;i++) {
        //1. 1을 빼는 경우
        d[i] = d[i - 1] + 1;

        //2. 
        if (i % 3 == 0) {
            d[i] = min(d[i], d[i / 3] + 1);
        }
        //3. 
        if (i % 2 == 0) {
            d[i] = min(d[i], d[i / 2] + 1);
        }
    }
    cout<<d[n]<<"\n";
}