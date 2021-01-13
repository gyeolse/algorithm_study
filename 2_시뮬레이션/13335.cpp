#include <bits/stdc++.h>
using namespace std;

int n, w, l; //트럭의 수, 다리 길이, 최대 하중

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> w >> l; //트럭의 수, 다리 길이, 최대 하중
    queue<int> truck; //트럭으로 이루어진 큐
    for (int i = 0;i < n;i++) {
        int curTruck;
        cin >> curTruck;
        truck.push(curTruck);
    }
    vector<int> arrived;
    queue<pair<int, int>> bridge;

    int totalWeight = 0; //다리 위에 올라간 무게

    int arrived_time = 0;
    while (arrived.size() < n) { //모든 트럭이 도착지에 도착할 때까지 반복
        arrived_time++;

        //다리 > 도착지로 옮기기, 트럭 > 다리로 옮기기 순서에 따라 답이 다름
        //이유 ?  : 첫번쨰에서 쳐 집어넣고, 바로 실행되버림. arrived_time 카운팅 안됨 
        
        //다리에서 도착지로 옮기기
        if (bridge.size() > 0) {
            pair<int, int> frontTruck = bridge.front();
            if (frontTruck.second == arrived_time) { //도착 시간에 도달
                bridge.pop();
                totalWeight -= frontTruck.first;
                arrived.push_back(frontTruck.first);
            }
        }

        //트럭을 다리에 올리기
        if (truck.size() > 0) { //범위 체크
            int frontTruck = truck.front();
            //현재 다리 무게에 현재 트럭의 무게가 l보다 작을 떄 
            if (totalWeight + frontTruck <= l) {
                //현재 다리 길이가 꽉 차있지 않을 때 
                if (bridge.size() <= w) {
                    truck.pop();
                    totalWeight += frontTruck;
                    //시간 + 최대 길이를 시간으로 세팅해줌.
                    bridge.push({ frontTruck, arrived_time + w });
                }
            }
        }
    }

    cout << arrived_time << "\n";
    return 0;
}