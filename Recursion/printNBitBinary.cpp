// print N-bit binary number having no.s of 1 greater than no.s of 0 for any given prefix

#include<bits/stdc++.h>
using namespace std;

void solve(int n, int one, int zero, string op){
   if(n==0){
      cout << op << " ";
      return;
   }
   // if(one != 0){
      // cout << "here";
      string op1 = op;
      op1 = op1 + '1';
      solve(n-1, one+1, zero, op1);
   // }
   if(zero < one){
      string op2 = op;
      op2 = op2 + '0';
      solve(n-1, one, zero+1, op2);
   }
}

int main() {
   int n; cin >> n;
   solve(n, 0, 0, "");
}