#include "binary_search.h"
#include <iostream>

BinaryTree::BinaryTree() = default;

//insert into binary tree
void BinaryTree::insert(Node* &node, const int data) {
    if (node == nullptr) {
        node = new Node(data); //this will be the base case of the recursion (will insert once the path has ended)
        return;
    }

    //if number is already in the tree
    if (node->data == data) {
        return;
    }

    //if greater than node then go right
    if (node->data < data) {
        insert(node->right, data); //now go down the right branch
    } else if (node->data > data) {
        insert(node->left, data); //go down left path is passed in is less than node
    }
}

void BinaryTree::remove(Node* rem) {
    /*Cases to check for:
        children are null (no childreN)
        only one child
        with two children (complicated case)
        */

  if (rem->left == nullptr && rem->right == nullptr) {
    //we can just delete the thing
  }
  
  if (rem->left == nullptr) {
    sortNodes(rem, rem->right); //sort using right node
  } else if (rem->right == nullptr) {
    sortNode(rem, rem->left);
  } else { //if two children or no children
    
    
  }

}

//used in the remove function for recursion
void BinaryTree::sortNodes(Node* n1, Node* n2) {

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
