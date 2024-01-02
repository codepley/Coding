#include<bits/stdc++.h>
using namespace std;

void solve(string op, int open, int close, vector<string> &v) {
   if(open==0 && close==0){
      v.push_back(op);
      return;
   }

   if(open != 0) {
      string op1 = op;
      op1 = op1 + '(';
      solve(op1, open-1, close, v);
   }

   if(open < close) {
      string op2 = op;
      op2 = op2 + ')';
      solve(op2, open, close-1, v);
   }
}

int main() {
   int n; cin >> n;
   vector<string> v;
   solve("", n, n, v);
   for(auto u: v) {
      cout << u << " ";
   }
   cout << endl << v.size() << endl;
}