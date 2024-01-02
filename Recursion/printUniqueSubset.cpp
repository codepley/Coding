#include<bits/stdc++.h>
using namespace std;

void findUniqueSubset(string ip, string op, set<string> &vals){
   if(ip.length() == 0){
      vals.insert(op);
      return;
   }
   string op1 = op;
   string op2 = op;
   op2.push_back(ip[0]);
   ip.erase(ip.begin() + 0);
   findUniqueSubset(ip, op1, vals);
   findUniqueSubset(ip, op2, vals);
}

int main() {
   string s;
   cin >> s;
   set<string> vals;
   findUniqueSubset(s, " ", vals);
   for(auto u: vals){
      cout << u << " ";
   }
}