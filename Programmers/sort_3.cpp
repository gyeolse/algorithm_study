#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    //1. 정렬
    sort(citations.begin(), citations.end());

    //2. max_elem, min_elem
    int start = 0;    //이게 0이 포인트네 
    int end = citations[citations.size() - 1];

    //3. binary_search
    while (start <= end) {
        int mid = (start + end) / 2;

        int highH = 0;
        for (int i = 0;i < citations.size();i++) {
            if (mid <= citations[i]) {
                highH++;
            }
        }

        //1. 왼쪽으로 이동
        if (highH < mid) {
            end = mid - 1;
        }
        //2. 오른쪽으로 이동
        else {
            answer = mid;
            start = mid + 1;
        }
    }
    return answer;
}