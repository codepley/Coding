#include<bits/stdc++.h>
using namespace std;

void insert(stack<int> &st, int elem){
   if(st.empty()){
      st.push(elem);
      return;
   }
   int val = st.top();
   st.pop();
   insert(st, elem);
   st.push(val);
}

void reverse(stack<int> &st) {
   if(st.size() == 1){
      return;
   }
   int elem = st.top();
   st.pop();
   reverse(st);
   insert(st, elem);
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
   st.push(1);
   st.push(2);
   st.push(3);
   st.push(4);
   st.push(5);

   reverse(st);
   print(st);
}