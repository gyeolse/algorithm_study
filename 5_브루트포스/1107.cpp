#include <bits/stdc++.h>
using namespace std;
int n, m;
int notUsed[10];

bool isAvailable(int t) {
    //0일떄 처리를 해주지 않아서 틀림. 0일 경우에 return true로 빠져버리므로, 
    //해당 예외처리를 무조건 해주어야함.
    if (t == 0) {
        if (notUsed[0]) return false;
        return true;
    }
    while (t) {
        if (notUsed[t % 10] == true) {
            return false;
        }
        t /= 10;
    }
    return true;
}

int buttonCount(int n) {
    //1. 현재 위치 100에서 +나 -을 누르는 경우
    int hundredDistance = abs(n - 100);

    //2. 최대한 많이 누르는 경우. 0~9 모두 고장난 경우
    //  0에서 해당 Idx 가는 경우, 백만에서 해당 idx 가는 경우 두 가지 
    int MAX = 1000010;
    int loopVal = MAX;

    for (int i = 0;i < MAX;i++) {
        if (isAvailable(i)) {
            int temp = to_string(i).length();
            int gap = abs(n - i);

            loopVal = min(gap + temp, loopVal);
        }
    }

    return min(loopVal, hundredDistance);
}

int main() {
    cin >> n >> m;

    for (int i = 0;i < m;i++) {
        int x; cin >> x;
        notUsed[x] = true;
    }

    cout << buttonCount(n) << "\n";

    return 0;
}