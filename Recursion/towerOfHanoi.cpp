#include<bits/stdc++.h>
using namespace std;

void toh(char s, char h, char d, int n, int &count){
   count++;
   if(n==1){
      cout << "Move disk " << n << " from " << s << " to " << d << endl;
      return;
   }
   toh(s, d, h, n-1, count);
   cout << "Move disk " << n << " from " << s << " to " << d << endl;
   toh(h, s, d, n-1, count);
   return;
}

int main() {
   int n; cin >> n;
   int count = 0;
   toh('A','B','C', n, count);
   cout << "Total count = " << count << endl;
}