#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0;i < n;i++) {
        cin >> arr[i];
    }

    int start = 0, end = 0, cnt = 0, sum = 0;

    while (start <= end && end <= n) {
        //1. m보다 클 때,
        if(sum > m) {
            sum -= arr[start++];
        }
        //2. m이랑 같을 때,
        else if (sum == m) {
            cnt++;
            sum -= arr[start++];
        }
        //3. m보다 작을 때
        else {
            sum += arr[end++];
        }
    }

    cout<<cnt<<"\n";
    return 0;
}