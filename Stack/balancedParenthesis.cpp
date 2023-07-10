#include <bits/stdc++.h>
using namespace std;

int main() {
   string s;
   cin >> s;
   stack<char> st;
   for(int i=0; i<s.length(); i++){
      if(s[i]=='(' || s[i]=='[' || s[i] == '{'){
         st.push(s[i]);
      }else{
         if((s[i]==')' && st.top()=='(') || (s[i]==']' && st.top()=='[') || (s[i]=='}' && st.top()=='{')){
            st.pop();
         }
      }
   }
   if(st.empty()) {
      cout << "Balanced" << endl;
   }else{
      cout << "Not Balanced" << endl;
   }
}