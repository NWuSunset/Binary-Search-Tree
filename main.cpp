#include <iostream>

using namespace std;
int main() {
  char arr[40][40]{};

  arr[0][0] = 'c';
  
  for (int i = 0; i < 40; i++) {
    cout << arr[i] << endl;
    
  }

  
  return 0;
}
