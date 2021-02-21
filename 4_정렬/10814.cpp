#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int, pair<int, string>> a, pair<int, pair<int, string>> b) {

    if (a.first == b.first) {
        //2. 먼저 가입한 순 == 오름차순
        return a.second.first < b.second.first;
    }
    //1. 나이 어린순 == 오름차순 
    else {
        return a.first < b.first;
    }
}
int main() {
    int n;
    vector<pair<int, pair<int, string>>> vec;

    cin >> n;
    for (int i = 0;i < n;i++) {
        int a; string b;
        cin >> a >> b;
        vec.push_back({ a,{i,b} });
    }

    sort(vec.begin(), vec.end(), comp);
    for (int i = 0;i < vec.size();i++) {
        cout << vec[i].first << " " << vec[i].second.second << "\n";
    }
    return 0;
}