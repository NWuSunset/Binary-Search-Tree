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
  void sortNodes(Node* n1, Node* n2);
  void print(const Node* pos, const int depth = 0); //Prints out the binary tree (depth starts at 0)
  bool hasNode(Node* node, int data); //checks if the tree has a specific node
  
  ~BinaryTree();

  Node* root = nullptr;
  

};

#endif
