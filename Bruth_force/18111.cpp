#include <bits/stdc++.h>
using namespace std;

int n, m, inven;
int arr[500][500];
int maxElement = 0;
int minElement = 987654321;
vector<pair<int,int>> res;
int main() {
    //1. input, max, min값 
    cin >> n >> m >> inven;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            cin >> arr[i][j];
            //max, min 값 저장 
            maxElement = max(maxElement, arr[i][j]);
            minElement = min(minElement, arr[i][j]);
        }
    }

    //2. max값으로 만들어주기
    // max 보다 크다면, 차이만큼, inven에 넣어주고, 들이는 시간은 *2
    // max 보다 작다면, 차이만큼, inven에서 가져오고, 들이는 시간 * 1
    // 만약, inven에 값이 존재하지 않는다면, 불가능하므로, 바로 break;
    int totalTime = 0;
    int tempInven = inven;
    bool isAvailable = true;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            if(isAvailable == true ) {
                if(maxElement > arr[i][j]) {
                    if(tempInven <= 0) {
                        isAvailable = false;
                        break;
                    }
                    int gap = maxElement - arr[i][j];
                    totalTime += gap;
                    tempInven -= gap;
                }
            }
        }
    }
    //3. 결과를 res에 push
    if(isAvailable == true ) {
        res.push_back({totalTime, maxElement});
    }

    //4. min값으로 만들어주기. min 보다 크다면, 무조건 인벤토리에서 더해주기만 하면 됨. 
    totalTime = 0;
    tempInven = inven;
    isAvailable = true;
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(isAvailable == true) {
                if(minElement < arr[i][j]) {
                    int gap = arr[i][j] - minElement;
                    totalTime += (gap*2);
                    tempInven += gap;
                }
            }
        }
    }

    //4. 결과를 res에 push 
    res.push_back({totalTime, minElement});
    sort(res.begin(),res.end());

    // for(int i=0;i<res.size();i++) {
    //     cout<<res[i].first<<" "<<res[i].second<<"\n";
    // }
    cout<<res[0].first<<" "<<res[0].second<<"\n";

    return 0;
}