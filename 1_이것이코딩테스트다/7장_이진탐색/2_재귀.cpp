#include <bits/stdc++.h>
using namespace std;

int n, target;
vector<int> arr;

//1. 이진 탐색 (재귀)
int binarySearch(vector<int>& arr, int target, int start, int end) {
    if (start > end) return -1; //없다는 것을 뜻함
    int mid = (start + end) / 2;
    if (arr[mid] == target) return mid; //찾음
    else if (arr[mid] > target) { //mid가 더 큰 경우, 왼쪽 확인
        return binarySearch(arr, target, start, mid - 1);
    }
    else return binarySearch(arr, target, mid + 1, end); //오른쪽 확인

}

int main() {
    cin >> n >> target;
    for (int i = 0;i < n;i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    //binarysearch stl : 시작점, 끝점, 찾는수
    //output
    // int res = binarySearch(arr, target, 0, n - 1);
    int res = binary_search(arr.begin(), arr.end(), target);
    if (res == -1) {
        cout << -1 << "\n";
    }
    else {
        cout << res + 1 << "\n";
    }


    return 0;
}