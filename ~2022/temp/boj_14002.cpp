#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[1001]; //input array
int vec[1001]; //�� ���� idx�� ����� �����ϴ� �迭
int dp[1001]; //�ͳ��� : i��° ���� �� ���� �κм����� ���̸� ����

int n;

void go_14002(int num){
    if(vec[num]==-1){
        cout<<arr[num]<<" ";
        return;
    }

    int next = vec[num];
    go_14002(next);
    cout<<arr[num]<<" ";

}

int main(void){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    for(int i=0;i<n;i++){
        dp[i] = 1; //
        vec[i] = -1; //�湮X
        for(int j=0;j<i;j++){
            if(dp[i]<dp[j]+1 && arr[j]<arr[i]){
                dp[i] = dp[j] + 1;
                vec[i] = j;
            }
        }
    }

    //���� ������� dp �迭�� idx
    int answer=0;
    int idx;
    for(int i=0;i<n;i++){
        if(answer<dp[i]){
            answer=dp[i];
            idx = i;
        }
    }

    cout<<answer<<'\n';

    //��ͷ� ������
    go_14002(idx);

    return 0;
}