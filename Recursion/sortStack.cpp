#include<bits/stdc++.h>
using namespace std;

void insert(stack<int> &st, int elem) {
   if(st.empty() || st.top() <= elem){
      st.push(elem);
      return;
   }
   int val = st.top();
   st.pop();
   insert(st, elem);
   st.push(val);
}

void sort(stack<int> &st) {
   if(st.size() == 1){
      return;
   }
   int elem = st.top();
   st.pop();
   sort(st);
   insert(st, elem);
}

void print(stack<int> &st) {
   while(st.empty() == false){
      int p = st.top();
      cout << p << " ";
      st.pop();
   }
}

int main(){
   stack<int> st;
   st.push(7);
   st.push(4);
   st.push(9);
   st.push(5);

   cout << "initially \n";
   print(st);

   st.push(7);
   st.push(4);
   st.push(9);
   st.push(5);

   sort(st);
   cout << "\nfinally \n";
   print(st);

}