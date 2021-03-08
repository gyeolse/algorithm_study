#include <bits/stdc++.h>
using namespace std;
int n,m;
int board[51][51];

bool checkEqual(int i,int j,int line) {
    if(board[i][j] == board[i+line][j]) {
        if(board[i+line][j] == board[i+line][j+line]) {
            if(board[i+line][j+line] == board[i][j+line]) {
                return true;
            }
        }
    }
    return false;
}

bool isAvailable (int l) {
    //board 내에서 정사각형이 순회할 수 있는지 확인 
    //n-l, m-l 중 하나라도 0 미만이면 false
    if(n-l < 0 || m-l < 0) return false;
    return true;
}

// 꼭짓점에 쓰여있는 수가 모두 같은 가장 큰 정사각형 찾기 
int main() {
    //1. input
    cin>>n>>m;
    for(int i=0;i<n;i++){
        string s; cin>>s;
        for(int j=0;j<s.size();j++) { 
             board[i][j] = s[j];           
        }
    }

    //2. 정사각형을 늘려가며 확인하기
    int line = 1;
    int res = 1;

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            for(int k=1;k<min(n,m);k++) { //이렇게 하면 굳이 작은 값을 안구해도 된다
                if(i+k < n && j + k < m && checkEqual(i,j,k)) {
                    res = max(res, k+1);
                } 
            }
        }
    }

    cout<<res*res<<"\n";    
    return 0;
}