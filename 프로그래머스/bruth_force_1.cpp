#include <bits/stdc++.h>
using namespace std;
int supo_one[5] = { 1,2,3,4,5 };
int supo_two[8] = { 2,1,2,3,2,4,2,5 };
int supo_three[10] = { 3,3,1,1,2,2,4,4,5,5 };
int answerSheet[3];

vector<int> solution(vector<int> answers) {
    for (int i = 0;i < answers.size();i++) {
        int curAnswer = answers[i];
        if (supo_one[i % 5] == curAnswer) answerSheet[0]++;
        if (supo_two[i % 8] == curAnswer) answerSheet[1]++;
        if (supo_three[i % 10] == curAnswer) answerSheet[2]++;
    }
    vector<pair<int, int>> answer; //맞춘 수, idx
    int max_elem = 0;
    for (int i = 0;i < 3;i++) {
        answer.push_back({ answerSheet[i],i + 1 });
        max_elem = max(answerSheet[i], max_elem);
    }
    vector<int> res;
    for (int i = 0;i < 3;i++) {
        if (max_elem == answer[i].first) res.push_back(answer[i].second);
    }
    return res;
}