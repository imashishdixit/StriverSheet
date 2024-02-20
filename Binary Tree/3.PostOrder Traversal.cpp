#include<bits/stdc++.h>
using namespace std;
/*
Problem Statement
*/

//! Recursive Approach
//Time Complexity: O(N).
//Reason: We are traversing N nodes and every node is visited exactly once.
//Space Complexity: O(N)
//Reason: Space is needed for the recursion stack. In the worst case (skewed tree), space complexity can be O(N).

void postOrder(TreeNode * root,vector<int> &res){
    if(root==NULL){
        return;
    }
    postOrder(root->left,res);
    postOrder(root->right,res);
    res.push_back(root->val);
    return;
}
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    postOrder(root,res);
    return res;
}

//! iterative Soluton
//!Time Complexity: O(N).
//!Space Complexity: O(N)

vector < int > postOrderTrav(node * cur) {
  vector < int > postOrder;
  if (cur == NULL) {
    return postOrder;
  }

  stack < node * > st;
  while (cur != NULL || !st.empty()) {

    if (cur != NULL) {
      st.push(cur);
      cur = cur -> left;
    } else {
      node * temp = st.top() -> right;
      if (temp == NULL) {
        temp = st.top();
        st.pop();
        postOrder.push_back(temp -> data);
        while (!st.empty() && temp == st.top() -> right) {
          temp = st.top();
          st.pop();
          postOrder.push_back(temp -> data);
        }
      } else cur = temp;
    }
  }
  return postOrder;
}

int main(){

}