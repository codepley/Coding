#include<bits/stdc++.h>
using namespace std;

void solve(string ip, string op) {
   if(ip == ""){
      cout << op << " ";
      return;
   }
   string op1 = op;
   string op2 = op;
   op1 = op1 + ip[0];
   op2 = op2 + char(ip[0] - 32);
   ip.erase(ip.begin() + 0);
   // cout << op1 << " " << op2 << " " << ip << endl;
   solve(ip, op1);
   solve(ip, op2);
}

int main() {
   string s;
   cin >> s;
   solve(s, "");
}