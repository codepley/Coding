// print lcs

#include<bits/stdc++.h>
using namespace std;

int main() {
   string s1, s2;
   cin >> s1 >> s2;
   int n = s1.length(), m = s2.length();
   vector<vector<int>> dp(n+1, vector<int> (m, 0));
   
   for(int i=1; i<=n; i++){
      for(int j=1; j<=m; j++){
         if(s1[i-1] == s2[j-1]){
            dp[i][j] = 1+dp[i-1][j-1];
         }else{
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
         }
      }
   }

   int i=n, j=m;
   string ans = "";
   while(i>0 && j>0){
      if(s1[i-1] == s2[j-1]){
         ans.push_back(s1[i-1]);
         i--; j--;
      }else{
         if(dp[i][j-1] < dp[i-1][j]){
            i--;
         }else{
            j--;
         }
      }
   }
   for(int i=0; i<=n; i++){
      for(int j=0; j<=m; j++){
         cout << dp[i][j] << " ";
      }cout << endl;
   }
   reverse(ans.begin(), ans.end());
   cout << ans << endl; 
}