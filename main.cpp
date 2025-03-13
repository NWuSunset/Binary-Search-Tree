#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <limits>
#include "binary_search.h"

using namespace std;

bool userSelection(BinaryTree * bst);
void fromFile(BinaryTree * bst);
void fromConsole(BinaryTree * bst);

int main() {
/*
  char arr[40][40]{};

  arr[0][0] = 'c';
  
  for (int i = 0; i < 40; i++) {
    cout << arr[i] << endl;
  } */

  BinaryTree * bst = new BinaryTree();

  /*
  bst->insert(bst->root, nullptr, 5);
  bst->print(bst->root);
  bool test = bst->hasNode(bst->root, 5);
  cout << test << endl; 
  
  cout << "Hello World" << endl;  

  */

  while (!userSelection(bst)) {}
  
  return 0;
}

bool userSelection(BinaryTree* bst) {
  char userInput[12];
  cout << "Type CONSOLE to enter a series of numbers in the console. Or type FILE to enter a file name. Type PRINT to print out the tree. Type 'remove' to remove a number from the tree" << endl;
  cin.getline(userInput, 12);
  
  //in case more than 8 characters are entered (so it won't break the program)
  if (cin.fail()) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Input Error. Input is too long" << endl;
  }
  
  if (strcasecmp(userInput, "FILE") == 0) {
    fromFile(bst);
  } else if (strcasecmp(userInput, "CONSOLE") == 0) {
    fromConsole(bst);
  } else if (strcasecmp(userInput, "PRINT") == 0) {
    bst->print(bst->root);
  } else if (strcasecmp(userInput, "Remove") == 0) {
    int num;
    cout << "What number do you want to remove from the tree?" << endl;
    cin >> num;
    Node* n = bst->getNode(bst->root, num);
    if (n != nullptr) {
      bst->remove(n);
    } else {
    cout << "Invalid number" << endl;
    }
    cin.ignore();
  } else if (strcasecmp(userInput, "QUIT") == 0) {
    return true;
  } else {
    cout << "Invalid input." << endl;
  }
  return false;
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
