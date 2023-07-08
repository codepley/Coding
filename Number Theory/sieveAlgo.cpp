#include<bits/stdc++.h>
using namespace std;
#define N 100

void sieve(vector<bool>& n) {
   for(int i=0; i<n.size(); i++){
      if(n[i] == 1){
         for(int j=i*i; j<n.size(); j+=i){  // if we do j=i*i then it is more optimised than i+i
            n[j] = 0;
         }
      }
   }
   int ct=0;
   for(auto u: n){
      // if(u==1) ct++;
      cout << u << " ";
   }
   cout << ct << endl;
}

int main() {
   vector<bool> n(N, 1);
   n[0] = n[1] = 0;
   sieve(n);
}