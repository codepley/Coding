#include<bits/stdc++.h>
using namespace std;

void findSubset(string ip, string op){
   if(ip.length() == 0){
      cout << "\"" << op << "\""<< endl;
      return;
   }
   string op1 = op;
   string op2 = op;
   op2.push_back(ip[0]);
   ip.erase(ip.begin() + 0);
   findSubset(ip, op1);
   findSubset(ip, op2);
}

int main() {
   string s;
   cin >> s;
   findSubset(s, " ");
}