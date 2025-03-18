#include <bits/stdc++.h>
using namespace std;

int main()
{
  int num = 12321;
  int dup = num;
  int reverse = 0;
  while (num != 0)
  {
    int lastDigit = num % 10;
    reverse = reverse * 10 + lastDigit;
    num = num / 10;
  }
  cout << reverse << endl;
  cout << dup << endl;
  cout << num << endl;
  if (reverse == dup)
  {
    cout << "Palindrome";
  }
  else
  {
    cout << "Not Palindrome";
  }

  return 0;
}