#include <bits/stdc++.h>
using namespace std;
#define MAX 100010 //MAX값을 잘못 지정해줘서, 어이없게 틀리고 있었다. 

int n;
long long s;
long long inputArr[MAX];
long long sumArr[MAX];
int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);
    cin >> n >> s;
    for (int i = 0;i < n;i++) {
        cin >> inputArr[i];
    }

    //1. 부분합을 구해서 저장해두기
    for (int i = 0;i < n;i++) {
        if (i == 0) {
            sumArr[i] = inputArr[i];
        }
        else {
            sumArr[i] = inputArr[i] + sumArr[i - 1];
        }
    }

    //2. 투 포인터 사용 
    int onePtr = 0; int twoPtr = 0; //S보다 작을 때, twoPtr 이동, S보다 클 때, onePtr 이동 
    int totalLength = 987654321; //추후 변경해야함

    while(twoPtr < n && onePtr <= twoPtr) {
        int cur = sumArr[twoPtr] - sumArr[onePtr-1];
        // cout<<"cur val: "<<cur<<endl;
        // cout<<"curPtr: "<<onePtr<<" "<<twoPtr<<endl;
        if(cur < s) { //s보다 작을 때
            twoPtr++;
        }
        else if (cur == s) {
            totalLength = min(totalLength, (twoPtr-onePtr)+1);
            twoPtr++;
        }
        else if(cur > s) {
            totalLength = min(totalLength, (twoPtr-onePtr)+1);
            onePtr++;
        }
    }

    if(totalLength == 987654321) {
        cout<<"0"<<"\n";
    }
    else {
        cout<<totalLength<<"\n";    
    }
    return 0;
}