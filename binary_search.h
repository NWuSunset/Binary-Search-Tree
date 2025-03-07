

struct Node {
  Node* left = nullptr;
  Node* right = nullptr;
  int data;
};



class BinaryTree {
 public:
  BinaryTree(); 
  void insert(); //insert into binary tree
  void remove(); //remove from binary tree 
  void print(); //Prints out the binary tree
  bool hasNode(int data); //checks if the tree has a specific node

  ~BinaryTree();
private:
  Node* root = nullptr;

};
