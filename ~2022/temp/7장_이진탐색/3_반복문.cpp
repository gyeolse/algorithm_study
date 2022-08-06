#include <bits/stdc++.h>
using namespace std;

int n, target;
vector<int> arr;

//1. 이진 탐색 (반복문)
int binarySearch(vector<int>& arr, int target, int start, int end) {
    while (start <= end) {
        int mid = (start + end) / 2;

        //1. 왼쪽에 있을 때
        if (target < arr[mid]) {
            end = arr[mid] - 1;
        }
        //2. 오른쪽에 있을 때
        else if (target > arr[mid]) {
            start = arr[mid] + 1;
        }
        //3. 같을 때
        else {
            return mid;
        }
    }
    return -1;
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