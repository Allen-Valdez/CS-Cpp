#include <iostream>
using namespace std;

void reverseString(string s) {
  int length = s.size();
  if (length > 0)
  {
    cout << s[length - 1];
    reverseString(s.substr(0, length - 1));
  }
}

int main() {
  reverseString("Hello!");
}