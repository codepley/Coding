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

int main() {
   TreeNode *root = new TreeNode(10);
   root->left = new TreeNode(5);
   root->right = new TreeNode(15);
   root->left->left = new TreeNode(3);
}