#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(int i=0;i<commands.size();i++){
        //1,5,2,6,3,7,4
        //commands[i]번째의 첫번째 : 시작점, 두번째 끝점, 세번째 원하는 위치
        int a = commands[i][0]; //2
        int b = commands[i][1]; //5
        int c = commands[i][2]; //3

        vector<int> temp;

        for(int j=a-1;j<b;j++){
            temp.push_back(array[j]);
        }

        sort(temp.begin(),temp.end());
        answer.push_back(temp[c-1]); //답 넣기
    }
    
    return answer;
}