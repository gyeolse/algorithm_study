//N-Queen. ��Ʈ��ŷ
#include <iostream>
using namespace std;
int N;
int ans=0;
bool a[15][15];

//check �Լ� : ���� �� �ִ� �ڸ�����
bool check(int r, int c){
    // l������ ���� üũ
    for(int i=0;i<N;i++){
        if(i==r) continue;
        if(a[i][c]){
            return false;
        }
    }
    // \���� üũ (1,1)�̶�� (0,0). (2,2)���, (1,1) (0,0)....
    int x=r-1;
    int y=c-1;

    while(x>=0 && y>=0){ //x,y ����϶��� loop
        if(a[x][y]==true){
            return false;
        }
        x-=1;
        y-=1;
    }

    // /���� üũ. (2,2)��� (1,3) (0,4)
    x=r-1;
    y=c+1;

    while(x>=0 && y<N){ //y�� ���� ������ y>=0�̸� �ȵ�. y<n�̾����. y�� ��� �����ϰ� �ִ�. 
        if(a[x][y]==true){
            return false;
        }

        x-=1;
        y+=1;
    }

    return true;
}

//calc �Լ� : �� �ڸ� �����ϱ�
void calc(int r){
    if(r==N){
        ans +=1;
    }
    for(int c=0;c<N;c++){ //c=column
        a[r][c] = true;
        if(check(r,c)){ //���� �� �ִ� �ڸ�����
            calc(r+1); //���
        }
        //if�� ���� ���� ���� ���
        a[r][c]=false;        
    }
}


int main(void){
    cin>>N;
    calc(0);

    cout<<ans<<"\n";

    return 0;
}