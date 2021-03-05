#include <bits/stdc++.h>
using namespace std;

int n;
int chk[10];

int max_ = 0;
int min_ = 987654321;

bool isAvailable(vector<int> vec) {
    for(int i=0;i<vec.size()-1;i++) {
        if(chk[i] == 0 && vec[i] > vec[i+1]) {
            return false;
        }
        else if(chk[i] == 1 && vec[i] < vec[i+1]) {
            return false;
        }
    }
    return true;
}
int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0;i < n;i++) {
        char x; cin >> x;
        if (x == '<') {
            chk[i] = 0;
        }
        else {
            chk[i] = 1;
        }
    }

    vector<int> maxVec;
    for(int i=9;i>9-(n+1);i--) {
        maxVec.push_back(i);
    }

    do
    {
        //맞는 조건이 있으면 바로 break. 그 애가 바로 minVec.
        if(isAvailable(maxVec)) {
            break;
        }
    } while (prev_permutation(maxVec.begin(),maxVec.end()));
    

    vector<int> minVec;
    for(int i=0;i<n+1;i++) {
        minVec.push_back(i);
    }

    do
    {
        //맞는 조건이 있으면 바로 break. 그 애가 바로 minVec.
        if(isAvailable(minVec)) {
            break;
        }
    } while (next_permutation(minVec.begin(),minVec.end()));


    for(int i=0;i<maxVec.size();i++) {
        cout<<maxVec[i];
    }
    cout<<"\n";


    for(int i=0;i<minVec.size();i++) {
        cout<<minVec[i];
    }
    cout<<"\n";
    return 0;
}