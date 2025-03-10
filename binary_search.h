#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

struct Node {
  Node* left = nullptr;
  Node* right = nullptr;
  int data;

  explicit Node(const int data) {
    this->data = data;
  }
};



class BinaryTree {
 public:
  BinaryTree(); 
  void insert(Node* &node, int data); //insert into binary tree
  void remove(); //remove from binary tree
  void sortNodes();
  void print(const Node* pos , int depth); //Prints out the binary tree
  bool hasNode(int data); //checks if the tree has a specific node

  ~BinaryTree();
private:
  Node* root = nullptr;

};

#endif
