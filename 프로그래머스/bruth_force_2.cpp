#include <bits/stdc++.h>
using namespace std;
bool prime[10000000] = { false, };

int solution(string numbers) {
    int answer = 0;
    int max = 0; int tmp = 0;
    sort(numbers.begin(), numbers.end(), greater<int>());
    max = stoi(numbers); //제일 최대

    for (int i = 2; i <= max;i++) {
        for (int j = i + i;j <= max;j += i)
            prime[j] = true;
    }

    sort(numbers.begin(), numbers.end());

    do {
        // string str="";
        // tmp = 0;
        // for(int j=0;j<numbers.size();j++) {
        //     str+= numbers[j];
        //     tmp = stoi(str);
        //     if( tmp > 1 && prime[tmp] == false) {
        //         answer++;
        //         prime[tmp] = true;
        //     }
        // }
        string str = "";
        for (int j = 0;j < numbers.size();j++) {
            str += numbers[j];
            cout << str << " ";

        }
        cout << endl;
    } while (next_permutation(numbers.begin(), numbers.end()));
    return answer;
}