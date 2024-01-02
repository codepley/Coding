#include<bits/stdc++.h>
using namespace std;

void insert(vector<int> &v, int elem) {
   if(v.size()==0 || v[v.size()-1] <= elem){
      v.push_back(elem);
      return;
   }
   int val = v[v.size()-1];
   v.pop_back();
   insert(v, elem);
   v.push_back(val);
}

void sort(vector<int> &v){
   if(v.size()==1){
      return;
   }
   int elem = v[v.size() - 1];
   v.pop_back();
   sort(v);
   insert(v, elem);
}

int main() {
   vector<int> arr = {9, 4, 12, 8, 4, 3, 7};
   sort(arr);
   for(auto u: arr){
      cout << u << " ";
   }
}