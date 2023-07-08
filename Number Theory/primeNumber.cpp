#include<bits/stdc++.h>
using namespace std;

// O(n) solution
bool isPrime(int n) {
   for(int i=2; i<n-1; i++){
      if(n%i==0){
         return false;
      }
   }
   return true;
}

// O(sqrt(n)) solution
bool isPrimefast(int n) {
   for(int i=2; i*i<=n; i++){
      if(n%i==0){
         return false;
      }
   }
   return true;
}

int main() {
   int n; cin >> n;
   cout << isPrimefast(n) << endl;
   cout << isPrime(n) << endl;
}