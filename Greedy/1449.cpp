#include <bits/stdc++.h>
using namespace std;

int n,l;
int pipe[1001];
int tapeCount = 1;

int main() {
    cin>>n>>l;

    for(int i=0;i<n;i++) {
        cin>>pipe[i];
    }

    sort(pipe, pipe+n);

    int tapePosition = pipe[0]; 
    //1. tape의 위치와 현재 위치를 비교 
    for(int i=0;i<n;i++) {
        int temp = pipe[i] - tapePosition;
        //2. 위치의 차이가 l보다 크다면 tape의 위치를 현재 위치로 세팅해주고, tape의 갯수를 더함
        if(temp > l-1 ) { //테이프의 시작과 끝을 0.5로 해야하므로 -1을 해야한다. 
            tapeCount++;
            tapePosition = pipe[i];
        }
        //3. 위치의 차이가 l보다 작다면, 하나로 해결할 수 있으므로, 다음 위치로 이동
        // cout<<"curTape : "<<tapePosition<<" temp : "<<temp<<endl;
    }

    cout<<tapeCount<<"\n";
    return 0;
}