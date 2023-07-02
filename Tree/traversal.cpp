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

void inorder(TreeNode *root) {
   if(root==NULL){
      return;
   }
   inorder(root->left);
   cout << root->val << " ";
   inorder(root->right);
}

void preorder(TreeNode *root) {
   if(root == NULL) return;
   cout << root->val << " ";
   preorder(root->left);
   preorder(root->right);
}

void postorder(TreeNode *root) {
   if(root == NULL) return;
   postorder(root->left);
   postorder(root->right);
   cout << root->val << " ";
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

   cout << "\nThe Inorder Traversal of the Tree" << endl;
   inorder(root);

   cout << "\nThe Preorder Traversal of the Tree" << endl;
   preorder(root);

   cout << "\nThe Postorder Traversal of the Tree" << endl;
   postorder(root);
}