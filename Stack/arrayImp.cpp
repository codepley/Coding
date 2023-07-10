#include <bits/stdc++.h>
using namespace std;

class Stack {
   public:
   void push(int x){
      arr[topIndex] = x;
      topIndex++;
   }
   void pop(){
      if(topIndex == 0){
         cout << "Stack is empty" << endl;
      }else{
         topIndex--;
      }
   }
   int top() {
      return arr[topIndex-1];
   }
   int size() {
      return topIndex;
   }

   private:
   int arr[100];
   int topIndex = 0;
};

int main() {
   Stack s = Stack();
   s.push(4);
   s.push(15);
   // s.pop();
   cout << s.size() << endl;
}