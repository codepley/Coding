#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x){
      val = x;
      left = NULL;
      right = NULL;
   }
};

int maxLevel = 0;
void leftView(TreeNode *root, int l) {
   if(root==NULL) return;

   if(maxLevel < l){
      maxLevel = l;
      cout << root->val << " ";
   }
   leftView(root->left, l+1);
   leftView(root->right, l+1);
}

void leftViewIterative(TreeNode *root) {
   if(root == NULL) return;
   queue<TreeNode*> q;
   q.push(root);
   while(!q.empty()) {
      int sz = q.size();
      for(int i=0; i<sz; i++){
         TreeNode *curr = q.front();
         q.pop();
         if(i==0) cout << curr->val << " ";
         if(curr->left) q.push(curr->left);
         if(curr->right) q.push(curr->right);
      }
   }
}

int main() {
   TreeNode *root = new TreeNode(10);
   root->left = new TreeNode(20);
   root->right = new TreeNode(30);
   root->left->left = new TreeNode(40);
   root->left->right = new TreeNode(50);
   root->left->right->left = new TreeNode(70);
   root->left->right->right = new TreeNode(80);
   root->right->right = new TreeNode(60);

   leftView(root, 1);
   cout << endl;
   leftViewIterative(root);
}