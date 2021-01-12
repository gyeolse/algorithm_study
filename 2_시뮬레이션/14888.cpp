#include <bits/stdc++.h>
using namespace std;

#define INF 987654321
int n;
vector<int> input;
vector<int> oper; //연산자들 모음

int main() {
    //입력
    cin >> n;
    for (int i = 0;i < n;i++) {
        int temp;
        cin >> temp;
        input.push_back(temp);
    }

    for (int i = 0;i < 4;i++) {
        int temp;
        cin >> temp;
        if (i == 0) {
            for (int j = 0;j < temp;j++) {
                oper.push_back(1);
            }
        }
        else if (i == 1) {
            for (int j = 0;j < temp;j++) {
                oper.push_back(2);
            }
        }
        else if (i == 2) {
            for (int j = 0;j < temp;j++) {
                oper.push_back(3);
            }
        }
        else if (i == 3) {
            for (int j = 0;j < temp;j++) {
                oper.push_back(4);
            }
        }
    }
    // if(oper.size() < n-1) {
    //     for(int i=0;i<((n-1)-oper.size());i++){
    //         oper.push_back(0);
    //     }
    // }

    sort(oper.begin(), oper.end());
    //연산자들 vector(oper) 에 입력까지 완료

    //음수가 나올 수 있음을 잊고 있어서, max를 0으로 세팅함. 이런거 틀리지 말자.
    int mx_value = -INF;
    int mn_value = INF;
    do
    {
        int temp_value = input[0]; //첫번쨰꺼를 넣어야함
        for (int i = 0;i < input.size();i++) {
            if (i == input.size() - 1) break;
            if (oper[i] == 1) {
                temp_value += input[i + 1];
            }
            else if (oper[i] == 2) {
                temp_value -= input[i + 1];
            }
            else if (oper[i] == 3) {
                temp_value *= input[i + 1];
            }
            else if (oper[i] == 4) {
                temp_value /= input[i + 1];
            }
            //아무것도 없는 경우는 들어올수가 없구나
        }

        //이번 루프에서의 값 비교 
        mx_value = max(mx_value, temp_value);
        mn_value = min(mn_value, temp_value);
    } while (next_permutation(oper.begin(), oper.end()));

    //최대값, 최소값 출력
    cout << mx_value << "\n";
    cout << mn_value << "\n";
    return 0;
}