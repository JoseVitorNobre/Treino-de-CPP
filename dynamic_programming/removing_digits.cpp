#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  int cosciente = 0;
  while(n > 0){
    int n1 = n;
    int c = 0;
    while(n1 > 0){
      c = max(c, n1 % 10);
      n1 /= 10; 
    }
    n -= c;
    cosciente++;
  }
  cout << cosciente;
}