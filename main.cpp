#include <iostream>
#include <fstream>
#include <sstream>


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

  
  return 0;
}


void fromFile(Heap* heap) {
  string file;
  cout << "Enter the name of the file you want to read from" << endl;
  getline(cin, file);

  ifstream numFile(file);

  if (numFile.is_open()) {
    int num;
    cout << "Inserting numbers into the heap..." << endl;
    cout << "Adding numbers from file" << endl;
    while (numFile >> num) {
      heap->insertNode(num, heap->heapSize);
    }
    numFile.close();
  } else {
    cout << "Cannot find file specified" << endl;
  }
}


void fromConsole(Heap* heap) {
  string input;
  cout << "Enter numbers separated by spaces: " << endl;
  getline(cin, input);

  istringstream iss(input);
  //object to stream the string into different variables (since we input ints separated by spaces)
  int num;

  cout << "Inserting numbers into the heap..." << endl;
  //Stream a number till while space is encountered. Do this until end of string is hit
  while (iss >> num) {
    heap->insertNode(num, heap->heapSize); //add num to heap
  }
}
