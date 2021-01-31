#include <bits/stdc++.h>
using namespace std;

bool comp(string& a, string& b) {
    return a + b > b + a;
}
string solution(vector<int> numbers) {
    vector <string> numString;
    for (int i = 0;i < numbers.size();i++) {
        numString.push_back(to_string(numbers[i]));
    }
    string answer = "";
    sort(numString.begin(), numString.end(), comp);
    for (int i = 0;i < numString.size();i++) {
        answer += numString[i];
    }

    if (answer[0] == '0') return "0";
    return answer;
}