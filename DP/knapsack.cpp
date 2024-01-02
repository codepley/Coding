#include<bits/stdc++.h>
using namespace std;

int knapsack(vector<int> wt, vector<int> val, int W, int n, int (&dp)[1002][1002]) {
   // base condition
   if(n == 0 || W == 0){
      return dp[n][W] = 0;
   }

   if(dp[n][W] != -1){
      return dp[n][W];
   }

   if(wt[n-1] < W){
      return dp[n][W] = max(val[n-1] + knapsack(wt, val, W-wt[n-1], n-1, dp), knapsack(wt, val, W, n-1, dp));
   }else{
      return dp[n][W] = knapsack(wt, val, W, n-1, dp);
   }
}

int topDownKnapsack(vector<int> wt, vector<int> val, int W, int n) {
   vector<vector<int>> dp(n+1, vector<int> (W+1, 0));
   for(int i=1; i<=n; i++){
      for(int j=1; j<=W; j++){
         if(wt[i-1] < j){
            dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]], dp[i-1][j]);
         }else{
            dp[i][j] = dp[i-1][j];
         }
      }
   }
   return dp[n][W];
}

int main() {
   int dp[1002][1002];
   memset(dp, -1, sizeof(dp));
   vector<int> wt = {95,4,60,32,23,72,80,62,65,46};
   vector<int> val = {55,10,47,5,4,50,8,61,85,87};
   // vector<int> wt = {5,4,6,3};
   // vector<int> val = {10,40,30,50};
   int W = 269;
   cout << knapsack(wt, val, W, 10, dp) << endl;
   cout << topDownKnapsack(wt, val, W, 10) << endl;
}