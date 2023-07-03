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

void levelOrderLineTwo(TreeNode *root){
   if(root==NULL) return;
   queue<TreeNode*> q;
   q.push(root);
   while(!q.empty()){
      int count = q.size();
      for(int i=0; i<count; i++){
         TreeNode *curr = q.front();
         q.pop();
         cout << curr->val << " ";
         if(curr->left) q.push(curr->left);
         if(curr->right) q.push(curr->right);
      }
      cout << endl;
   }
}

void levelOrderLine(TreeNode *root) {
   if(root == NULL) return; 
   queue<TreeNode*> q;
   q.push(root);
   q.push(NULL);
   while(q.size() > 1){
      TreeNode *p = q.front();
      q.pop();
      if(p!=NULL){
         cout << p->val << " ";
         if(p->left != NULL) q.push(p->left);
         if(p->right != NULL) q.push(p->right);  
      }else{
         q.push(NULL);
         cout << endl;
         continue;
      }
      
   }
}

void levelOrder(TreeNode *root) {
   if(root == NULL) return; 
   queue<TreeNode*> q;
   q.push(root);
   while(!q.empty()){
      TreeNode *p = q.front();
      q.pop();
      cout << p->val << " ";
      if(p->left != NULL) q.push(p->left);
      if(p->right != NULL) q.push(p->right);
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

   levelOrder(root);
   cout << endl;
   // levelOrderLine(root);
   levelOrderLineTwo(root);
}