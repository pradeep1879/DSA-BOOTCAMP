#include <iostream>
using namespace std;

void charToAscii(){
  char ch = 'a';
  cout << ch << ":" << (int)ch << endl;

  char chA = 'A';
  cout << chA << ":" << (int)chA << endl;

  char ch0 = '0';
  cout << ch0 << ":" << (int)ch0;

}

int main(){
  charToAscii();
}