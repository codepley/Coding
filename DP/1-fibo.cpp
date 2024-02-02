// memoization demonstration using fibonacci problem
// 0 1 1 2 3 5 8 ....

#include<bits/stdc++.h>
using namespace std;

// 0 1 1 2 3 5

int fib(int n, vector<int> &memo) {
   if(n==0 || n==1){
      return memo[n] = n;
   }
   if(memo[n] != -1){
      return memo[n];
   }
   return memo[n] = fib(n-1, memo) + fib(n-2, memo);
}

int main() {
   int n = 7;
   vector<int> memo(n+2, -1);
   cout << fib(n, memo) << endl;
}