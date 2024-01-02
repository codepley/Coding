#include<bits/stdc++.h>
using namespace std;

void solve(string ip, string op) {
   if(ip.length() == 0){
      cout << op << " ";
      return;
   }
   string op1 = op;
   string op2 = op;
   op1 = op + ip[0];
   op2 = op + "-" + ip[0];
   ip.erase(ip.begin()+0);
   solve(ip, op1);
   solve(ip, op2);
   return;
}

int main() {
   string s; cin >> s;
   string op = "";
   op = op+s[0];
   s.erase(s.begin()+0);
   solve(s, op);
}