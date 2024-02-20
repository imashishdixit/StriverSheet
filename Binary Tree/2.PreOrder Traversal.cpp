#include<bits/stdc++.h>
using namespace std;
struct node {
  int data;
  struct node * left, * right;
};

/*
? Problem Statement: Given a binary tree print the preorder traversal of binary tree.

*/
//! Recursive solution
/*
*Time Complexity: O(N).
*Reason: We are traversing N nodes and every node is visited exactly once.
*/

/*
*Space Complexity: O(N)
*Reason: Space is needed for the recursion stack. In the worst case (skewed tree), space complexity can be O(N).
*/
void preOrder(TreeNode * root,vector<int>& res){
    if(!root){
        return;
    }
    res.push_back(root->val);
    preOrder(root->left,res);
    preOrder(root->right,res);
    return;
}
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    preOrder(root,res);
    return res;
}

//* Iterative Approach
//*Time Complexity: O(N).
//*Reason: We are traversing N nodes and every node is visited exactly once.
//*Space Complexity: O(N)
//*Reason: In the worst case, (a tree with every node having a single right child and left-subtree, follow the video attached below to see the illustration), the space complexity can be considered as O(N).
vector < int > preOrderTrav(node * curr) {
  vector < int > preOrder;
  if (curr == NULL)
    return preOrder;
  
  stack < node * > s;
  s.push(curr);

  while (!s.empty()) {
    node * topNode = s.top();
    preOrder.push_back(topNode -> data);
    s.pop();
    if (topNode -> right != NULL)
      s.push(topNode -> right);
    if (topNode -> left != NULL)
      s.push(topNode -> left);
  }
 return preOrder;
}
  
