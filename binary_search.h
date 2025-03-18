#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

//found out how to label documentation

struct Node {
  Node* left = nullptr; ///< The left child
  Node* right = nullptr; ///< The right child
  Node* parent = nullptr; ///< Parent of node
  int data; ///< Data node contains

  /*!
      @brief Node constructor
      @param data the data the node will contain
   */
  explicit Node(const int data) {
    this->data = data;
  }
};



class BinaryTree {
 public:

  /*!
   * @brief tree constructor
   */
  BinaryTree();

    /*!
      @brief  Inserting data into the binary tree
      @param  node        Pos in the tree. Should be root node to start
      @param  prev        previous node, used in the function's recursion. Should be null to start
      @param  data        data to be inserted into the tree
    */
  void insert(Node* &node, Node* prev, int data); //insert into binary tree


  /*!
      @brief  removing data/node from binary tree
      @param  rem        node to remove.
    */
  void remove(Node* rem); //remove from binary tree

  /*!
      @brief  used in the remove function to swap a node with another
      @param  n1        node to be removed/swapped
      @param  n2        node to swap with
    */
  void swapNodes(Node* n1, Node* n2);

  /*!
      @brief  Used to visualize the tree to the console
      @param  pos       Position in the tree. Should be root to start
      @param  depth     Depth of the tree. Should be 0 to start
    */
  void print(const Node* pos, int depth = 0); //Prints out the binary tree (depth starts at 0)

  /*!
        @brief  Used to visualize the tree to the console
        @param  node     position in the tree. Should be root to start
        @param  data     data to find
        @returns the Node* in the tree that contains the passed in data
        @returns nullptr if the data could not be found in the tree
      */
  void print(const Node* pos, const int depth = 0, bool isRight = false); //Prints out the binary tree (depth starts at 0)
  Node* getNode(Node* node, int data); //checks if the tree has a specific node

  /*!
   * @brief destructor
   */
  ~BinaryTree();

  Node* root = nullptr; ///< root of the binary tree
  
};

#endif
