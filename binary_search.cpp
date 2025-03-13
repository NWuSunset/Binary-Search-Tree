#include "binary_search.h"
#include <iostream>

BinaryTree::BinaryTree() = default;

//insert into binary tree
void BinaryTree::insert(Node* &node, Node* prev, const int data) {
    if (node == nullptr) {
        node = new Node(data); //this will be the base case of the recursion (will insert once the path has ended)
	node->parent = prev;
	return;
    }
    
    //if number is already in the tree
    if (node->data == data) {
      std::cout << "Already in the tree" << std::endl;
      return;
    }
    
    //if greater than node then go right
    if (node->data < data) {
      insert(node->right, node,  data); //now go down the right branch
    } else if (node->data > data) {
      insert(node->left, prev, data); //go down left path is passed in is less than node
    }
}

void BinaryTree::remove(Node* rem) {
  //If left is null swap with right. (if there are no children it will just become a nullptr)
  if (rem->left == nullptr) {
    swapNodes(rem, rem->right); //sort using right node
  } else if (rem->right == nullptr) { //if only has left child
    swapNodes(rem, rem->left);
  } else { //if two children 
    //Go to rem's successor, then go left all the way of the sucessor. Then swap the end of the left tree with rem, and delete the end node
    Node* s = rem->right; //successor

    //Go down through the left path
    while (s->left != nullptr) {
      s = s->left;
    }
    //one last left is hit
    //swap their numbers
    rem->data = s->data;
    remove(s); //basically calling remove again to call sortNodes(s, s->right).
  }
}

//used in the remove function for recursion. n1 is the node to be deleted, n2 is the node to be swapped
void BinaryTree::swapNodes(Node* n1, Node* n2) {

  //n1 is the root
  if (n1 == root) {
    root = n2; //root is now n2 
  }

  
  //Check if n1 is left of it's parent (then sawp n2 with that)
  if (n1 == n1->parent->left) {
    n1->parent->left = n2; //swap with n2
  } else {
    n1->parent->right = n2; //if it's right: swap with parent right
  }

  //If n2 != nullptr
  // n2's parent = n1's parent
  //Swapping n1 with it's parent
}

//Visualize the binary tree
void BinaryTree::print(const Node* pos , const int depth) {
    //Take top then right

    if (pos == nullptr) {
        return; //base case
    }

    //Take the right first
    print(pos->right, depth + 1);

    //put spaces for the depth (more depth = more spaces)
    for (int i = 0; i < depth; i++) {
        std::cout << "    ";
    }
    std::cout << pos->data << std::endl; //then print out data

    print(pos->left, depth + 1); //print out left of tree
}

bool BinaryTree::hasNode(Node* node, int data) {
    //Base case: if node is null (end of tree)
    if (node == nullptr) {
        return false;
    }
    //Base case: if we find the data
    if (node->data == data) {
        return true;
    }
    //If data is less go left.
    if (data < node->data) {
        hasNode(node->left, data);
    } else {
        hasNode(node->right, data);
    }
    return false;
}


BinaryTree::~BinaryTree() {
    delete root;
}
