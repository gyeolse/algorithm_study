#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int n,m,k;
int dirX[4]={1,0,-1,0};
int dirY[4]={0,1,0,-1};
int dist[101][101];
int board[101][101];

int main(void){
    cin>>n>>m>>k;
    for(int i=0;i<k;i++){
        int nx1,ny1,nx2,ny2; //0,2,4,4
        cin>>nx1>>ny1>>nx2>>ny2;
        for(int i=nx1;i<nx2;i++){
            for(int j=ny1;j<ny2;j++){
                board[j][i]=-1;
//                cout<<"("<<i<<","<<j<<")"<<endl;
            }
        }
    }

    queue<pair<int,int>> que;
    while(!que.empty()){
        
    }
}