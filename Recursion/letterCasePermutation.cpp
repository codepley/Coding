// i/p = a1b2 
// o/p = a1b2 a1B2 A1b2 A1B2

#include<bits/stdc++.h>
using namespace std;

void solve(string ip, string op) {
   if(ip == ""){
      cout << op << " ";
      return;
   }
   if(isalpha(ip[0])){
      string op1 = op;
      string op2 = op;
      op1.push_back(tolower(ip[0]));
      op2.push_back(toupper(ip[0]));
      ip.erase(ip.begin()+0);
      solve(ip, op1);
      solve(ip, op2);
   }else{
      string op1 = op;
      op1.push_back(ip[0]);
      ip.erase(ip.begin()+0);
      solve(ip, op1);
   }
}

int main() {
   string s; cin >> s;
   solve(s, "");
}