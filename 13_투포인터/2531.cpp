#include <bits/stdc++.h>
using namespace std;
int n, d, k, c; //접시수, 초밥수, 연속해서먹는접시수, 쿠폰번호
int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);
    cin >> n >> d >> k >> c;
    vector<int> arr(n);
    for (int i = 0;i < n;i++) {
        cin >> arr[i];
    }

    //1. 연속해서 먹는 접시 수 만큼, 뒤에 앞의 초밥들을 그대로 넣어준다.
    for (int i = 0;i < k;i++) {
        arr.push_back(arr[i]);
    }

    int maxValue = 0;

    int start = 0, end = k-1;
    bool isExist = false;
    int couponIdx = 0;

    map<int, int> chk;

    //1. 처음 생성
    for(int i=0;i<k;i++) {
        chk.insert({arr[i],arr[i]});
        if(arr[i] == c){
            couponIdx = i;
            isExist = true;
        } 
    }

    if(isExist == true) {
        maxValue = (maxValue,)
    }
    while(start <= end && start <= n-k && end <= n-1) {


        //1.coupon이 있는지, 
        if(isExist) {
            maxValue = max(maxValue, (int)chk.size()+1);            
            isExist = false;
        }
        else {
            chk.erase(arr[start]);
            chk.insert({arr[end+1], arr[end+1]});
        }
        //다음 케이스 진행
        start++;
        end++;
    }

    cout<<maxValue<<"\n";
    return 0;
}