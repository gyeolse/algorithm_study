#include <bits/stdc++.h>
using namespace std;

int n;


struct grade
{
    int korean;
    int english;
    int math;
    string name;
};

struct compare {
    bool operator()(grade a, grade b) {
        if (a.korean == b.korean) {
            if (a.english == b.english) {
                if (a.math == b.math) {
                    //4. 모든 점수 같은 경우
                    return a.name > b.name;
                }
                //3. 수학 점수가 감소하는 순서로 
                return a.math < b.math;
            }
            //2. 영어 점수가 증가하는 순서로
            return a.english > b.english;
        }
        //1. 국어 점수가 감소하는 순서로
        return a.korean < b.korean;
    }
};

priority_queue<grade, vector<grade>, compare> vec;

int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0;i < n;i++) {
        grade temp;
        cin >> temp.name >> temp.korean >> temp.english >> temp.math;
        vec.push(temp);
    }

    for (int i = 0;i < n;i++) {
        grade temp = vec.top(); vec.pop();
        // cout << temp.korean << " " << temp.english << " " << temp.korean << " "<<temp.name<<"\n";
        cout <<temp.name<<"\n";
    }

    return 0;
}