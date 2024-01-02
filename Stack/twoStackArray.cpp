#include <bits/stdc++.h>
using namespace std;

class TwoStack {
   int *arr;
   int cap, top1, top2; 
   public:
   TwoStack(int n){
      cap = n;
      top1 = -1;
      top2 = n;
      arr = new int[cap];
   }

   bool push1(int n){
      if(top1 < top2-1){
         top1++;
         arr[top1] = n;
         return true;
      }
      return false;
   }
   bool push2(int n){
      if(top1 < top2-1){
         top2--;
         arr[top2] = n;
         return true;
      }
      return false;
   }
   int peek1() {
      if(top1==-1){
         cout << "No item in stack 1" << endl;
         return -1;
      }
      return arr[top1];
   }
   int peek2() {
      if(top2==cap){
         cout << "No item in stack 2" << endl;
         return -1;
      }
      return arr[top2];
   }
   bool pop1(){
      if(top1==-1){
         cout << "Nothing to pop from stack 1" << endl;
         return -1;
      }
      top1--;
      return true;
   }
   bool pop2(){
      if(top2==cap){
         cout << "Nothing to pop from stack 2" << endl;
         return -1;
      }
      top2++;
      return true;
   }
   int size1() {
      return top1+1;
   }
   int size2() {
      return cap-top2;
   }
};

int main() {
   TwoStack st = TwoStack(10);
   st.push1(24);
   st.push1(25);
   st.push1(26);
   st.push2(43);
   st.push2(42);
   st.push2(41);
   st.pop1();
   st.pop2();
   cout << st.peek1() << " " << st.peek2() << endl;
   cout << st.size1() << " " << st.size2() << endl;
   return 0;
}