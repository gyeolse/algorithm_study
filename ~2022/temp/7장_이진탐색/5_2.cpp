#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> arr;

int binarySearch(vector<int>& arr, int start, int end, int target) {
    //1. 인덱스 초과시 return -1
    if (start > end) return -1;

    int mid = (start + end) / 2;

    //1. 왼쪽에 있을 때
    if (target < arr[mid]) {
        return binarySearch(arr, start, mid - 1, target);
    }
    //2. 오른쪽에 있을 때 
    else if (target > arr[mid]) {
        return binarySearch(arr, mid + 1, end, target);
    }
    //3. 같을 때
    return mid;
}
int main() {
    cin >> n;
    for (int i = 0;i < n;i++) {
        int x; cin >> x; arr.push_back(x);
    }

    sort(arr.begin(), arr.end());
    cin >> m;
    for (int i = 0;i < m;i++) {
        int t;
        cin >> t;
        //직접 구현
        int res = binarySearch(arr, 0, n - 1, t);
        // int res = binary_search(arr.begin(), arr.end(), t);
        if (res == -1) {
            cout << "NO" << " ";
        }
        else {
            cout << "YES" << " ";
        }
    }
    return 0;
}