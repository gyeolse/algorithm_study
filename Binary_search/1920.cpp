#include <bits/stdc++.h>
using namespace std;

//BinarySearch 구현
int binarySearch(vector<int>& arr, int target, int start, int end) {
    //1. 범위 벗어나는 경우
    if (start > end) return 0;

    int mid = (start + end) / 2;
    //2. 찾았을 경우
    if (arr[mid] == target) return 1;
    //3. 탐색. target이 더 큰 경우, 오른쪽 탐색
    else if (target > arr[mid]) return binarySearch(arr, target, mid + 1, end);
    //4. 탐색. target이 더 작은 경우, 왼쪽 탐색 
    else return binarySearch(arr, target, start, mid - 1);
}

int main() {
    cin.tie(NULL); ios::sync_with_stdio(false); cout.tie(NULL);
    int n, m;
    vector<int> arr;
    cin >> n;
    for (int i = 0;i < n;i++) {
        int x; cin >> x;
        arr.push_back(x);
    }

    //1. 정렬
    sort(arr.begin(), arr.end());

    cin >> m;
    for (int i = 0;i < m;i++) {
        int x; cin >> x;
        int res = binarySearch(arr, x, 0, n - 1);
        // int res = binary_search(arr.begin(), arr.end(), x);
        cout<<res<<"\n";
    }
    return 0;
}