// https://aerocode.net/392

#include <bits/stdc++.h>
using namespace std;
int n;
int arr[1001];
bool chk[1000001]; //값이 비었는지 확인함

int main() {
    cin >> n;
    for (int i = 0;i < n;i++) {
        cin >> arr[i];
    }
    //1 1 2 3 6 7 
    sort(arr, arr + n);

    int weight = 0;

    //0~weight까지는 이어져있고,
    //새롭게 들어오는 arr[i]가 weight+1보다 크다면, break 해주어야함. 

    for (int i = 0;i < n;i++) {
        if(arr[i] > weight + 1) {
            break;
        }
        weight +=arr[i];
    }
    cout<<weight+1<<endl;
    return 0;
}