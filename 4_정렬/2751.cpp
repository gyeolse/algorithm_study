#include <bits/stdc++.h>
using namespace std;
#define MAX 1000001
int n;
int list_[MAX];
int sorted[MAX];

void merge(int left, int mid, int right) {
    int i = left; int k = left; int j = mid + 1;

    while (i <= mid && j <= right) {
        if (list_[i] < list_[j]) {
            sorted[k++] = list_[i++];
        }
        else {
            sorted[k++] = list_[j++];
        }
    }

    // 남은 것들 처리 
    if (i > mid) {
        for (int x = j; x <= right; x++) {
            sorted[k++] = list_[x];
        }
    }
    else {
        for (int x = i; x <= mid; x++) {
            sorted[k++] = list_[x];
        }
    }
    // 옮기기
    for (int x = left; x <= right; x++) {
        list_[x] = sorted[x];
    }
}

void mergeSort(int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(left, mid);
        mergeSort(mid + 1, right);
        merge(left, mid, right);
    }
}
int main() {
    cin >> n;
    for (int i = 0;i < n;i++) {
        cin >> list_[i];
    }

    // mergeSort
    mergeSort(0, n - 1);

    for (int i = 0;i < n;i++) {
        cout << list_[i] << "\n";
    }
    return 0;
}