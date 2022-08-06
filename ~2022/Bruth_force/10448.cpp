#include <bits/stdc++.h>
using namespace std;
int n;
bool isAvailable[100001];
int samgak[1001];


int main() {
    int temp = 1;
    for (int i = 1;i <= 500;i++) {
        if (i == 1) {
            samgak[i] = temp;
            temp++;
        }
        else {
            samgak[i] += samgak[i - 1];
            samgak[i] += temp;
            temp++;
        }
    }

    for (int i = 1;i <= 50;i++) {
        for (int j = 1;j <= 50;j++) {
            for (int k = 1;k <= 50;k++) {
                int temp = samgak[i] + samgak[j] + samgak[k];
                isAvailable[temp] = true;
            }
        }
    }

    cin >> n;
    for (int i = 0;i < n;i++) {
        int x; cin >> x;
        cout << isAvailable[x] << "\n";
    }
    return 0;
}