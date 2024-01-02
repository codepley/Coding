#include<bits/stdc++.h>
using namespace std;

bool cmp(const pair<char,int> &a,  const pair<char,int> &b){
   return a.second>b.second;
}

struct TreeNode {
   pair<char, int> val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(pair<char, int> x){
      val = x;
      left = NULL;
      right = NULL;
   }
};

void traverseTree(TreeNode* head){
   if(head == NULL) return;
   traverseTree(head->left);
   cout << head->val.first << " " << head->val.second << endl;
   traverseTree(head->right);
}

void printCode(TreeNode* root, string s){
   if(root==NULL) return;
   if(root->val.first != '$'){
      cout << root->val.first << " " << s << endl;
      return;
   }
   printCode(root->left, s+'0');
   printCode(root->right, s+'1');
}

int main() {
   vector<pair<char, int>> code = {{'a',10}, {'d',50}, {'b',20}, {'e',40}, {'f',80} };
   sort(code.begin(), code.end(), cmp);
   int maxSum = 0;
   for(auto u: code){
      maxSum += u.second;
   }
   TreeNode* head = new TreeNode({'$',maxSum});
   TreeNode* temp = head;
   for(int u=0; u<code.size()-2; u++){
      maxSum = maxSum - code[u].second;
      if(code[u].second < maxSum){
         temp->left = new TreeNode(code[u]);
         temp->right = new TreeNode({'$',maxSum});
         temp = temp->right;
      }else{
         temp->right = new TreeNode(code[u]);
         temp->left = new TreeNode({'$',maxSum});
         temp = temp->left;
      }
   }

   temp->left = new TreeNode(code[code.size()-1]);
   temp->right = new TreeNode(code[code.size()-2]);
   temp = temp->left;
   cout << "++++++++++++++++++++++++++" << endl;
   printCode(head, "");
   
}