#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n = 153;
  int dup = n;
  int sum = 0;
  while (n != 0)
  {
    int lastDigit = n % 10;
    sum += pow(lastDigit, 3);
    n = n / 10;
  }
  if (sum == dup)
  {
    cout << "Armstrong Number";
  }
  else
  {
    cout << "Not Armstrong Number";
  }

  return 0;
}