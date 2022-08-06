#include<iostream>
#include<string>

using namespace std;

int main() {
   long long n;
   int arr[9] = { 0 };
   cin >> n;
   while (n > 0) {
      long long m = n % 10;
      cout<<m<<" ";
      if (m == 9) {
         arr[6]++;
      }
      else {
         arr[m]++;
      }
      n = n / 10;
      cout<<n<<"\n";
   }

   for(int i=0;i<9;i++){
       cout<<arr[i]<<" ";
   }
   cout<<endl;

   int max = 0;
   for (int i = 0; i < 9; i++) {
      if (i == 6) {
         arr[i] = arr[i] / 2 + arr[i] % 2;
      }
      if (max < arr[i]) {
         max=arr[i];
      }
   }
   cout << max;


}