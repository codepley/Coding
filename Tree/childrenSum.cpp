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

bool childrenSum(TreeNode *root) {
   if(root == NULL) return true;
   if(root->left == NULL && root->right == NULL) return true;
   int sum = 0;
   if(root->left != NULL) sum += root->left->val;
   if(root->right != NULL) sum += root->left->val;
   return (childrenSum(root->left) && childrenSum(root->right) && (sum == root->val));
}

int main() {
   TreeNode *root = new TreeNode(20);
   // root->left = new TreeNode(8);
   // root->right = new TreeNode(12);
   // root->left->left = new TreeNode(3);
   // root->left->right = new TreeNode(5);

   root->left = new TreeNode(20);
   

   if(childrenSum(root)){
      cout << "Yes, children sum property is followed" << endl;
   }else{
      cout << "No, children sum property is not followed" << endl;
   }
}