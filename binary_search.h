#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

struct Node {
  Node* left = nullptr;
  Node* right = nullptr;
  Node* parent = nullptr;
  int data;

  explicit Node(const int data) {
    this->data = data;
  }
};



class BinaryTree {
 public:
  
  BinaryTree();

  /*
    insert Args:

    node - Node to start on
    prev
    data
   */
  
  void insert(Node* &node, Node* prev, const int data); //insert into binary tree


  /* remove args: rem - node to remove from the tree */
  void remove(Node* rem); //remove from binary tree
  void swapNodes(Node* n1, Node* n2);
  void print(const Node* pos, const int depth = 0); //Prints out the binary tree (depth starts at 0)
  Node* getNode(Node* node, int data); //checks if the tree has a specific node
  
  ~BinaryTree();

  Node* root = nullptr;
  

};

#endif
