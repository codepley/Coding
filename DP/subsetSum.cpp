#include<bits/stdc++.h>
using namespace std;

bool solve(vector<int> arr1, int sum, int n){
   if(sum == 0) return 1;
   if(n==0) return 0;
   if(sum < 0) return 0;

   return solve(arr1, sum-arr1[n-1], n-1) || solve(arr1, sum, n-1);
}

int main() {
   vector<int> arr1 = {3,34,4,12,5,2};
   int sum = 59;

   int n = arr1.size();

   cout << solve(arr1, sum, n) << endl;
}