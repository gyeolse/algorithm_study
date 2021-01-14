#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define X first
#define Y second
//define �ڿ� ; �ȵ���. �̰Ŷ����� ���� ������ ã�Ҵ� ����

int arr[502][502];
bool visit[502][502];
int dirX[4]={1,0,-1,0};
int dirY[4]={0,1,0,-1};

int n,m;

//�׸��� �ϳ��� ���� ���, ���� ���� �׸��� ���̴� 0
int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    int picCount=0; //�׸��� ����
    int picMax=0; //�׸��� ����
//queue�� ù��° �� �ֱ�    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==0||visit[i][j]==true) continue; // 0�̰ų� �湮�ϸ� �Ѿ��
            picCount++; //���⼭ count++�� �Ѵ�. ��. ���ο� �����̶� ���̴ϱ� ���⼭ �ϸ� �Ǵ±���. �����غ��� �����ѵ�
            queue<pair<int,int>> que; //que ������ ���ش�. 
            visit[i][j]=true;
            que.push({i,j});
            int area=0; //0���� ����
            while(!que.empty()){
                area++; //������ 1����
                pair<int,int> cur = que.front(); que.pop(); //cur.X, cur.Y�� ����
                for(int k=0;k<4;k++){
                    int nx = cur.first + dirX[k];
                    int ny = cur.second + dirY[k];
                    if(nx<0||nx>=n||ny<0||ny>=m) continue;
                    if(visit[nx][ny] || arr[nx][ny]!=1) continue;
                    visit[nx][ny]=true;
                    que.push({nx,ny});
                }
            }
            //max�� �������ִ� �Լ�
            picMax=max(picMax,area);
        }
    }
    cout<<picCount<<"\n"<<picMax;
    return 0;
}