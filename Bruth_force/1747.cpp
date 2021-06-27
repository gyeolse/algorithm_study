#include <bits/stdc++.h>
using namespace std;
#define MAX 1004000 //MAX 값을 크게 해줬어야 했을 문제
long long n;
long long res = 0;
long long isPrime[MAX]; //true : 소수, false : 소수 X

// http://blog.naver.com/PostView.nhn?blogId=kks227&logNo=220793360258

bool isPell(int n) {
    bool res = true;

    //1. n의 자릿수 
    string numToString = to_string(n);
    int sz = numToString.size();
    int start = 0;
    int end = sz - 1;

    //2. 팰린드롬1 확인
    for (int i = 0;i < sz - 1;i++) {
        if (numToString[i] != numToString[sz - i - 1]) {
            return false;
        }
    }

    return true;

}

int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);
    cin >> n;

    //1. 소수 구하기 : 에라토스테네스의 체
    for (int i = 2;i < MAX;i++) {
        isPrime[i] = i;
    }

    for (int i = 2;i < MAX;i++) {
        if (isPrime[i] == 0) continue;

        for (int j = 2 * i;j <= MAX;j += i) {
            isPrime[j] = 0;
        }
    }

    //2. 그 중 팰린드롬 체크
    for (int i = n;i < MAX;i++) {
        if (isPrime[i] != 0) {
            if (isPell(i)) {
                res = i;
                break;
            }
        }
    }

    cout << res << "\n";

    return 0;
}