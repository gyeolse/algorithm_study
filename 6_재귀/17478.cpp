#include <bits/stdc++.h>
using namespace std;

int n;
string intro = "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.";
string line = "____";
string question = "\"재귀함수가 뭔가요?\"";
string answer[3] ={ "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.", "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.", "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"" };
string realAnswer = "\"재귀함수는 자기 자신을 호출하는 함수라네\"";
string outro = "라고 답변하였지.";

void func(int idx) {
    if(n==idx) {
        string tempS;
        for(int i=0;i<idx;i++) {
            tempS += line;
        }
        cout<<tempS<<question<<"\n";
        cout<<tempS<<realAnswer<<"\n";
        cout<<tempS<<outro<<"\n";        
        return;
    }

    string curLine;
    for(int i=0;i<idx;i++) {
        curLine += line;
    }

    cout<<curLine<<question<<"\n";
    for(int i=0;i<3;i++) {
        cout<<curLine<<answer[i]<<"\n";
    }

    func(idx+1);
    cout<<curLine<<outro<<"\n";
}

int main() {
    cin>>n;
    cout<<intro<<"\n";
    func(0);
    return 0;
}