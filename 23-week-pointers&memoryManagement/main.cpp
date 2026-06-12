#include <iostream>
#include <vector>
using namespace std;

void f(int &x){
  x++;
}

void I(){
  int x  = 10;
  f(x);
  cout << x << endl;
}

void K(){
  int x = 10;
  int &y = x;
  y++;
  x *= 10;

  cout << x << endl;
  cout << y << endl;
}


void a(){
  int x = 10;

  cout << x << endl;
  cout << &x << endl;

  int &y = x; // same address of x, because they are referencing the same variable
  cout << y << endl;
  cout << &y << endl;

}

void size(){
  int a = 10; // 4 bytes
  char b = 'x'; // 1 bytes
  long long c = 13414132413248912234; // 8 bytes

  cout << sizeof(a) << endl;
  cout << sizeof(b) << endl;
  cout << sizeof(c) << endl;
}


int main(){
// I();
// K();
// a();
size();
}