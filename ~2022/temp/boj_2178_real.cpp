#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

//������ �迭������ �Ÿ� �����ϱ�. 
//flood fill
int n,m;

string board[102]; //board �迭 ����. string ��ü�� char�� �̷���� �迭�̱� ������ [][]�̷��� ������ �ϴ� ���� �����ϴٴ� ���� �����ϰ� �־���
int result[102][102];
int dirX[4] = {1,0,-1,0};
int dirY[4] = {0,1,0,-1};

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>board[i];
    }
    for(int i=0;i<n;i++){
        fill(result[i],result[i]+m,-1); //fill �Լ�. �ʱ�ȭ�Լ�. memset�̶� �ϴ� ������ ����ϴٰ� �����ϸ� ��. 
    }
//ù��° ���ҷ� start
    queue<pair<int,int>> que;
    que.push({0,0});
    result[0][0]=0; //result �迭�� ���� ��ſ�, visit�迭�� �� �ʿ䰡 ������ �ֳ��ϸ�, -1�� �ʱ⿡ ������ ���־��� ������, -1�� �̹湮�� ���ϱ� ������.

    while(!que.empty()){
        pair<int,int> cur = que.front(); que.pop();

        for(int i=0;i<4;i++){
            int nX = cur.first + dirX[i];
            int nY = cur.second + dirY[i];
            if(nX<0||nX>=n||nY<0||nY>=m) continue;
            if(result[nX][nY]>=0||board[nX][nY]!='1') continue;
            result[nX][nY] = result[cur.first][cur.second] + 1; //�ٷ� �� ������ + 1 �� ���� �ǰ���.
            que.push({nX,nY});
        }
    }
    //queue

    cout<<result[n-1][m-1]+1<<"\n"; //�������� ó�� ���۵� 1�� �ļ� 1�� �����ִ� ���� �´�
    return 0;    
}