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

int getHeight(TreeNode *root) {
   if(root==NULL) return 0;
   return 1+max(getHeight(root->left), getHeight(root->right));
}

// O(n) solution
int checkBalancedTwo(TreeNode *root){
   if(root==NULL) return 0;
   int lh = checkBalancedTwo(root->left);
   if(lh==-1) return -1;
   int rh = checkBalancedTwo(root->right);
   if(rh==-1) return -1;
   if(abs(lh-rh)>1) return -1;
   return max(lh, rh)+1;
}

bool checkBalanced(TreeNode *root){
   if(root==NULL) return true;
   int leftHeight = getHeight(root->left);
   int rightHeight = getHeight(root->right);
   if(abs(leftHeight-rightHeight)>1) return false;
   if(checkBalanced(root->left) && checkBalanced(root->right) && abs(leftHeight-rightHeight) <= 1){
      return true;
   }
   return false;
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

   bool ans = checkBalanced(root);
   if(ans){
      cout << "Balanced" << endl;
   }else{
      cout << "Not Balanced" << endl;
   }
   int ans2 = checkBalancedTwo(root);
   if(ans2 == -1){
      cout << "Not Balanced" << endl;
   }else{
      cout << "Balanced" << endl;
   }
}