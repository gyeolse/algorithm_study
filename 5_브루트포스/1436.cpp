#include <bits/stdc++.h>
#define MAX 6669999

using namespace std;
vector<int> arr;

int main() {
    int n;
    cin >> n;

    //2억번까지 가능
    for (int i = 1;i <= MAX;i++) {
        string s = to_string(i);
        if (s.size() < 3) continue;
        else if (s.size() == 3) {
            if (s == "666") arr.push_back(stoi(s));
        }
        else {
            //연속으로 6이 존재하는지 확인
            // 16660 
            for (int j = 0;j < s.size() - 2;j++) {
                string t_ = s.substr(j, 3); //166
                if (t_ == "666") {
                    arr.push_back(stoi(s));
                    break;
                }
            }
        }
    }

    // for(int i=0;i<100;i++) {
    //     cout<<arr[i]<<endl;
    // }
    cout<<arr[n-1]<<endl;
    return 0;
}