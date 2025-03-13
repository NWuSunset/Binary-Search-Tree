#include <iostream>
#include <fstream>
#include <sstream>
#include "binary_search.h"

using namespace std;

void fromFile();
void fromConsole();

int main() {
/*
  char arr[40][40]{};

  arr[0][0] = 'c';
  
  for (int i = 0; i < 40; i++) {
    cout << arr[i] << endl;
  } */

  BinaryTree * bst = new BinaryTree();

  
  bst->insert(bst->root, nullptr, 5);
  bst->print(bst->root);
  bool test = bst->hasNode(bst->root, 5);
  cout << test << endl; 
  
  cout << "Hello World" << endl;  
  return 0;
}


//taking numbers from a file separated by spaces
void fromFile(BinaryTree* bst) {
  string filePath;
  cout << "Enter the path of the file you want to read from. Or type the filename if it's in the local directory" << endl;
  getline(cin, filePath);

  ifstream inputFile(filePath);

  if (inputFile.is_open()) {
    int num;
    cout << "Inserting numbers into the tree..." << endl;
    cout << "Adding numbers from file" << endl;
    while (inputFile >> num) {
      bst->insert(bst->root, nullptr, num);
    }
    inputFile.close();
  } else {
    cout << "Cannot find file specified" << endl;
  }
}


void fromConsole(BinaryTree * bst) {
  string input;
  cout << "Enter numbers separated by spaces: " << endl;
  getline(cin, input);

  istringstream iss(input);
  //object to stream the string into different variables (since we input ints separated by spaces)
  int num;

  cout << "Inserting numbers into the heap..." << endl;
  //Stream a number till while space is encountered. Do this until end of string is hit
  while (iss >> num) {
    bst->insert(bst->root, nullptr, num);
  }
}
