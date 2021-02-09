/**
 * 1. 값 K를 만드는데 필요한 최솟값 => 그리디
 * 2. 구현
 *  1) 오름차순으로 주어짐 -> 내림차순으로 바꿔주기 
 *  2) 나눌 수 있는 동전이어야 함 -> 나눌 수 있는 동전까지 가기
 *  3) 나눠서 몫이 나오면 몫 : 동전 갯수, 나머지 : 남은 동전
 *  4) 0이 될 때까지 반복 후 탈출
*/

#include <bits/stdc++.h>
using namespace std;
int n,k;
vector<int> vec;

int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);
    cin>>n>>k;
    for(int i=0;i<n;i++) {
        int x; cin>>x; vec.push_back(x);
    }
    sort(vec.begin(),vec.end(),greater<>());

    int ans = 0;
    int tmp = k;
    
    for(int i=0;i<vec.size();i++) {
        if(tmp/vec[i] == 0) continue;
        else {
            ans += tmp/vec[i];
            tmp = tmp%vec[i];
        }
    }

    cout<<ans<<endl;
    return 0;
}