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

void findDistance(TreeNode *root, int k){
   if(root == NULL) return;
   if(k==0) cout << root->val << " ";
   else{
      findDistance(root->left, k-1);
      findDistance(root->right, k-1);
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

   findDistance(root, 2);
   return 0;
}