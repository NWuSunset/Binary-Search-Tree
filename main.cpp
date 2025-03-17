#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <limits>
#include "binary_search.h"

using namespace std;
/*!
  @brief Handles user input
  @param bst       the binary search tree
  @returns         true if the user inputs the "quit" command
 */
bool userSelection(BinaryTree * bst);

/*!
  @brief Reads in numbers (separated by spaces) from a file and inserts them into binary tree
  @param bst       the binary search tree
  @note can take in a file path or the name of a file in the local directory e.g. "C:\Users\476275\Downloads\numbers.txt", numbers.txt (if file is in the local program directory).
 */
void fromFile(BinaryTree * bst);

/*!
  @brief Reads in numbers (separated by spaces) from the console and inserts them into binary tree
  @param bst       the binary search tree
 */

void fromConsole(BinaryTree * bst);

int main() {
  BinaryTree * bst = new BinaryTree();

  while (!userSelection(bst)) {}
  
  return 0;
}

bool userSelection(BinaryTree* bst) {
  char userInput[12];
  cout << "Type CONSOLE to enter a series of numbers in the console. Or type FILE to enter a file name. Type PRINT to print out the tree. Type 'remove' to remove a number from the tree" << endl;
  cin.getline(userInput, 12);
  
  //in case more than 12 characters are entered (so it won't break the program)
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
    if (bst->root == nullptr) cout << "Nothing in the tree" << endl;
    bst->print(bst->root);
  } else if (strcasecmp(userInput, "Remove") == 0) {
    int num;
    cout << "What number do you want to remove from the tree?" << endl;
    cin >> num;

    //get the node that matches user input
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

  // Check if the filePath starts and ends with a double quote, and remove them if so.
  if (filePath.size() >= 2 && filePath.front() == '"' && filePath.back() == '"') {
    filePath = filePath.substr (1, filePath.size() - 2); //makes a substring that doesn't include the double quote
  }
  
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
