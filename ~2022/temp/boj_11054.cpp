#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n; //������ ����

// ****** �տ��� LIS �ڿ������� LIS �ؼ� ���� �� -1 (�ߺ��� ��) ���־�� ��.
// �տ��� LIS, �ڿ��� LIS��
// �׷��Ƿ�, ���� �ݴ����� LIS�� ���ֹǷ�, �ش� idx������ ������� ���� ���ϱⰡ ������.
// �̶� �տ��� LIS�� �ش� idx������, �ڿ��� LIS�� �׶��������� �׷��Ƿ�,
// �ش� idx�� �ߺ��� �� �� �����Ƿ� ������ -1�� ���ִ� ��. �ϴٺ��� ���ذ�

int main(void){
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    vector<int> dp1(n);
    vector<int> dp2(n);

    //��������
    for(int i=0;i<n;i++){
        dp1[i] = 1;
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i] && dp1[i]<dp1[j]+1){
                dp1[i]=dp1[j] + 1;
            }
        }
    }
    
    //�ݴ뿡�� �����ϱ� �̰͵� ���ǹ��� ����
    //�ε��� �ٷ�� �� �������ְ�, ���߿� �� ���� �Ǹ� �� �̷��� �Ǵ��� �����س��°� ����Ʈ
    for(int i=n-1;i>=0;i--){
        dp2[i] = 1;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[i] && dp2[i]<dp2[j]+1){
                dp2[i] = dp2[j] + 1;
            }
        }
    }

    int answer = 0;
    for(int i=0;i<n;i++){
        if(answer<dp1[i]+dp2[i]-1){
            answer=dp1[i]+dp2[i]-1;
        }
    }

    cout<<answer<<'\n';

    return 0;
}