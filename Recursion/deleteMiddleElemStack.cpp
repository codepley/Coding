#include<bits/stdc++.h>
using namespace std;

void solve(stack<int> &st, int k){
   if(k == 1){
      st.pop();
      return;
   }
   int val = st.top();
   st.pop();
   solve(st, k-1);
   st.push(val);
}

void print(stack<int> &st) {
   while(st.empty() == false){
      int p = st.top();
      cout << p << " ";
      st.pop();
   }
}

int main() {
   stack<int> st;
   int n; cin >> n;
   for(int i=0; i<n; i++){
      int k; cin >> k;
      st.push(k);
   }
   int k = n/2 + 1;
   // cout << k << endl;
   solve(st, k);

   print(st);
}