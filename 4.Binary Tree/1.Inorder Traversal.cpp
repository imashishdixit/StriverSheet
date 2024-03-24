#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<stack>
using namespace std;
/*
? Problem Statement : Given a Binary Tree. Find and print the inorder traversal of Binary Tree.

*/
struct node {
  int data;
  struct node * left, * right;
  node(int data){
    this->data=data;
    this->left = NULL;
    this->right=NULL;
  }
};



//! Iterative 
//! Time Complexity: O(N).

//! Reason: We are traversing N nodes and every node is visited exactly once.

//! Space Complexity: O(N)

//!Reason: In the worst case (a tree with just left children), the space complexity will be O(N).

vector < int > inOrderTrav(node * curr) {
  vector < int > inOrder;
  stack < node * > s;
  while (true) {
    if (curr != NULL) {
      s.push(curr);
      curr = curr -> left;
    } else {
      if (s.empty()) break;
      curr = s.top();
      inOrder.push_back(curr -> data);
      s.pop();
      curr = curr -> right;
    }
  }
  return inOrder;
}

//! Recursive
//!Time Complexity: O(N).

//? Reason: We are traversing N nodes and every node is visited exactly once.

//? Space Complexity: O(N)

// ? Reason: Space is needed for the recursion stack. In the worst case (skewed tree), space complexity can be O(N).
void inOrderTrav(node * curr, vector < int > & inOrder) {
  if (curr == NULL)
    return;

  inOrderTrav(curr -> left, inOrder);
  inOrder.push_back(curr -> data);
  inOrderTrav(curr -> right, inOrder);
}



int main(){

}