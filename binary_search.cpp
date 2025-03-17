#include "binary_search.h"
#include <iostream>

BinaryTree::BinaryTree() = default;

//insert into binary tree
void BinaryTree::insert(Node* &node, Node* prev, const int data) {
  if (node == nullptr) {
    node = new Node(data); //this will be the base case of the recursion (will insert once the path has ended)
    node->parent = prev; //set parent node
    return;
  }
  
  /* Not needed
  //if number is already in the tree
  if (node->data == data) {
  std::cout << "Already in the tree" << std::endl;
  return;
  } */
  
  //if data being inserted is greater than node then go right
  if (node->data < data) {
    insert(node->right, node,  data);
  } else if (node->data > data) { //If data being inserted is less than node go left
    insert(node->left, node, data); 
    }
}

//Remove from binary tree
void BinaryTree::remove(Node* rem) {
  //If node to be removed has a null left is null swap with right. If there are no children it will just become nullptr (as right is a nullptr).
  if (rem->left == nullptr) {
    swapNodes(rem, rem->right);
  } else if (rem->right == nullptr) { //if the node to be removed only has a left child
    swapNodes(rem, rem->left);
  } else { //if two children 
    //Go to rem's successor, then go left all the way of the sucessor. Then swap the end of the left tree with rem, and delete the end node.
    Node* s = rem->right; //successor
    
    //Go down through the left path
    while (s->left != nullptr) {
      s = s->left;
    }
    //once the end of the path is hit.
    //swap the node data at the end of the path with the node to be removed.
    rem->data = s->data;
    remove(s); //basically calling remove again to call sortNodes(s, s->right), resulting in s becoming a nullptr.
  }
}

//used in the remove function for recursion. n1 is the node to be deleted, n2 is the node to be swapped
void BinaryTree::swapNodes(Node* n1, Node* n2) {
  //n1 is the root
  if (n1 == root) {
    root = n2; //root is now n2
    delete n1; //free up n1 memory
    return;
  }
  
  
  //Check if n1 is left of it's parent (then swap n2 with that)
  if (n1 == n1->parent->left) {
    n1->parent->left = n2; //swap with n2
  } else { //if it's the right of the parent
    n1->parent->right = n2; //swap n2 to the parent's right
  }
  delete n1; //free up n1 memory space
}

//Visualize the binary tree
void BinaryTree::print(const Node* pos , const int depth, bool isRight) {
  //Take top then right
  
  if (pos == nullptr) {
    return; //base case
  }


  //Take the right first
  print(pos->right, depth + 1, true);
  
  //put spaces for the depth (more depth = more spaces)
  for (int i = 0; i < depth; i++) {
    std::cout << "    ";
  }
 
  
  //Print a Γ for a right node and L for a left node (helps show the connections of the tree better)
  if (depth > 0 ) {
    std::cout << (isRight ? "Γ" : "L") << " ";
  }
  std::cout << pos->data << std::endl; //then print out data

  print(pos->left, depth + 1, false); //print out left of tree

}

//Finds a node in the binary tree that correspondsd to data
Node* BinaryTree::getNode(Node* node, int data) {
  //Base case: if node is null (end of tree)
  if (node == nullptr) {
    //return false;
    return nullptr;
  }
  //Base case: if we find the data
  if (node->data == data) {
    //return true;
    return node;
  }
  //If data is less than the node pos we are at: go left.
  if (data < node->data) {
    return getNode(node->left, data); //return value if it's found in left tree
  } else { //If data is more than the node pos: go right.
    return getNode(node->right, data); //return value if found in right tree
  }
}


BinaryTree::~BinaryTree() {
  delete root;
}
