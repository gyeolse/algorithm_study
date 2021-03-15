#include <bits/stdc++.h>
using namespace std;

long long n;
long long arr[1000001];
long long b, c;

long long totalPerson;
int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);
    //1. input
    cin >> n;
    for (long long i = 0;i < n;i++) {
        cin >> arr[i];
    }
    cin >> b >> c; //총 감독관, 부 감독관

    //2. 총 감독관을 모두 넣은 후 +1씩 해주기 
    for (long long i = 0;i < n;i++) {
        arr[i] -= b;
        totalPerson++;
    }

    for(long long i=0;i<n;i++) {

        if(arr[i] > 0 ) {
            long long mok = arr[i]/c;
            long long na = arr[i]%c;

            totalPerson += mok;
            if(na > 0 ) totalPerson++;
        }

    }

    cout<<totalPerson<<"\n";
    return 0;
}